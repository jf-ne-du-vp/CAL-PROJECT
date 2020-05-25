#include <iostream>


#include "Car.h"
#include "Person.h"
#include "Graph.h"
#include "BuildGraph.h"
#include "GraphViewer/graphviewer.h"
#include "UserInterface.h"
#include "Menu.h"
#include "CityTransfers.h"


using namespace std;


int main() {
    cout << "   ------   WELCOME TO PORTO CITY TRANSFERS   ------" << endl;
    cout << endl << "             Fast and safe transportation" << endl << endl << endl;

    auto* ct = new CityTransfers();
    mapMenu(ct);
    ct->gv = creategraphViewer(ct->graph);
    mainMenu(ct);


    //Do dfs to process
    //cout << "Pre-procesing starting" << endl;
    //Do treatment for non accessible and draw them black
    //cout << "Pre-procesing finished, not acessible nodes represnetd in black" << endl;


    //cout << "Before dfs:" << ct->graph->findVertex(6519)->getVisited() << endl;
    //ct->graph->dfs(ct->graph->findVertex(9074));
    //cout << "completed dfs" << endl;
    //cout << "After dfs:" << ct->graph->findVertex(6519)->getVisited() << endl;

    ct->gv->closeWindow();
    free(ct->gv);
    return 0;
}