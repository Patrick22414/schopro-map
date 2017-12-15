#include "Map.h"

Map::Map() {
  nofedge = 0;
  nofvertex = 0;
  head = NULL;
}
ErrMap Vertex::addVertex(string vertexname) {
  tail = indexsearch(nofvertex);
  nofvertex ++;
  newvertex = new Vertex(nofvertex, name);
  tail->nextvertex = newvertex;
}

ErrMap addEdge(string v1_name, string v2_name, double weight) {
  Vertex* v1 = namesearch(v1_name);
  Vertex* v2 = namesearch(v2_name);
  addEdge(v1, v2, weight);
}

ErrMap addEdge(int v1_index, int v2_index, double weight) {
  Vertex* v1 = indexsearch(v1_index);
  Vertex* v2 = indexsearch(v2_index);
  addEdge(v1, v2, weight);
}

ErrMap addEdge(Vertex* v1, Vertex* v2, double weight) {
  newedge1 = new Edge(weight, v2);
  newedge2 = new Edge(weight, v1);
  v1_edge = v1->nextedge;
  v2_edge = v2->nextedge;
  while(v1_edge!=NULL) {v1_edge = v1_edge->nextedge;}
  while(v2_edge!=NULL) {v2_edge = v2_edge->nextedge;}
  v1_edge->nextedge = newedge1;
  v2_edge->nextedge = newedge2;
  nofedge ++;
}

Map::~Map()
{
}
