#include "Menu.h"

void firstProblem(CityTransfers* ct){
    int option;

    cout << "             || ================== First Problem =================" << endl;
    cout << "             || (1) Calculate and show route for one client" << endl;
    cout << "             || (2) Return to main menu" << endl;

    option = menuOption(1,2);

    switch(option){
        case 1:
            cout << "in first problem" << endl;
            firstProblem(ct);
            break;
        case 2:
            return;
    }
}


void carMenu(CityTransfers* ct){
    int option;

    cout << "             || ================== Client Menu =================" << endl;
    cout << "             || (1) Add Car" << endl;
    cout << "             || (2) Remove Car" << endl;
    cout << "             || (3) Return to main menu" << endl;

    option = menuOption(1,3);

    switch(option){
        case 1:
            //addCar(ct);
            carMenu(ct);
            break;
        case 2:
            //removeCar(ct);
            carMenu(ct);
            break;
        case 3:
            return;
    }
}

void clientMenu(CityTransfers* ct){
    int option;

    cout << "             || ================== Client Menu =================" << endl;
    cout << "             || (1) Add Client" << endl;
    cout << "             || (2) Remove Client" << endl;
    cout << "             || (3) Return to main menu" << endl;

    option = menuOption(1,3);

    switch(option){
        case 1:
            //addClient
            clientMenu(ct);
            break;
        case 2:
            //removeClient();
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