#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"

using namespace std;

enum ErrMap { MAP_SUCCESS, VERTEX_NOT_FOUND, EDGE_NOT_FOUND, MAP_UNDERFLOW, MAP_OVERFLOW };

class Map
{
public:
// con/destructors
	Map();
	~Map();
// getters
	int countVertices() {return nofvertex;}
	int countEdges() {return nofedge;}
// convertors
	string index2name(int xindex);
	int name2index(string xname);
// generataion methods
	ErrMap addVertex(string vertexname);
	ErrMap addEdge(string v1_name, string v2_name, double weight);
	ErrMap addEdge(int v1_index, int v2_index, double weight);
	ErrMap addEdge(Vertex* v1, Vertex* v2, double weight);
// deletion methods
	ErrMap deleteVertex(/*TODO*/); // delete a vertex and all edges linked to it
	ErrMap deleteEdge(/*TODO*/); // delete an edge
// general methods
	vector<int> shortest(/*TODO*/); // calculate the shortest path between two vertices and store the path in a std::vector
	Vertex operator[](int xindex/*TODO*/); // overloaded operator [] to get a copy of a vertex
	//TODO
private:
	ErrMap indexsearch(int id, Vertex*& v);
	ErrMap namesearch(string xname, Vertex*& v);

	int nofedge;
	int nofvertex;
	Vertex* head;
};

#endif // MAP_H
