#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

class Edge
{
public:
	Edge();
	Edge(double xweight);
	Edge(double xweight, Vertex* xlink, Edge* xnextedge = NULL);

	~Edge();

	friend class Map;
private:
	double weight;
	Vertex* link;
	Edge* nextedge;
};

#endif // EDGE_H
