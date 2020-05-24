#ifndef PROJ_2020_UTILS_H
#define PROJ_2020_UTILS_H

#include <vector>

#include "Graph.h"
#include "Person.h"
#include "Car.h"
#include "CityTransfers.h"

vector<Vertex *> appendPaths(vector<Vertex *> path1, vector<Vertex *> path2);

int menuOption(int minimum, int max);

int showClients(CityTransfers* ct);

Person newClient(CityTransfers* ct);

int showCars(CityTransfers* ct);

Car newCar(CityTransfers* ct);

#endif //PROJ_2020_UTILS_H
