#include "Edge.h"
#include "Vertex.h"

using namespace std;

Edge::Edge() {
  weight = -1;
  edgetype = "WALK";
  link = NULL;
  nextedge = NULL;
}

Edge::Edge(double xweight, string xedgetype) {
  weight = xweight;
  edgetype = xedgetype;
  link = NULL;
  nextedge = NULL;
}

Edge::Edge(double xweight, string xedgetype, Vertex* xlink, Edge* xnextedge) {
  weight = xweight;
  edgetype = xedgetype;
  link = xlink;
  nextedge = xnextedge;
}

void Edge::display() {
    // display infos about this edge
    cout << endl;
    cout << "---Edge---" << endl;
    cout << "weight = "  << weight  << endl;
    cout << "edge type = "  << edgetype  << endl;
    cout << "link to =>";
    if (link != NULL) {
      link->display_short();
    }else {
      cout << " no vertex" << endl;
      cout << endl;
    }
}

Edge::~Edge()
{
}
