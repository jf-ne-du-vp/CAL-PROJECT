#include "BuildGraph.h"



Graph* buildGraph(string nodePath, string edgePath){
    Graph* graph = new Graph;
    string line;

    ifstream nodes;
    nodes.open(nodePath);

    ifstream edges;
    edges.open(edgePath);

    if (nodes.fail()) {
        cout << "Couldn't open node file: " << nodePath << endl;
        return graph;
    }

    if (edges.fail()) {
        cout << "Couldn't open edge file: " << edgePath << endl;
        return graph;
    }

    //first vertexes
    getline(nodes, line);
    int numNodes = stoi(line);

    for(int i = 0; i < numNodes; i++){
        getline(nodes, line);
        istringstream iss(line);
        string midS;
        int ID;
        double x, y;
        /*
          for(size_t j = 0; j < line.size(); j++){
            if(line[i] == '(' || line [i] == ')' || line [i] == ',')
                line[i] = ' ';
        }

        stringstream ss(line);
        ss >> ID >> x >> y;
         */
        getline(iss, midS, '(');
        getline(iss, midS, ',');
        ID = stoi(midS);
        getline(iss, midS, ',');
        x = stod(midS);
        getline(iss, midS, ')');
        y = stod(midS);

        graph->addVertex(ID, x, y);
    }

    nodes.close();

    //now take care of edges
    getline(edges, line);
    int numEdges =  stoi(line);


    for(int i = 0; i< numEdges; i++){
        getline(edges, line);
        istringstream iss(line);
        string midS;
        int srcID, destID;
        /*
          for(size_t j = 0; j < line.size(); j++){
            if(line[i] == '(' || line [i] == ')' || line [i] == ',')
                line[i] = ' ';
        }

        stringstream ss(line);
        ss >> srcID >> destID;
         */
        getline(iss, midS, '(');
        getline(iss, midS, ',');
        srcID = stoi(midS);
        getline(iss, midS, ')');
        destID = stoi(midS);


        graph->addEdge(i, srcID, destID, euclidianDistance(graph->findVertex(srcID), graph->findVertex(destID)));
    }

    edges.close();

    return graph;
}


vector<Person> getClients(const string& clientsPath){
    vector<Person> res;
    ifstream stationID;
    stationID.open(clientsPath);

    if (stationID.fail()) {
        cout << "Couldn't open node file: " << clientsPath  << endl;
        return res;
    }



    stationID.close();
    return res;
}

vector<Car> getCars(const string& carsPath){
    vector<Car> res;
    ifstream cars;
    cars.open(carsPath);
    string line;

    if (cars.fail()) {
        cout << "Couldn't open cars file: " << carsPath  << endl;
        return res;
    }

    getline(cars, line);
    int numCars = stoi(line);

    for(int i = 0; i < numCars; i++){
        string midS;
        int ID;
        int seats;

        getline(cars, midS);
        ID = stoi(midS);
        getline(cars, midS);
        seats = stoi(midS);

        res.emplace_back(ID, seats);
    }

    cars.close();
    return  res;
}


int getStation(const string& clientsPath){
    ifstream stationID;
    stationID.open(clientsPath);

    if (stationID.fail()) {
        cout << "Couldn't open clients file: " << clientsPath  << endl;
        return 0;
    }

    int id;
    string info;
    getline(stationID, info);
    id = stoi(info);

    stationID.close();
    return id;
}


void saveCars(const string& carsPath, vector<Car> cars){
    ofstream car;
    car.open(carsPath);
    string line;

    if (car.fail()) {
        cout << "Couldn't open cars file: " << carsPath  << endl;
    }

    car << cars.size();

    for(int i = 0; i < cars.size(); i++){
        car << endl << cars[i].getID();
        car << endl << cars[i].getSeats();
    }


    car.close();
}


void saveClients(const string& clientsPath, vector<Person> clients){
    ofstream stationID;
    stationID.open(clientsPath);

    if (stationID.fail()) {
        cout << "Couldn't open clients file: " << clientsPath  << endl;
    }



    stationID.close();
}