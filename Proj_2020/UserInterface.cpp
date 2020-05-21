#include "UserInterface.h"
/*
GraphViewer* creategraphViewer(const Graph* graph){
    GraphViewer* gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
    gv->defineEdgeCurved(false);
    for (Vertex* vertex : graph->getVertexSet()) {
        gv->addNode(vertex->getID(), (int) vertex->getX() - 527500, (int) vertex->getY() - 4555555);

        for (Vertex *vertex : graph->getVertexSet()) {
            for (Edge *edge : vertex->getAdj()) {
                gv->addEdge(edge->getID(), vertex->getID(), edge->getDest()->getID(), EdgeType::UNDIRECTED);
                gv->setEdgeWeight(edge->getID(), (int) edge->getWeight());
            }
        }
    }
    gv->rearrange();
    return gv;
}*/