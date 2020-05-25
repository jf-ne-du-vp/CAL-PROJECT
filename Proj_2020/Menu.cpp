#include "Menu.h"

void secondProblem(CityTransfers* ct){
    int option;
    vector<int> IDS;
    vector<Vertex*> p;

    cout << "             || ================== Main Menu =================" << endl;
    cout << "             || (1) Nearest neighbour / using Dijkstra" << endl;
    cout << "             || (2) Return to main menu" << endl;

    option = menuOption(1,2);

    switch(option){
        case 1:
            resetGraph(ct->gv, ct->graph);
            for(const auto& c : ct->clients){
                IDS.push_back(c.getDestiny());
            }

            p = ct->graph->nearNeighborDij(IDS, ct->stationID);
            showPathInGraph(ct->gv, p);
            paintClients(ct->gv, ct->graph, IDS);
            cout << "Number of clients in this route: " << IDS.size() << endl;
            cout << "Station identified in green and each client destination in black" << endl;
            cout << "Distance traveled: " << ct->graph->getnearDist() << endl;
            IDS.erase(IDS.begin(), IDS.end());
            secondProblem(ct);
            break;
        case 2:
            return;
    }
}


void firstProblem(CityTransfers* ct){
    int option;
    int dest;
    int clientID;
    double distance = 0;
    vector<Vertex*> p;
    int srcFloyd;
    int destFloyd;

    cout << "             || ================== First Problem =================" << endl;
    cout << "             || (1) Dijkstra / Calculate and show route for one client " << endl;
    cout << "             || (2) A Star / Calculate and show route for one client" << endl;
    cout << "             || (3) Floyd-Warshall / Calculate and show route between any two nodes" << endl;
    cout << "             ||     Be aware it will take too long to calculate " << endl;
    cout << "             || (4) Return to main menu" << endl;

    option = menuOption(1,4);

    switch(option){
        case 1:
            resetGraph(ct->gv, ct->graph);
            ct->graph->dijkstraShortestPath(ct->stationID); //it will be ct.stationID
            cout << "Choose client" << endl;
            showClients(ct);
            clientID = menuOption(0, ct->clients.size());
            showPathInGraph(ct->gv, ct->graph->getPath(ct->stationID, ct->clients[clientID].getDestiny()));
            distance += ct->graph->findVertex(ct->clients[clientID].getDestiny())->getDist();
            ct->graph->dijkstraShortestPath(ct->clients[clientID].getDestiny()); //it will be ct.stationID
            showPathInGraph(ct->gv, ct->graph->getPath(ct->clients[clientID].getDestiny(), ct->stationID));
            distance += ct->graph->findVertex(ct->stationID)->getDist();
            cout << "Total distance traveled is: " << distance << endl;
            distance = 0;
            firstProblem(ct);
            break;
        case 2:
            resetGraph(ct->gv, ct->graph);
            cout << "Choose client" << endl;
            showClients(ct);
            clientID = menuOption(0, ct->clients.size());
            p = ct->graph->aStar(ct->stationID, ct->clients[clientID].getDestiny());
            showPathInGraph(ct->gv, p);
            distance += ct->graph->findVertex(ct->clients[clientID].getDestiny())->getDistASTAR();
            p = ct->graph->aStar(ct->clients[clientID].getDestiny(), ct->stationID);
            showPathInGraph(ct->gv, p);
            distance += ct->graph->findVertex(ct->stationID)->getDistASTAR();
            cout << "Total distance traveled is: " << distance << endl;
            distance = 0;
            firstProblem(ct);
            break;
        case 3:
            resetGraph(ct->gv, ct->graph);
            cout << "Starting to calculate Floyd-Warshall" << endl;
            ct->graph->floydWarshallShortestPath();
            cout << "Calculated Floyd-Warshall" << endl;

            cout << "Press one to see path, two to leave" << endl;
            while(menuOption(1,2) != 2) {
                cout << "Vertexes IDs:" << endl;
                getvertexesID(ct, srcFloyd, destFloyd);
                p = ct->graph->getfloydWarshallPath(srcFloyd, destFloyd);
                showPathInGraph(ct->gv, p);
                cout << "Press one to see another path, two to leave" << endl;
            }

            firstProblem(ct);
            break;
        case 4:
            return;
    }
}


