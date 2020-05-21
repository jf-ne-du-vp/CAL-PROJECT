#include "Path.h"

Path::Path(){}

Path::Path(double distance, const vector<Vertex*> &path): distance(distance), path(path){}

double Path::getDistance() const{
    return this->distance;
}
vector<Vertex *> Path::getPath() const{
    return this->path;
}