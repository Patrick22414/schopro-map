#include "Edge.h"
#include "Vertex.h"

using namespace std;

Edge::Edge() {
  weight = -1;
  edgetype = WALK;
  link = NULL;
  nextedge = NULL;
}

Edge::Edge(double xweight, EdgeType xedgetype) {
  weight = xweight;
  edgetype = xedgetype;
  link = NULL;
  nextedge = NULL;
}

Edge::Edge(double xweight, EdgeType xedgetype, Vertex* xlink, Edge* xnextedge) {
  weight = xweight;
  edgetype = xedgetype;
  link = xlink;
  nextedge = xnextedge;
}

Edge::~Edge()
{
}
