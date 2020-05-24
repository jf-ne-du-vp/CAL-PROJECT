#include "UserInterface.h"


GraphViewer* creategraphViewer(const Graph* graph){
    auto* gv = new GraphViewer(1200, 1000, false);
    gv->createWindow(1200, 1000);
    gv->defineVertexColor("Yellow");
    gv->defineEdgeColor("BLACK");
    gv->defineEdgeCurved(false);
    for (Vertex* vertex : graph->getVertexSet()){
        gv->addNode(vertex->getID(), (int) vertex->getX() , (int) vertex->getY());
        gv->setVertexLabel(vertex->getID(), to_string(vertex->getID()));
    }

    for(Vertex* vertex : graph->getVertexSet()){
        for(Edge* edge : vertex->getAdj()){
            gv->addEdge(edge->getID(), vertex->getID(), edge->getDest()->getID(), EdgeType::DIRECTED);
            //gv->setEdgeWeight(edge->getID(), (int)edge->getWeight());
        }
    }
    gv->rearrange();

    return gv;
}


void showPathInGraph(GraphViewer* gv, const vector<Vertex*>& path){
    for (int i = 0; i < path.size() - 1; i++) {
        gv->setVertexColor(path[i]->getID(), RED);
        for (Edge* e : path[i]->getAdj()) {
            if (e->getDest() == path[i + 1]) {
                gv->setEdgeColor(e->getID(), RED);
                break;
            }
        }
    }
    if (path.size() == 0)
        return;
    gv->setVertexColor(path[0]->getID(), BLACK);
    if (path.size() == 1)
        return;
    gv->setVertexColor(path[path.size() - 1]->getID(), GREEN);
    gv->rearrange();
}

void resetGraph(GraphViewer* gv, const Graph* graph){
    for(auto v : graph->getVertexSet()){
        gv->setVertexColor(v->getID(), YELLOW);
    }
}