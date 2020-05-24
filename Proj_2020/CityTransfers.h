#ifndef PROJ_2020_CITYTRANSFERS_H
#define PROJ_2020_CITYTRANSFERS_H

#include <vector>

#include "Car.h"
#include "Person.h"
#include "Graph.h"
#include "BuildGraph.h"
#include "GraphViewer/graphviewer.h"
#include "UserInterface.h"
#include "Path.h"

using namespace std;

class CityTransfers {
public:
    vector<Person> clients;
    vector<Car> cars;
    Graph* graph;
    GraphViewer* gv;
    int stationID;
    CityTransfers();

    //latest path calculated
    Path path;
    //timewaited by clients, ordered as vector clients
    vector<int> waitedTime;
};


#endif //PROJ_2020_CITYTRANSFERS_H
