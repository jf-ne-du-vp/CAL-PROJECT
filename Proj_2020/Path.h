#ifndef PROJ_2020_PATH_H
#define PROJ_2020_PATH_H

#include "Graph.h"

using namespace std;

class Path {
    double distance;
    vector<Vertex *> path;
public:
    Path();
    Path(double distance, const vector<Vertex*> &path);

    double getDistance() const;
    vector<Vertex *> getPath() const;


};


#endif //PROJ_2020_PATH_H
