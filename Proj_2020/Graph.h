#ifndef PROJ_2020_GRAPH_H
#define PROJ_2020_GRAPH_H

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <stack>
#include <list>
#include <queue>


#include "MutablePriorityQueue.h"


using namespace std;

#define INF std::numeric_limits<double>::max()

class Vertex;
class Edge;
class Graph;


/*********************   VERTEX   *********************/


class Vertex{
    int ID;                     //identification of vertex
    double x, y;                //location of vertex
    vector<Edge*> adj;          //outgoing edges


    double dist = 0;
    Vertex *path = NULL;
    int queueIndex = 0; 		// required by MutablePriorityQueue

    bool visited = false;		// auxiliary field
    bool processing = false;	// auxiliary field

    void addEdge(int ID, Vertex *dest, double w);

public:
    Vertex(int ID, double x, double y);
    int getID() const;
    double getX() const;
    double getY() const;
    double getDist() const;
    vector<Edge*> getAdj() const;
    Vertex *getPath() const;

    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};


/*********************   EDGE   *********************/


class Edge{
    int ID;
    double weight;     //distance from vertex to vertex
    Vertex *dest;      //destination vertex

public:
    Edge(int ID, Vertex *dest, double weight);
    int getID() const;
    double getWeight() const;
    Vertex* getDest() const;

    friend class Graph;
    friend class Vertex;
};


/*********************   GRAPH   *********************/


class Graph {
    vector<Vertex*> vertexSet;      //vertex set

public:
    Vertex* findVertex(int ID) const;
    bool addVertex(int ID, double x, double y);
    bool addEdge(int edgeID, int srcID, int destID, double weight);
    int getNumVertex() const;
    vector<Vertex *> getVertexSet() const;

    vector<Vertex *> getPath(const int &origin, const int &dest) const;

    //algorithms
    void dijkstraShortestPath(int srcID);
};


#endif //PROJ_2020_GRAPH_H
