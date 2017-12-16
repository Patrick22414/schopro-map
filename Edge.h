#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

class Vertex;
enum EdgeType { DRIVE, WALK };

class Edge
{
public:
	Edge();
	Edge(double xweight, EdgeType xedgetype);
	Edge(double xweight, EdgeType xedgetype, Vertex* xlink, Edge* xnextedge = NULL);
	~Edge();

	void display(/*TODO*/); // print all about this edge onto std::cout
	//TODO

	friend class Map;
private:
	double weight;
	EdgeType edgetype;
	Vertex* link;
	Edge* nextedge;
};

#endif // EDGE_H
