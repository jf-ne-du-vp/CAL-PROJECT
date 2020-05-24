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
    bool clientDest = false;

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
    void setVisited(bool visited);
    bool getVisited() const;
    void setClientDest(bool dest);
    bool getClientDest() const;


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

    //for Floyd-Warshall
    vector<vector<double>> W;
    vector<vector<int>> P;

public:
    Vertex* findVertex(int ID) const;
    bool addVertex(int ID, double x, double y);
    bool addEdge(int edgeID, int srcID, int destID, double weight);
    int getNumVertex() const;
    vector<Vertex *> getVertexSet() const;
    int findVertexIdx(Vertex* vertex) const;

    //for Floyd-Warshall
    void resetMatrixW(int size);
    void resetMatrixP(int size);
    void setW(int i, int j, double weight);
    double getW(int i, int j) const;
    void setP(int i, int j, int index);
    int getP(int i, int j) const;
    double edgeWeight(int i, int j) const;
    int nextVertex(int i, int j) const;




    //algorithms
    static void dfsVisit(Vertex* vertex);
    void dfs(Vertex* src);
    static bool dfsVisit(Vertex* vertex, Vertex* dest);
    bool dfs(Vertex* src, Vertex* dest);

    void dijkstraShortestPath(int srcID);
    vector<Vertex *> getPath(const int &origin, const int &dest) const;

    void floydWarshallShortestPath();
    vector<Vertex *> getfloydWarshallPath(const int &orig, const int &dest) const;
    double getfloydWarshallWeight(const int &orig, const int &dest) const;

    //vector<Vertex *> nearestNeighbour

};


#endif //PROJ_2020_GRAPH_H
