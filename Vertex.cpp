#include "Vertex.h"
#include "Edge.h"

using namespace std;

Vertex::Vertex() {
  index = 0;
  name = "";
  info = "";
  nextvertex = NULL;
  nextedge = NULL;
}

Vertex::Vertex(int xindex, string xname) {
  index = xindex;
  name = xname;
  info = "no information";
  nextedge = NULL;
  nextvertex = NULL;
}

Vertex::Vertex(int xindex, string xname, string xinfo){
    index = xindex;
    name = xname;
    info = xinfo;
    nextedge = NULL;
    nextvertex = NULL;
}

Vertex::Vertex(int xindex, string xname, string xinfo, Vertex* xnextvertex, Edge* xnextedge) {
  index = xindex;
  name = xname;
  info = xinfo;
  nextedge = xnextedge;
  nextvertex = xnextvertex;
}

Vertex::~Vertex()
{
}

void Vertex::vdisplay(){
    // display infos about this vertex
    cout << endl;
    cout << "index = " << index << endl;
    cout << "name = "  << name  << endl;
    cout << "info = "  << info  << endl;
    cout << endl;
}