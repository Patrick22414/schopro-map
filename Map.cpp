#include "Map.h"

using namespace std;

Map::Map() {
  nofedge = 0;
  nofvertex = 0;
  head = NULL;
}

string Map::index2name(int xindex) {
  Vertex* v = NULL;
  ErrMap flag = indexsearch(xindex, v);
  if (flag != MAP_SUCCESS) {
    return "";
  }
  return v->name;
}
int Map::name2index(string xname) {
  Vertex* v = NULL;
  ErrMap flag = namesearch(xname, v);
  if (flag != MAP_SUCCESS) {
    return 0;
  }
  return v->index;
}

ErrMap Map::addVertex(string vertexname, string info) {
// Add a vertex at the end of list
  Vertex* newvertex = new Vertex(nofvertex+1, vertexname, info);
  if (head == NULL) {
    head = newvertex;
  }else {
    Vertex* tail = NULL;
    ErrMap flag = indexsearch(nofvertex, tail);
    if (flag != MAP_SUCCESS) {
      return flag;
    }
    tail->nextvertex = newvertex;
  }
  nofvertex ++;
  return MAP_SUCCESS;
}

ErrMap Map::addEdge(string v1_name, string v2_name, double weight, string xedgetype) {
// Add an edge between two name-referred vertices.
// Will invoke ADDEDGE(V1, V2, WEIGHT) to perform the action.
  Vertex* v1 = NULL;
  ErrMap flag = namesearch(v1_name, v1);
  if (flag != MAP_SUCCESS) {
    return flag;
  }
  Vertex* v2 = NULL;
  flag = namesearch(v2_name, v2);
  if (flag != MAP_SUCCESS) {
    return flag;
  }
  return addEdge(v1, v2, weight, xedgetype);
}

ErrMap Map::addEdge(int v1_index, int v2_index, double weight, string xedgetype) {
// Add an edge between two index-referred vertices.
// Will invoke ADDEDGE(V1, V2, WEIGHT) to perform the action.
  Vertex* v1 = NULL;
  ErrMap flag = indexsearch(v1_index, v1);
  if (flag != MAP_SUCCESS) {
    return flag;
  }
  Vertex* v2 = NULL;
  flag = indexsearch(v2_index, v2);
  if (flag != MAP_SUCCESS) {
    return flag;
  }
  return addEdge(v1, v2, weight, xedgetype);
}

ErrMap Map::addEdge(Vertex* v1, Vertex* v2, double weight, string xedgetype) {
// Add an edge between two vertices using their pointers.
  Edge* newedge1 = new Edge(weight, xedgetype, v2);
  Edge* v1_edge = v1->nextedge;
  if (v1_edge != NULL) {
    while (v1_edge->nextedge != NULL) {
      v1_edge = v1_edge->nextedge;
    }
    v1_edge->nextedge = newedge1;
  }else {
    v1->nextedge = newedge1;
  }

  Edge* newedge2 = new Edge(weight, xedgetype, v1);
  Edge* v2_edge = v2->nextedge;
  if (v2_edge != NULL) {
    while (v2_edge->nextedge != NULL) {
      v2_edge = v2_edge->nextedge;
    }
    v2_edge->nextedge = newedge2;
  }else {
    v2->nextedge = newedge2;
  }

  nofedge ++;
  return MAP_SUCCESS;
}

Map::~Map()
{
}

string Map::getInfo(string vertexname) {
  Vertex* v = NULL;
  ErrMap flag = namesearch(vertexname, v);
  if (flag != MAP_SUCCESS) {
    return "No information available.";
  }
  return v->info;
}

void Map::display(){
    //display infos about map
    Vertex* v = head;
    for(int i = 1; i <= nofvertex; i++)
    {
        v->display();
        v = v->nextvertex;
    }
}

// Private methods of class Map below

ErrMap Map::indexsearch(int id, Vertex*& v) {
//------------------------------------------------------------------------------
// Pre: An int "id" sepcifying the index of which vertex to search for. An
//      Vertex pointer "v" as reference parameter.
//--- INDEXSEARCH searchs the vertex of index "id" and stores its address in the
//    reference parameter "v". Error codes are returned when "id" is invalid.
// Post: An error code of type ErrMap was returned. An address stored in the
//       reference.
//------------------------------------------------------------------------------
	if (id <= 0) {
		return MAP_UNDERFLOW;
	}else if (id > nofvertex) {
		return MAP_OVERFLOW;
	}
	v = head;
	for(int i=1; i<id; i++) {
		v = v->nextvertex;
	}
	return MAP_SUCCESS;
}

ErrMap Map::namesearch(string xname, Vertex*& v) {
//------------------------------------------------------------------------------
// Pre: A string "xname" sepcifying the name of which vertex to search for. An
//      Vertex pointer "v" as reference parameter.
//--- NAMESEARCH searchs the vertex of name "xname" and stores its address in
//    the reference parameter "v". Error codes are returned when "xname" is not
//    a name of existing vertices.
// Post: An error code of type ErrMap was returned. An address stored in the
//       reference.
//------------------------------------------------------------------------------
	v = head;
	while ((v!=NULL) && (xname!=v->name)) {
		v = v->nextvertex;
	}
	if (v == NULL) {
		return VERTEX_NOT_FOUND;
	}
	return MAP_SUCCESS;
}
