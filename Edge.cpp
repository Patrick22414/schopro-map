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

Edge::~Edge()
{
}
