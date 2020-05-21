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


vector<Edge*> Vertex::getAdj() const{
    return this->adj;
}

Vertex *Vertex::getPath() const{
    return this->path;
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
    return nullptr;
}

bool Graph::addVertex(int ID, double x, double y){
    if(findVertex(ID) != nullptr) return false;

    vertexSet.push_back(new Vertex(ID, x, y));
    return true;
}

bool Graph::addEdge(int edgeID, int srcID, int destID, double weight){
     auto v1 = findVertex(srcID);
     auto v2 = findVertex(destID);

     if(v1 == nullptr || v2 == nullptr) return false;

     v1->addEdge(edgeID, v2, weight);
     return true;
}

int Graph::getNumVertex() const{
    return vertexSet.size();
}

vector<Vertex *> Graph::getVertexSet() const{
    return vertexSet;
}

/*****  ALGORITHMS   *****/

void Graph::dijkstraShortestPath(int srcID){
    auto s = findVertex(srcID);

    for(auto v : vertexSet){
        v->dist = INF;
        v->path = nullptr;
    }

    s->dist = 0;
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    while(!q.empty()){
        auto v = q.extractMin();
        for(auto e : v->adj) {
            if (e->dest->dist > v->dist + e->weight){
                double oldDist = e->dest->dist;
                e->dest->dist = v->dist + e->weight;
                e->dest->path = v;
                if (oldDist == INF)
                    q.insert(e->dest);
                else
                    q.decreaseKey(e->dest);
            }
        }
    }
}