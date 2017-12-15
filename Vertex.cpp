#include "Vertex.h"

Vertex::Vertex() {
  index = 0;
  name = "";
  nextvertex = NULL;
  nextedge = NULL;
}

Vertex::Vertex(int xindex, string xname) {
  index = xindex;
  name = xname;
  info = "";
  nextedge = NULL;
  nextvertex = NULL;
}

Vertex::Vertex(int xindex, string xname, Vertex* xnextvertex, Edge* xnextedge) {
  index = xindex;
  name = xname;
  nextedge = xnextedge;
  nextvertex = xnextvertex;
}

Vertex::~Vertex()
{
}
