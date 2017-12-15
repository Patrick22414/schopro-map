#include "Edge.h"
#include "Vertex.h"

using namespace std;

Edge::Edge() {
  weight = -1;
  link = NULL;
  nextedge = NULL;
}

Edge::Edge(double xweight) {
  weight = xweight;
  link = NULL;
  nextedge = NULL;
}

Edge::Edge(double xweight, Vertex* xlink, Edge* xnextedge) {
  weight = xweight;
  link = xlink;
  nextedge = xnextedge;
}

Edge::~Edge()
{
}
