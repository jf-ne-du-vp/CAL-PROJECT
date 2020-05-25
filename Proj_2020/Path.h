#ifndef PROJ_2020_PATH_H
#define PROJ_2020_PATH_H

#include "Graph.h"

using namespace std;


/**
 * @brief Pat class used to structure calculated path
 */
class Path {

    /**
     * Path total distance
     */
    double distance;

    /**
     * Vector with sequence of visited vertexes in path
     */
    vector<Vertex *> path;
public:

    /**
     * @brief Constructor of new Path object
     */
    Path();

    /**
     * @brief Constructor of new Path object
     * @param distance Path total distance
     * @param path with sequence of visited vertexes in path
     */
    Path(double distance, const vector<Vertex*> &path);


    /**
     * @brief Get Path total distance
     * @return Path total distance
     */
    double getDistance() const;

    /**
     * @brief Get Vector with sequence of visited vertexes in path
     * @return Vector with sequence of visited vertexes in path
     */
    vector<Vertex *> getPath() const;
};


#endif //PROJ_2020_PATH_H
