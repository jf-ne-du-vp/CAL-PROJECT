#ifndef PROJ_2020_BUILDGRAPH_H
#define PROJ_2020_BUILDGRAPH_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "Graph.h"
#include "Person.h"
#include "Car.h"



Graph* buildGraph(string nodePath, string edgePath);

vector<Person> getClients(const string& clientsPath);

vector<Car> getCars(const string& carsPath);

int getStation(const string& ClientsPath);

void saveCars(const string& carsPath, vector<Car> cars);

void saveClients(const string& clientsPath, vector<Person> clients);

#endif //PROJ_2020_BUILDGRAPH_H
