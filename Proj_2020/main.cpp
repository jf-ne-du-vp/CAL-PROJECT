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
    //Graph* graph = buildGraph("../Maps/GridGraphs/16x16/nodes.txt", "../Maps/GridGraphs/16x16/edges.txt");
    //Graph* graph = buildGraph("../Maps/PortugalMaps/Espinho/nodes_x_y_porto.txt", "../Maps/PortugalMaps/Espinho/edges_Porto.txt");
    //Graph* graph = buildGraph("../Maps/MapaPorto/porto_strong_nodes_xy.txt", "../Maps/MapaPorto/porto_strong_edges.txt");
    Graph* graph = buildGraph("../Maps/MapaEspinho/espinho_full_nodes_xy.txt", "../Maps/MapaEspinho/espinho_full_edges.txt");

    cout << "Grafo lido tem " << graph->getNumVertex() << " vertices." << endl;

    GraphViewer* gv = creategraphViewer(graph);


    //graph->dijkstraShortestPath(27744);
    //vector<Vertex *> v1 = graph->getPath(27744, 26781);
    graph->dijkstraShortestPath(2783);
    vector<Vertex *> v1 = graph->getPath(2783, 6765);
    cout << "Vertices visitados: " << v1.size() << endl;
    sleep(5);
    showPathInGraph(gv, v1);

    //path total km
    int d = 0;
    for(int i = 0; i < v1.size(); i++){
        d += v1[i]->getDist();
    }
    cout << "Dist total percorrida: " << d << endl;
    getchar();

    gv->closeWindow();
    free(gv);
    return 0;
}
