#ifndef PROJ_2020_BUILDGRAPH_H
#define PROJ_2020_BUILDGRAPH_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "Graph.h"

double euclidianDistance(Vertex* src, Vertex* dest);    //should i try other methods to calculate dist between vertexes?

Graph* buildGraph(string nodePath, string edgePath);


#endif //PROJ_2020_BUILDGRAPH_H
