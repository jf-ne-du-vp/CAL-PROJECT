#include "UserInterface.h"

GraphViewer* creategraphViewer(const Graph* graph){
    auto* gv = new GraphViewer(900, 900, false);
    gv->createWindow(900, 900);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("grey");
    gv->defineEdgeCurved(false);
    for (Vertex* vertex : graph->getVertexSet()){
        gv->addNode(vertex->getID(), (int) vertex->getX() +15 , (int) vertex->getY() +15);
    }

    for(Vertex* vertex : graph->getVertexSet()){
        for(Edge* edge : vertex->getAdj()){
            gv->addEdge(edge->getID(), vertex->getID(), edge->getDest()->getID(), EdgeType::DIRECTED);
            gv->setEdgeWeight(edge->getID(), (int)edge->getWeight());
        }
    }
    gv->rearrange();

    return gv;
}