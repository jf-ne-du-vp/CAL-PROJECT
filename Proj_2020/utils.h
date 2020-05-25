#ifndef PROJ_2020_UTILS_H
#define PROJ_2020_UTILS_H

#include <vector>

#include "Graph.h"
#include "Person.h"
#include "Car.h"
#include "CityTransfers.h"



/**
 * @brief Used by menus to get user number input/ and also to choose client and car
 * @param minimum Lowest option in menu
 * @param max Highest option in menu
 * @return Number of option selected by user
 */
int menuOption(int minimum, int max);


/**
 * @brief Show user clients in CityTransfers
 * @param ct Company with clients
 */
void showClients(CityTransfers* ct);


/**
 * @brief Creating new client by user
 * @param ct Company with all info, so that when choosing a destination ID to see if it is in graph
 * @return New Person object
 */
Person newClient(CityTransfers* ct);


/**
 * @brief Show user cars in CityTransfers
 * @param ct Company with cars
 */
void showCars(CityTransfers* ct);


/**
 * @brief Creating new car
 * @param ct Company with all info
 * @return Naw car object
 */
Car newCar(CityTransfers* ct);

#endif //PROJ_2020_UTILS_H
