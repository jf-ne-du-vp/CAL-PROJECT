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

    ct->gv->closeWindow();
    free(ct->gv);
    return 0;
}