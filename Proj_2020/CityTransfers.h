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

/**
 * @brief CityTransfers class, represents company information
 */
class CityTransfers {
public:

    /**
     * Vector of clients
     */
    vector<Person> clients;

    /**
     * Vector of carss
     */
    vector<Car> cars;

    /**
     * Graph wiht map nodes and edges
     */
    Graph* graph;

    /**
     * GraphViewr window
     */
    GraphViewer* gv;

    /**
     * ID of station of the map in graph
     */
    int stationID;

    /**
     * ID of graph in map
     */
    int currentGraph;

    /**
     * @brief constructs a new CityTransfers object
     */
    CityTransfers();

    /**
     * @brief latest calculated
     */
    Path path;

    /**
     * Vector with timewaited by clientes in latest route, ordered by drop off
     */
    vector<int> waitedTime;
};


#endif //PROJ_2020_CITYTRANSFERS_H
