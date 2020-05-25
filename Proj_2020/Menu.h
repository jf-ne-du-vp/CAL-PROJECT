#ifndef PROJ_2020_MENU_H
#define PROJ_2020_MENU_H

#include <iostream>

#include "Graph.h"
#include "utils.h"
#include "CityTransfers.h"
#include "UserInterface.h"


using namespace std;


/**
 *  @brief Menu of first problem iteration
 * @param ct CityTransfers class, represents company information
 */
void firstProblem(CityTransfers* ct);


/**
 *  @brief Menu of second problem iteration
 * @param ct CityTransfers class, represents company information
 */
void secondProblem(CityTransfers* ct);



/**
 *  @brief Menu of third problem iteration
 * @param ct CityTransfers class, represents company information
 */
void thirdProblem(CityTransfers* ct);


/**
 * @brief Menu to add or eliminate cars
 * @param ct CityTransfers class, represents company information
 */
void carMenu(CityTransfers* ct);


/**
 * @ brief Menu to add or eliminate clients
 * @param ct CityTransfers class, represents company information
 */
void clientMenu(CityTransfers* ct);

/**
 * @brief Main menu to navigete to other menus
 * @param ct CityTransfers class, represents company information
 */
void mainMenu(CityTransfers* ct);


/**
 * @brief First menu shown to user, to choose map
 * @param ct CityTransfers class, represents company information
 */
void mapMenu(CityTransfers* ct);


#endif //PROJ_2020_MENU_H
