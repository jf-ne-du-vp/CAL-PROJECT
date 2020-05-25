#include "utils.h"


vector<Vertex *> appendPaths(vector<Vertex *> path1, vector<Vertex *> path2){
    vector<Vertex *> res;

    for(auto v : path1){
        res.push_back(v);
    }

    for(auto v : path2){
        res.push_back(v);
    }

    return res;
}

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

int showClients(CityTransfers* ct){
    int i = 0;
    for(auto client : ct->clients){
        cout << i << ":" << endl;
        cout << "Name : " << client.getName() << " Destination: " << client.getDestiny() << endl;
        i++;
    }
    return 0;
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

int showCars(CityTransfers* ct){
    int i = 0;
    for(auto car : ct->cars){
        cout << i << ":" << endl;
        cout << "Number of seats: " << car.getSeats() << endl;
        i++;
    }

    return 0;
}


Car newCar(CityTransfers* ct){
    int seats;
    cout << "Number of seats available in car (between 4 and 8): " << endl;
    seats = menuOption(4,8);

    return Car(seats);
}