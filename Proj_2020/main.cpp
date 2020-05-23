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
    //Graph* graph = buildGraph("../Maps/PortugalMaps/Lisboa/nodes_x_y_lisboa.txt", "../Maps/PortugalMaps/Lisboa/edges_lisboa.txt");
    //Graph* graph = buildGraph("../Maps/MapaPorto/porto_strong_nodes_xy.txt", "../Maps/MapaPorto/porto_strong_edges.txt");
    //Graph* graph = buildGraph("../Maps/MapaEspinho/espinho_strong_nodes_xy.txt", "../Maps/MapaEspinho/espinho_strong_edges.txt");
    Graph* graph = buildGraph("../Maps/MapaPenafiel/penafiel_strong_nodes_xy.txt", "../Maps/MapaPenafiel/penafiel_strong_edges.txt");

    cout << "Grafo lido tem " << graph->getNumVertex() << " vertices." << endl;

    GraphViewer* gv = creategraphViewer(graph);

    //for grid
    //graph->dijkstraShortestPath(34);
    //vector<Vertex *> v1 = graph->getPath(34, 282);

    //graph->dijkstraShortestPath(27744); //Porto
    //vector<Vertex *> v1 = graph->getPath(27744, 26781);
    //graph->dijkstraShortestPath(2783);
    //vector<Vertex *> v1 = graph->getPath(2783, 6765);
    //graph->dijkstraShortestPath(14267);
    //vector<Vertex *> v1 = graph->getPath(14267, 17617);
    //graph->dijkstraShortestPath(3617);
    vector<Vertex *> v1; // = graph->getPath(3617, 5033);
    //cout << "Vertices visitados: " << v1.size() << endl;
    //showPathInGraph(gv, v1);
    double d = 0;
    for(int i = 0; i < v1.size(); i++){
        d += v1[i]->getDist();
    }


    //floydwarshal
    cout << "starting floyd" << endl;
    graph->floydWarshallShortestPath();
    cout << "calculated floyd" << endl;
    v1 = graph->getfloydWarshallPath(3617, 5033);
    cout << "got floyd path" << endl;
    showPathInGraph(gv, v1);


    cout << "Dist total percorrida floyd: " << graph->getfloydWarshallWeight(3617,5033)<<endl;
    cout << "Dist total percorrida dijkstra: " << d << endl;
    getchar();

    gv->closeWindow();
    free(gv);
    return 0;
}