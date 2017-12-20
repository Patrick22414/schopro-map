#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include "Edge.h"

using namespace std;

class Vertex
//------------------------------------------------------------------------------
// In this project, Vertex class is used to represent a tourist site of our
//   university.
// "index" is a codename of the site, assigned by the Map class
//   upon constructing and starting from 1, and is the prime key to the site.
//   Default (invalid) value is 0.
// "name" is the name of the site, also the secondary key to the site. Default
//   value is "";
{
public:
	Vertex();
	Vertex(int xindex, string xname);
    Vertex(int xindex, string xname, string xinfo);
	Vertex(int xindex, string xname, string xinfo, Vertex* xnextvertex, Edge* xnextedge);
	~Vertex();

	void display(); // print all about this vertex onto std::cout
	void display_short();
	friend class Map;
private:
	int index;
	string name;
	string info; // a short information about the tourist site
	Vertex* nextvertex;
	Edge* nextedge;
};

#endif // VERTEX_H
