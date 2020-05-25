#include "Graph.h"


/*********************   VERTEX   *********************/

void Vertex::addEdge(int ID, Vertex *dest, double w) {
    adj.push_back(new Edge(ID, dest, w));
}

Vertex::Vertex(int ID, double x, double y): ID(ID), x(x), y(y){}


int Vertex::getID() const{
    return this->ID;
}

double Vertex::getX() const{
    return this->x;
}

double Vertex::getY() const{
    return this->y;
}


double Vertex::getDist() const{
     return this->dist;
}

double Vertex::getDistASTAR() const{
    return this->distASTAR;
}

vector<Edge*> Vertex::getAdj() const{
    return this->adj;
}

Vertex *Vertex::getPath() const{
    return this->path;
}

void Vertex::setVisited(bool visited){
    this->visited = visited;
}

bool Vertex::getVisited() const{
    return this->visited;
}

void Vertex::setClientDest(bool dest){
    this->clientDest = dest;
}

bool Vertex::getClientDest() const{
    return this->clientDest;
}

bool Vertex::operator<(Vertex & vertex) const{
    return this->dist < vertex.dist;
}


/*********************   EDGE   *********************/


Edge::Edge(int ID, Vertex *dest, double weight): ID(ID), dest(dest), weight(weight){}

int Edge::getID() const{
    return this->ID;
}

double Edge::getWeight() const{
    return this->weight;
}

Vertex* Edge::getDest() const{
    return this->dest;
}


/*********************   GRAPH   *********************/


Vertex* Graph::findVertex(int ID) const{
    for(auto v : vertexSet){
        if(v->ID == ID) return v;
    }
    return NULL;
}

bool Graph::addVertex(int ID, double x, double y){
    if(findVertex(ID) != NULL) return false;

    vertexSet.push_back(new Vertex(ID, x, y));
    return true;
}

bool Graph::addEdge(int edgeID, int srcID, int destID, double weight){
     auto v1 = findVertex(srcID);
     auto v2 = findVertex(destID);

     if(v1 == NULL || v2 == NULL) return false;

     v1->addEdge(edgeID, v2, weight);
     return true;
}

int Graph::getNumVertex() const{
    return vertexSet.size();
}

vector<Vertex *> Graph::getVertexSet() const{
    return vertexSet;
}


int Graph::findVertexIdx(Vertex* vertex) const{
    for(int i = 0; i < vertexSet.size(); i++){
        if(vertexSet[i]->ID == vertex->ID)
            return i;
    }

    return -1;
}

void Graph::setW(int i, int j, double weight){
    W.at(i).at(j) = weight;
}


double Graph::getW(int i, int j) const{
    return W.at(i).at(j);
}


void Graph::setP(int i, int j, int index){
    P.at(i).at(j) = index;
}

//returns index of vertex
int Graph::getP(int i, int j) const{
    return P.at(i).at(j);
}


void Graph::resetMatrixW(int n) {
    W = vector<vector<double>> (n, vector<double> (n));
}


void Graph::resetMatrixP(int n) {
    P = vector<vector<int>> (n, vector<int> (n));
}


double Graph::edgeWeight(int i, int j) const{
    if(i == j) return 0;

    for(auto edge : vertexSet.at(i)->getAdj()){
        if(edge->dest == vertexSet.at(j))
            return edge->getWeight();
    }

    return INF;
}


int Graph::nextVertex(int i, int j) const{
    for(auto edge : vertexSet.at(i)->getAdj()){
        if(edge->dest == vertexSet.at(j))
            return j;
    }

    return -1;
}

double Graph::getnearDist() const{
    return this->nearDist;
}


void Graph::setnearDist(double nearDist){
    this->nearDist = nearDist;
}


/*****  ALGORITHMS   *****/


/*****  Dijkstra   *****/

void Graph::dijkstraShortestPath(int srcID){
    auto s = findVertex(srcID);

    for(auto v : vertexSet){
        v->dist = INF;
        v->path = NULL;
        v->queueIndex = 0;
    }

    s->dist = 0;
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    while(!q.empty()){
        auto v = q.extractMin();
        for(auto e : v->adj) {
            double dJ = v->dist + e->weight;
            if (e->dest->dist > dJ){
                double oldDist = e->dest->dist;
                e->dest->dist = dJ;
                e->dest->path = v;
                if (oldDist == INF)
                    q.insert(e->dest);
                else
                    q.decreaseKey(e->dest);
            }
        }
    }
}


vector<Vertex *> Graph::getPath(const int &origin, const int &dest) const{
    vector<Vertex *> res;
    auto v = findVertex(dest);
    if (v == nullptr || v->dist == INF) // missing or disconnected
        return res;

    for ( ; v != nullptr; v = v->path)
        res.push_back(v);

    reverse(res.begin(), res.end());
    return res;
}

/*****  A-star   *****/

