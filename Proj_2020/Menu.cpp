#include "Menu.h"

void firstProblem(CityTransfers* ct){
    int option;
    int dest;
    int clientID;
    double distance;

    cout << "             || ================== First Problem =================" << endl;
    cout << "             || (1) Dijkstra / Calculate and show route for one client " << endl;
    cout << "             || (2) Return to main menu" << endl;

    option = menuOption(1,2);

    switch(option){
        case 1:
            ct->graph->dijkstraShortestPath(5813); //it will be ct.stationID
            cout << "Choose client" << endl;
            showClients(ct);
            clientID = menuOption(0, ct->clients.size());
            showPathInGraph(ct->gv, ct->graph->getPath(5813, ct->clients[clientID].getDestiny()));
            ct->graph->dijkstraShortestPath(ct->clients[clientID].getDestiny()); //it will be ct.stationID
            showPathInGraph(ct->gv, ct->graph->getPath(ct->clients[clientID].getDestiny(), 5813));
            firstProblem(ct);
            break;
        case 2:
            return;
    }
}


void carMenu(CityTransfers* ct){
    int option;
    int id;

    cout << "             || ================== Client Menu =================" << endl;
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
                showClients(ct);
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
            //secondProblem();
            cout << "in 2" << endl;
            mainMenu(ct);
            break;
        case 3:
            //thirdProblem();
            cout << "in 3" << endl;
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
            return;
    }
}