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
 * @param graph raph
 * @param IDS Clients nod destination IDs
 */
void paintClients(GraphViewer* gv, const Graph* graph, const vector<int>& IDS);

#endif //PROJ_2020_USERINTERFACE_H
