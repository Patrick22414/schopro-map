#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

class Vertex;

class Edge
{
public:
	Edge();
	Edge(double xweight, string xedgetype);
	Edge(double xweight, string xedgetype, Vertex* xlink, Edge* xnextedge = NULL);
	~Edge();

	void display(/*TODO*/); // print all about this edge onto std::cout
	//TODO

	friend class Map;
private:
	double weight;
	string edgetype;
	Vertex* link;
	Edge* nextedge;
};

#endif // EDGE_H
