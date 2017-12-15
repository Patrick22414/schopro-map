#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"

class Vertex
//------------------------------------------------------------------------------
// In this project, Vertex class is used to represent a tourist site of our
//   university.
// "index" is a codename of the site, assigned by the Map class
//   upon constructing and starting from 1, and is the main reference key to the
//   site. Default (invalid) value is 0.
// "name" is the name of the site, also the
{
public:
	Vertex();
	Vertex(int xindex, string xname);
	Vertex(int xindex, string xname, Vertex* xnextvertex, Edge* xnextedge);
	~Vertex();

	friend class Map;
private:
	int index;
	string name; // name of the site
	string info; // a short information about the tourist site
	Vertex* nextvertex;
	Edge* nextedge;
};

#endif // VERTEX_H
