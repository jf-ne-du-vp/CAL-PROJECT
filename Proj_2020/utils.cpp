#include "utils.h"


vector<Vertex *> appendPaths(vector<Vertex *> path1, vector<Vertex *> path2){
    vector<Vertex *> res;

    for(auto v : path1){
        res.push_back(v);
    }

    for(auto v : path2){
        res.push_back(v);
    }

    return res;
}