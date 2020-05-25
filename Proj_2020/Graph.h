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


/**
 * @brief Class Vertex used in graph, adapted from used in classes
 */
class Vertex{

    /**
     * Vertex ID
     */
    int ID;                     //identification of vertex

    /**
     * @brief vertex location
     */
    double x, y;                //location of vertex

    /**
     * @brief Vector with outgoing edges
     */
    vector<Edge*> adj;          //outgoing edges

    /**
     * Used by dijkstra, distance from source to this->vertex
     */
    double dist = 0;

    /**
     * Used by A-STAR, distance from source to this->vertex, euclidian or manhattan
     */
    double distASTAR = 0;

    /**
     * Pointer to the previous vertex in a calculated path
     */
    Vertex *path = NULL;

    /**
     * required by MutablePriorityQueue
     */
    int queueIndex = 0; 		// required by MutablePriorityQueue

    /**
     * auxiliary field
     */
    bool clientDest = false;

    /**
     * auxiliary field for dfs
     */
    bool visited = false;		// auxiliary field for dfs

    /**
     * auxiliary field
     */
    bool processing = false;	// auxiliary field

    /**
     * @brief Adds an adjacent edge to the vertex
     * @param ID ID of vertex destination of edge
     * @param dest Pointer to vertex destination of edge
     * @param w Distance from current vertex do detination vertex
     */
    void addEdge(int ID, Vertex *dest, double w);

public:

    /**
     * @brief Constructor of new Vertex
     * @param ID New Vertex ID
     * @param x X coord of the new vertex
     * @param y Y coord of the new vertex
     */
    Vertex(int ID, double x, double y);


    /**
     * @brief Get Vertex ID
     * @return Vertex ID
     */
    int getID() const;

    /**
     * @brief Get Vertx X coordinate
     * @return X coordinate of vertex
     */
    double getX() const;

    /**
     * @brief get Vertex Y coordinate
     * @return Y coordinate of vertex
     */
    double getY() const;

    /**
     * @brief Get distance until this->vertex
     * @return Distance to this->vertex
     */
    double getDist() const;

    /**
     * @brief Get distance until this->vertex
     * @return Distance to this->vertex
     */
    double getDistASTAR() const;

    /**
     * @brief Get outgoing edges
     * @return
     */
    vector<Edge*> getAdj() const;

    /**
     * @brief GEt the atribute path
	 * @return Previous vertex in calculated path
     */
    Vertex *getPath() const;

    /**
	 * @brief Sets the atribute visited
	 * @param visited New value to be set
	 */
    void setVisited(bool visited);

    /**
	 * @brief Indicates if the vertex has been visited
	 * @return True if the vertex was previously visited,
	 * False otherwise
	 */
    bool getVisited() const;

    /**
     * @brief Set Auxiliary field
     * @param dest Auxiliary field
     */
    void setClientDest(bool dest);

    /**
     * @brief Get Auxiliary field
     * @return Auxiliary field
     */
    bool getClientDest() const;


    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
    friend class Graph;
    friend class MutablePriorityQueue<Vertex>;
};


/*********************   EDGE   *********************/


/**
 * @brief Class Edge used in graph, adapted from used in classes
 */
class Edge{

    /**
     * Edge ID
     */
    int ID;

    /**
     * Edge distance from vertex to vertex
     */
    double weight;     //distance from vertex to vertex

    /**
     * Pointer to destination vertex
     */
    Vertex *dest;      //destination vertex

public:

    /**
     * @brief Constructor of new edge
     * @param ID Edge ID
     * @param dest Pointer to destination vertex
     * @param weight Edge distance from vertex to vertex
     */
    Edge(int ID, Vertex *dest, double weight);


    /**
     * @brief Get edge ID
     * @return Edge ID
     */
    int getID() const;

    /**
     * @ Get edge distance, length
     * @return edge distance (length))
     */
    double getWeight() const;

    /**
     * @brief Get pointer to destination vertex
     * @return Pointer to destination vertex
     */
    Vertex* getDest() const;

