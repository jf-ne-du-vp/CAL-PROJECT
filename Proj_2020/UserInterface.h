#ifndef PROJ_2020_USERINTERFACE_H
#define PROJ_2020_USERINTERFACE_H

#include "GraphViewer/graphviewer.h"
#include "Graph.h"

using namespace std;

/**
 * @brief Function to create graph based on graph
 * @param graph Graph to be draw
 * @return Graphviewer object
 */
GraphViewer* creategraphViewer(const Graph* graph);


/**
 * @brief Draw path in GraphViewer
 * @param gv Graphviewer object
 * @param path Vector with with sequence of vertexes to draw
 */
void showPathInGraph(GraphViewer* gv, const vector<Vertex*>& path);


/**
 * @brief To return graphviewer to initial state, all nodes yellow
 * @param gv
 * @param graph
 */
void resetGraph(GraphViewer* gv, const Graph* graph);


/**
 * @brief Paint clients destinations in black, used in to show in nearNeighbor
 * @param gv Graphviewer
 * @param graph Graph
 * @param IDS Clients nod destination IDs
 */
void paintClients(GraphViewer* gv, const Graph* graph, const vector<int>& IDS);


/**
 * @brief Nodes not accessible from station will by painted in blue, visited will be set false by dfs
 * Also writes to stdout how many nodes are non accessible from station node
 * @param gv Graphviewer
 * @param graph Graph
 */
void showNotVisitedDFS(GraphViewer* gv, const Graph* graph);

#endif //PROJ_2020_USERINTERFACE_H
