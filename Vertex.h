#ifndef VERTEX_H
#define VERTEX_H

#include "Edge.h"

class Vertex
{
public:
	Vertex();
	Vertex(int xindex, string xdata);
	Vertex(int xindex, string xdata, Vertex* xnextvertex, Edge* xnextedge);
	~Vertex();

	friend class Map;
private:
	int index;
	string data;
	Vertex* nextvertex;
	Edge* nextedge;
};

#endif // VERTEX_H