    friend class Graph;
    friend class Vertex;
};


/*********************   GRAPH   *********************/


/**
 * @brief Class Graph used to store vertexes and edges and methods to them. Adapted from used in classes
 */
class Graph {

    /**
     * Vector with vertexes of graph
     */
    vector<Vertex*> vertexSet;      //vertex set

    //for Floyd-Warshall
    /**
     * Matrix with weight from vertex to vertex, used by floyd-Warshall
     */
    vector<vector<double>> W;

    /**
     * Matrix with previous vertex ID, from vertex to vertex, used by floyd-Warshall
     */
    vector<vector<int>> P;

    /**
     * Distance from nearest distant vertex, user by nearest neighbor
     */
    double nearDist = 0;

public:

    /**
     * @brief Find vertex with ID received in parameter
     * @param ID Id of vertex to be found
     * @return Pointer to found vertex
     */
    Vertex* findVertex(int ID) const;


    /**
	 * @brief Adds a new Vertex to the vertex set
	 * @param ID ID of the vertex
	 * @param x X Coord of the vertex
	 * @param y Y Coord of the vertex
	 * @return True if the addition was successful,
	 * False otherwise
	 */
    bool addVertex(int ID, double x, double y);

    /**
	 * @brief Adds a new Edge to the graph
     * @param edgeID ID of edge to add
	 * @param srcID ID of the source vertex of the edge
	 * @param destID ID of the destination vertex of the edge
	 * @param weight Weight of the edge
	 * @return True if the addition was successful,
	 * False otherwise
	 */
    bool addEdge(int edgeID, int srcID, int destID, double weight);


    /**
	 * @brief Get current size of the vertex set
	 * @return Size of the vertex set
	 *
	 */
    int getNumVertex() const;

    /**
     * @brief Get current vertex set
     * @returncurrent vertex set
     */
    vector<Vertex *> getVertexSet() const;

    /**
     * @brief find index in vertex of vertex
     * @param vertex Pointer of vertex to wich we want to find index
     * @return Index in vertexSet of the vertex
     */
    int findVertexIdx(Vertex* vertex) const;

    /**
     * @brief Get nearDist, used by nearest neighbor
     * @return NearDist
     */
    double getnearDist() const;

    /**
     * @brief Set nearDist, used by nearest neighbor
     * @param nearDist New nearDist
     */
    void setnearDist(double nearDist);

    //for Floyd-Warshall
    /**
	 * @brief Reset the matrix of distances
	 * @param size Size of the matrix
	 */
    void resetMatrixW(int size);

    /**
     * @brief Reset the matrix of paths
     * @param sizeS ize of the matrix
     */
    void resetMatrixP(int size);

    /**
	 * @brief Set the distance in the vertex matrix between the vertex with indexes i and j
	 * @param i Index in the vertex matrix of the source vertex
	 * @param j Index in the vertex matrix of the destination vertex
	 * @param value Distance between the two vertexes
	 *
	 */
    void setW(int i, int j, double weight);

    /**
	 * @brief Get distance in the vertex matrix between vertex width indexes i and j
	 * @param i Index in the vertex matrix of the source vertex
	 * @param j Index in the vertex matrix of the destination vertex
	 * @return Distance between the vertexes
	 */
    double getW(int i, int j) const;

    /**
	 * @brief Set the index of the following vertex in the shortest path between i and j
	 * @param i Index in the path matrix of the source vertex
	 * @param j Index in the path matrix of the destination vertex
	 * @param index of the following vertex in the shortest path between in and j
	 */
    void setP(int i, int j, int index);

    /**
	 * @brief Get the index of the following vertex in the shortest path between i and j
	 * @param i Index in the path matrix of the source vertex
	 * @param j Index in the path matrix of the destination vertex
	 * @return Index of the following vertex in the shortest path between in and j
	 */
    int getP(int i, int j) const;

    /**
	 * @brief Get the weight of the edge that connects the two vertexes with indexes i and j in the vertex set
	 * @param i Index of the source vertex in the vertex set
	 * @param j Index of the destination vertex in the vertex set
	 * @return Distance of the edge
	 *
	 */
    double edgeWeight(int i, int j) const;