void carMenu(CityTransfers* ct){
    int option;
    int id;

    cout << "             || ================== Car Menu =================" << endl;
    cout << "             || (1) Add Car" << endl;
    cout << "             || (2) Remove Car" << endl;
    cout << "             || (3) Return to main menu" << endl;

    option = menuOption(1,3);

    switch(option){
        case 1:
            ct->cars.push_back(newCar(ct));
            carMenu(ct);
            break;
        case 2:
            if(!ct->cars.empty()) {
                showCars(ct);
                cout << "Car to remove: " << endl;
                id = menuOption(0, ct->cars.size());
                ct->cars.erase(ct->cars.begin() + id);
                cout << "Car eliminated" << endl << endl;
            } else
                cout << "No car to eliminate." << endl;
            carMenu(ct);
            break;
        case 3:
            return;
    }
}


void clientMenu(CityTransfers* ct){
    int option;
    int id;

    cout << "             || ================== Client Menu =================" << endl;
    cout << "             || (1) Add Client" << endl;
    cout << "             || (2) Remove Client" << endl;
    cout << "             || (3) Return to main menu" << endl;

    option = menuOption(1,3);

    switch(option){
        case 1:
            ct->clients.push_back(newClient(ct));
            clientMenu(ct);
            break;
        case 2:
            if(!ct->clients.empty()) {
                showClients(ct);
                cout << "Client to remove: " << endl;
                id = menuOption(0, ct->clients.size());
                ct->clients.erase(ct->clients.begin() + id);
                cout << "Client eliminated" << endl << endl;
            } else
                cout << "No client to eliminate." << endl;
            clientMenu(ct);
            break;
        case 3:
            return;
    }
}


void mainMenu(CityTransfers* ct){
    int option;

    cout << "             || ================== Main Menu =================" << endl;
    cout << "             || (1) One Car / One Destiny" << endl;
    cout << "             || (2) One Car / Multiple Destinations" << endl;
    cout << "             || (3) Multiple Cars / Multiple Destinations" << endl;
    cout << "             || (4) Add/Eliminate Client" << endl;
    cout << "             || (5) Add/Eliminate Car" << endl;
    cout << "             || (6) Exit City Transfers" << endl;

    option = menuOption(1,6);

    switch(option){
        case 1:
            firstProblem(ct);
            mainMenu(ct);
            break;
        case 2:
            secondProblem(ct);
            mainMenu(ct);
            break;
        case 3:
            //thirdProblem();
            cout << "To be implemented" << endl;
            mainMenu(ct);
            break;
        case 4:
            clientMenu(ct);
            mainMenu(ct);
            break;
        case 5:
            carMenu(ct);
            mainMenu(ct);
            break;
        case 6:
            if(ct->currentGraph == 1 || ct->currentGraph == 4){
                saveCars("../Maps/MapaPorto/cars.txt", ct->cars);
                //saveClients("../Maps/MapaPorto/clients.txt", ct->clients);
                ct->clients.emplace_back("Teresa", 564, 1090);
            }
            else if(ct->currentGraph == 2){
                saveCars("../Maps/MapaEspinho/cars.txt", ct->cars);
                //saveClients("../Maps/MapaEspinho/clients.txt", ct->clients);
            }
            else if(ct->currentGraph == 3){
                saveCars("../Maps/MapaPenafiel/cars.txt", ct->cars);
                //saveClients("../Maps/MapaPenafiel/clients.txt", ct->clients);
            }
            return;
    }
}


