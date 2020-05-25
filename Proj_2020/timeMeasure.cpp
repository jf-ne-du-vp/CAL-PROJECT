#include "timeMeasure.h"

static chrono::high_resolution_clock::time_point startingTime;

void startTimeCount(){
    startingTime = chrono::high_resolution_clock::now();
}


long long getTimePassed(){
    auto finish = chrono::high_resolution_clock::now();
    long long time = chrono::duration_cast<chrono::milliseconds>(finish - startingTime).count();

    return time;
}