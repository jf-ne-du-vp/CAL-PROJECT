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


/**
 * @brief Creates graph by reading node file and edge file
 * @param nodePath Path to node file
 * @param edgePath Path to edge file
 * @return Built graph
 */
Graph* buildGraph(string nodePath, string edgePath);


/**
 * @brief Reads clients from client file
 * @param clientsPath Path to clients file
 * @return Vector with clients
 */
vector<Person> getClients(const string& clientsPath);


/**
 * @brief reads cars from cars file
 * @param carsPath Path to cars file
 * @return Vectir with cars
 */
vector<Car> getCars(const string& carsPath);


/**
 * @brief Reads station node ID from file, it is at the beginning of client file
 * @param ClientsPath path to clients file
 * @return Station node ID
 */
int getStation(const string& ClientsPath);


/**
 * @brief Saves created or deleted cars in file
 * @param carsPath Path to cars file
 * @param cars Vector with cars to save
 */
void saveCars(const string& carsPath, vector<Car> cars);


/**
 * @brief Saves created or deleted clients in file, and station node Id
 * @param carsPath Path to clients file
 * @param cars Vector with clients to save
 */
void saveClients(const string& clientsPath, vector<Person> clients);

#endif //PROJ_2020_BUILDGRAPH_H