void mapMenu(CityTransfers* ct){
    int option;

    cout << "             || ================== Map Menu =================" << endl;
    cout << "             ||     Wich map to choose?"<< endl;
    cout << "             || (1) Porto map / Strong" << endl;
    cout << "             || (2) Espinho map / Strong" << endl;
    cout << "             || (3) Penafiel map / Strong" << endl;
    cout << "             || (4) Porto map / Full (to test connectivity)" << endl;



    option = menuOption(1,4);

    switch(option){
        case 1:
            ct->currentGraph = 1;
            cout << "Loading Graph" << endl;
            ct->graph = buildGraph("../Maps/MapaPorto/porto_strong_nodes_xy.txt", "../Maps/MapaPorto/porto_strong_edges.txt");
            cout << "Graph loaded" << endl << endl;
            ct->stationID = getStation("../Maps/MapaPorto/clients.txt");
            //ct->clients = getClients("../Maps/MapaPorto/clients.txt");
            ct->cars = getCars("../Maps/MapaPorto/cars.txt");
            ct->clients.emplace_back("Luis", 56, 50570);
            ct->clients.emplace_back("Joao", 54, 5665);
            ct->clients.emplace_back("Lourenco", 64, 4083);
            ct->clients.emplace_back("Teresa", 564, 1090);
            break;
        case 2:
            ct->currentGraph = 2;
            cout << "Loading Graph" << endl;
            ct->graph = buildGraph("../Maps/MapaEspinho/espinho_strong_nodes_xy.txt", "../Maps/MapaEspinho/espinho_strong_edges.txt");
            cout << "Graph loaded" << endl << endl;
            ct->stationID = getStation("../Maps/MapaEspinho/clients.txt");
            //ct->clients = getClients("../Maps/MapaEspinho/clients.txt");
            ct->cars = getCars("../Maps/MapaEspinho/cars.txt");
            ct->clients.emplace_back("Teresa", 564, 4414);
            ct->clients.emplace_back("Luis", 56, 8964);
            ct->clients.emplace_back("Joao", 54, 489);
            ct->clients.emplace_back("Lourenco", 64, 5328);
            ct->clients.emplace_back("Maria", 23, 11867);
            break;
        case 3:
            ct->currentGraph = 3;
            cout << "Loading Graph" << endl;
            ct->graph = buildGraph("../Maps/MapaPenafiel/penafiel_strong_nodes_xy.txt", "../Maps/MapaPenafiel/penafiel_strong_edges.txt");
            cout << "Graph loaded" << endl << endl;
            ct->stationID = getStation("../Maps/MapaPenafiel/clients.txt");
            //ct->clients = getClients("../Maps/MapaPenafiel/clients.txt");
            ct->cars = getCars("../Maps/MapaPenafiel/cars.txt");
            ct->clients.emplace_back("Teresa", 564, 9236);
            ct->clients.emplace_back("Luis", 56, 842);
            ct->clients.emplace_back("Joao", 54, 9967);
            ct->clients.emplace_back("Lourenco", 64, 1511);
            break;
        case 4:
            ct->currentGraph = 4;
            cout << "Loading Graph" << endl;
            ct->graph = buildGraph("../Maps/MapaPorto/porto_full_nodes_xy.txt", "../Maps/MapaPorto/porto_full_edges.txt");
            cout << "Graph loaded" << endl << endl;
            ct->stationID = getStation("../Maps/MapaPorto/clients.txt");
            //ct->clients = getClients("../Maps/MapaPorto/clients.txt");
            ct->cars = getCars("../Maps/MapaPorto/cars.txt");
            ct->clients.emplace_back("Luis", 56, 50570);
            ct->clients.emplace_back("Joao", 54, 5665);
            ct->clients.emplace_back("Lourenco", 64, 4083);
            ct->clients.emplace_back("Teresa", 564, 1090);
            break;
    }
}