    /**
	 * @brief Get the next vertex on the shortest path between i and j
	 * @param i Index of the source vertex in the path matrix
	 * @param j Index of the destination vertex in the path matrix
	 * @return Return j if it is adjacent to i, otherwise returns -1
	 */
    int nextVertex(int i, int j) const;




    //algorithms
    /**
     * @brief Funciotn to help dfs
     * @param vertex Pointer to vertex
     */
    static void dfsVisit(Vertex* vertex);
    /**
     * @brief Calculate depth first search from one vertex to all other
     * To know where we can get to
     * @param src Pointer to source vertex
     */
    void dfs(Vertex* src);
    /**
     * @brief Funciotn to help dfs
     * @param vertex Pointer to source vertex
     * @param dest Pointer to destination vertex
     * @return True if possible
     * False otherwise
     */
    static bool dfsVisit(Vertex* vertex, Vertex* dest);
    /**
    * @brief Calculate depth first search from one vertex to another, not working
    * @param vertex Pointer to source vertex
    * @param dest Pointer to destination vertex
    * @return True if possible
    * False otherwise
    */
    bool dfs(Vertex* src, Vertex* dest);


    /**
     * @brief Calculate shortest path from one vertex to all others using dijkstra algorithm
     * @param srcID ID of source vertex
     */
    void dijkstraShortestPath(int srcID);

    /**
     * @brief Calculate path from one vertex to another others using AStar, euclidian heuristic
     * @param origin ID of origin vertex
     * @param dest ID of destination vertex
     * @return Vector with all visited vertexes in calculated path, ordered
     */
    vector<Vertex *> aStar(const int &origin, const int &dest);

    /**
     * @brief Used to get path calculated in dijkstra and astar
     * @param origin ID of origin vertex
     * @param dest ID of destination vertex
     * @return Vector with all visited vertexes in calculated path, ordered
     */
    vector<Vertex *> getPath(const int &origin, const int &dest) const;



    /**
     * @brief Calculate shortest path between all pair of vertexes in vertexSet
     */
    void floydWarshallShortestPath();

    /**
     * @brief Get path from matrix of shortest paths of floyd-warshall
     * @param orig ID of source vertex
     * @param dest ID of destination vertex
     * @return Vector with all visited vertexes in calculated path, ordered
     */
    vector<Vertex *> getfloydWarshallPath(const int &orig, const int &dest) const;

    /**
     * @brief Get Distance, from matrix of weights, travelled in path calculated in floyd-warshall
     * @param orig ID of source vertex
     * @param dest ID of destination vertex
     * @return Distance from vertex to vertex
     */
    double getfloydWarshallWeight(const int &orig, const int &dest) const;



    /**
     * @brief Get ID of nearest vertex, from vector parameter, with dist calculated in most recent dijkstra
     * @param destIDS Vector with destination IDs
     * @return ID of nearest vertex of source of last calculated dijkstra path
     */
    int nearShortestDist(vector<int> destIDS);


    /**
     * @brief Nearest Neighbor algorithm, to calculate path with multiple clients destinations, starts and ends at stations
     * @param destIDS IDS od clients destinations
     * @param stationID Station ID, path begin and ends here
     * @return Vector with all visited vertexes in calculated path, ordered
     */
    vector<Vertex *> nearNeighborDij(vector<int> destIDS, int stationID);
};

/**
 * @brief Calculate eucliadian distance between two vertexes
 * @param src Pointer to initial vertex
 * @param dest Pointer to destination vertex
 * @return Distance between vertexes
 */
double euclidianDistance(Vertex* src, Vertex* dest);    //should i try other methods to calculate dist between vertexes?


/**
 * @brief Calculate manhattan distance between two vertexes
 * @param src Pointer to initial vertex
 * @param dest Pointer to destination vertex
 * @return Distance between vertexes
 */
double manhattanDistance(Vertex* src, Vertex* dest);


#endif //PROJ_2020_GRAPH_H
