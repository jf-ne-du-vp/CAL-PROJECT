#include <iostream>


#include "Car.h"
#include "Person.h"
#include "Graph.h"
#include "BuildGraph.h"
#include "GraphViewer/graphviewer.h"
#include "UserInterface.h"


using namespace std;


int main() {
    cout << "   ------   WELCOME TO PORTO CITY TRANSFERS   ------" << endl;
    cout << endl << "             Fast and safe transportation" << endl << endl << endl;

    //maybe main menu
    Graph* graph = buildGraph("../Maps/GridGraphs/8x8/nodes.txt", "../Maps/GridGraphs/8x8/edges.txt");
    //Graph* graph = buildGraph("../Maps/PortugalMaps/Porto/nodes_x_y_porto.txt", "../Maps/PortugalMaps/Porto/edges_Porto.txt");

    cout << "Grafo lido tem " << graph->getNumVertex() << " vertices." << endl;

    GraphViewer* gv = creategraphViewer(graph);

    getchar();

    gv->closeWindow();
    free(gv);
    return 0;
}
