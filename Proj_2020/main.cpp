#include <iostream>

#include "Car.h"
#include "Person.h"
#include "Graph.h"
#include "BuildGraph.h"

using namespace std;

int main() {
    cout << "   ------   WELCOME TO PORTO CITY TRANSFERS   ------" << endl;
    cout << endl << "Fast and safe transportation from Campanha train station" << endl << endl;

    //maybe main menu
    Graph* graph = buildGraph("../Maps/GridGraphs/4x4/nodes.txt", "../Maps/GridGraphs/4x4/edges.txt");

    cout << "Grafo lido tem " << graph->getNumVertex() << " vertices." << endl;

    return 0;
}
