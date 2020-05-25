#ifndef PROJ_2020_USERINTERFACE_H
#define PROJ_2020_USERINTERFACE_H

#include "GraphViewer/graphviewer.h"
#include "Graph.h"

using namespace std;

GraphViewer* creategraphViewer(const Graph* graph);
void showPathInGraph(GraphViewer* gv, const vector<Vertex*>& path);
void resetGraph(GraphViewer* gv, const Graph* graph);
void paintClients(GraphViewer* gv, const Graph* graph, const vector<int>& IDS);

#endif //PROJ_2020_USERINTERFACE_H
