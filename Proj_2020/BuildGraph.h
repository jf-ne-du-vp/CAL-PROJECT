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

vector<Person> getClients(string clientsPath);

vector<Car> getCars(string carsPath);

int getStation(string ClientsPath);

#endif //PROJ_2020_BUILDGRAPH_H
