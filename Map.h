#ifndef MAP_H
#define MAP_H

#include <string>

enum ErrMap { VERTEX_NOT_FOUND, EDGE_NOT_FOUND， MAP_UNDERFLOW };

class Map
{
public:
	Map();
	~Map();

	ErrMap addVertex(string vertexname);
	ErrMap addEdge(string v1_name, string v2_name, double weight);
	ErrMap addEdge(int v1_index, int v2_index, double weight);
	ErrMap addEdge(Vertex* v1, Vertex* v2, double weight);
private:
	ErrMap indexsearch(int id, Vertex*& v) {
		//TODO
		ans = head;
		for(int i=1; i<id; i++) {ans = ans->nextvertex;}
		return ans;
	}
	ErrMap namesearch(string xname) {
		//TODO
		ans = head;
		while(!xname.compare(ans->name)) {ans = ans->nextvertex;}
		return ans;
	}

	int nofedge;
	int nofvertex;
	Vertex* head;
};

#endif // MAP_H
