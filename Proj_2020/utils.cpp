#include "utils.h"





int menuOption(int minimum, int max){
    int numberInput;

    while (1) {
        std::cin >> numberInput;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(200, '\n');
            std::cout << "Please input a valid number: ";
            continue;
        }
        if (numberInput < minimum || numberInput > max) {
            std::cout << "Please input a single number between " << minimum << " and " << max << " (inclusive): ";
            std::cin.clear();
            std::cin.ignore(200, '\n');
            continue;
        }
        break;
    }
    return numberInput;
}


void showClients(CityTransfers* ct){
    int i = 0;
    for(auto client : ct->clients){
        cout << i << ":" << endl;
        cout << "Name : " << client.getName() << endl << "Destination: " << client.getDestiny() << endl;
        i++;
    }
}


Person newClient(CityTransfers* ct){
    string name;
    cout << "Person name: " << endl;
    cin >> name;
    double nif;
    cout << "Persons's NIF: " << endl;
    cin >> nif;
    int destID;
    cout << "Destination ID: " << endl;
    cin >> destID;
    while(ct->graph->findVertex(destID) == NULL){
        cout << "Invalid ID, try again: " << endl;
        cin>> destID;
    }

    return Person(name, nif, destID);
}


void showCars(CityTransfers* ct){
    int i = 0;
    for(auto car : ct->cars){
        cout << i << ":" << endl;
        cout << "Car id:" << car.getID() << endl;
        cout << "Number of seats: " << car.getSeats() << endl;
        i++;
    }
}


Car newCar(CityTransfers* ct){
    int seats;
    cout << "Number of seats available in car (between 4 and 8): " << endl;
    seats = menuOption(4,8);

    int ID = ct->cars.size()+1;

    return Car(seats, ID);
}



void getvertexesID(CityTransfers* ct, int &srcFloyd, int &destFloyd){
    cout << "Type source ID: " << endl;
    cin >> srcFloyd;
    while(ct->graph->findVertex(srcFloyd) == NULL){
        cout << "Invalid ID, try again: " << endl;
        cin>> srcFloyd;
    }

    cout << "Type destination ID: " << endl;
    cin >> destFloyd;
    while(ct->graph->findVertex(destFloyd) == NULL){
        cout << "Invalid ID, try again: " << endl;
        cin>> destFloyd;
    }
}