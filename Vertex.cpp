#include "Vertex.h"

Vertex::Vertex() {
  index = 0;
  data = "";
  nextvertex = NULL;
  nextedge = NULL;
}

Vertex::Vertex(int xindex, string xdata) {
  index = xindex;
  data = xdata;
  nextedge = NULL;
  nextvertex = NULL;
}

Vertex::Vertex(int xindex, string xdata, Vertex* xnextvertex, Edge* xnextedge) {
  index = xindex;
  data = xdata;
  nextedge = xnextedge;
  nextvertex = xnextvertex;
}

Vertex::~Vertex()
{
}
