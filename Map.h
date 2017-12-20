#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

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
	ErrMap addVertex(string vertexname, string info);
	ErrMap addEdge(string v1_name, string v2_name, double weight, string xedgetype);
	ErrMap addEdge(int v1_index, int v2_index, double weight, string xedgetype);
	ErrMap addEdge(Vertex* v1, Vertex* v2, double weight, string xedgetype);
// general methods
	vector< int > pathfinder(int v1, int v2, double& dist);
	vector< int > pathfinder(string v1, string v2, double& dist);
	void pathprinter(vector< int > path);
	string getInfo(string vertexname);
// display methods
	void display();
private:
	ErrMap indexsearch(int id, Vertex*& v);
	ErrMap namesearch(string xname, Vertex*& v);
	void Dijkstra(Vertex* source);
	void matrix_extend();

	int nofedge;
	int nofvertex;
	vector< vector< int > > prev_matrix;
	vector< vector< double > > dist_matrix;
	Vertex* head;
};

#endif // MAP_H