vector<Vertex *> Graph::aStar(const int &origin, const int &dest){
    auto src = findVertex(origin);
    auto final = findVertex(dest);

    for(auto v : vertexSet){
        v->dist = INF;
        v->path = NULL;
        v->queueIndex = 0;
        v->distASTAR = 0;
    }

    src->dist = 0;
    MutablePriorityQueue<Vertex> q;
    q.insert(src);

    while(!q.empty()){
        auto v = q.extractMin();

        if(v == final)
            break;

        for(auto e : v->adj) {
            double aS = v->getDist() - euclidianDistance(v, e->dest) + e->getWeight() + euclidianDistance(e->dest, final);
            if (e->dest->dist > aS){
                double oldDist = e->dest->dist;
                e->dest->dist = aS;
                e->dest->distASTAR =  v->distASTAR+ e->getWeight() ;
                e->dest->path = v;
                if (oldDist == INF)
                    q.insert(e->dest);
                else
                    q.decreaseKey(e->dest);
            }
        }
    }


    return getPath(origin, dest);
}


/*****  Floyd-Warshall   *****/


void Graph::floydWarshallShortestPath(){
    int n = getNumVertex();
    resetMatrixW(n);
    resetMatrixP(n);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            setW(i, j, edgeWeight(i, j));
            setW(j, i, edgeWeight(j, i));
            setP(i, j, nextVertex(i, j));
            setP(j, i, nextVertex(j, i));
        }
    }

    for(int k = 0; k < n; k++) {
        cout << "k do floyd: " << k << endl;
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n; i++) {
                if (j == k || i == k || i == j || getW(i, k) == INF || getW(k, j) == INF)
                    continue;
                double val = getW(i, k) + getW(k, j);
                if (val < getW(i, j)) {
                    setW(i, j, val);
                    setP(i, j, getP(i, k));
                }
            }
    }
}


vector<Vertex *> Graph::getfloydWarshallPath(const int &orig, const int &dest) const{
    vector<Vertex *> res;
    int v1 = findVertexIdx(findVertex(orig));
    int v2 = findVertexIdx(findVertex(dest));

    if(v1 == -1 || v2 == -1 || getW(v1,v2) == INF)
        return res;

    res.push_back(vertexSet[v1]);
    while(v1!=v2){
        v1 = getP(v1, v2);
        if(v1 < 0){
            break;
        }
        res.push_back(vertexSet[v1]);
    }

    //reverse(res.begin(), res.end());
    return res;

}


double Graph::getfloydWarshallWeight(const int &orig, const int &dest) const{
    double dist = 0;
    int v1 = findVertexIdx(findVertex(orig));
    int v2 = findVertexIdx(findVertex(dest));

    if(v1 == -1 || v2 == -1 || getW(v1,v2) == INF)
        return dist;

    dist += getW(v1,v2);
    while(v1!=v2){
        v1 = getP(v1, v2);
        if(v1 < 0){
            break;
        }
        dist += getW(v1,v2);
    }

    return dist;
}


/*****  DFS   *****/

void Graph::dfsVisit(Vertex* vertex){
    vertex->visited = true;
    for(auto it: vertex->getAdj()){
        if(!it->getDest()->visited)
            dfsVisit(it->getDest());
    }
}

void Graph::dfs(Vertex* src){
    for(auto it : vertexSet){
        it->visited = false;
    }

    dfsVisit(src);
}


bool Graph::dfsVisit(Vertex* vertex, Vertex* dest){
    vertex->visited = true;
    if(vertex == dest){
        return true;
    }
    for(auto it: vertex->getAdj()){
        if(!it->getDest()->visited)
            dfsVisit(it->getDest());
    }
    return false;
}

bool Graph::dfs(Vertex* src, Vertex* dest){
    for(auto it : vertexSet){
        it->visited = false;
    }

    return dfsVisit(src, dest);
}


/*****  Nearest Neighbour   *****/


int Graph::nearShortestDist(vector<int> destIDS){
    int minorDist = destIDS[0];
    for(auto d : destIDS){
        if(findVertex(d)->getDist() < findVertex(minorDist)->getDist()){
            minorDist = d;
        }
    }

    return minorDist;
}

vector<Vertex *> Graph::nearNeighborDij(vector<int> destIDS, int stationID){
    vector<Vertex*> res;
    vector<Vertex*> mid;
    int numDest = destIDS.size();
    int current = stationID;
    int middleID;

    for(int i = 0; i < numDest; i++) {
        dijkstraShortestPath(current);
        //int com id do mais proximo
        middleID = nearShortestDist(destIDS);
        //vetor com o menor percurso
        mid = getPath(current, middleID);
        //adicionar caminho de outro cliente
        res.insert(res.end(), mid.begin(), mid.end());
        //retirar do vetor de ids o calculado agora
        for(int j = 0; j < destIDS.size();j++){
            if(destIDS[j] == middleID){
                destIDS.erase(destIDS.begin() + j);
            }
        }
        //atualizar a distancia ja percorrida
        nearDist += findVertex(middleID)->getDist();
        //atualizar a partir do qual se vai procurar
        current = middleID;
    }

    dijkstraShortestPath(current);
    mid = getPath(current, stationID);
    res.insert(res.end(), mid.begin(), mid.end());
    nearDist += findVertex(stationID)->getDist();

    return res;
}



/*****  Calculate distances (heuristic)   *****/


double euclidianDistance(Vertex* src, Vertex* dest){
    return sqrt(pow(src->getX() - dest->getX(), 2) + pow(src->getY() - dest->getY(), 2));
}

double manhattanDistance(Vertex* src, Vertex* dest){
    return (abs(src->getX() - dest->getX()) + abs(src->getY() - dest->getY()));
}
