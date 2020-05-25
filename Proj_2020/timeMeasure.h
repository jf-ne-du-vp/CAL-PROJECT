#ifndef PROJ_2020_TIMEMEASURE_H
#define PROJ_2020_TIMEMEASURE_H



#include <chrono>

using namespace std;


/**
 * @brief Start clock time
 */
void startTimeCount();


/**
 * @brief Get time since start clock time
 * @return Elapsed time, miliseconds
 */
long long getTimePassed();


#endif //PROJ_2020_TIMEMEASURE_H
