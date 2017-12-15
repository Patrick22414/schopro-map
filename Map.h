#ifndef MAP_H
#define MAP_H

#include <string>

enum ErrMap { //TODO };

class Map
{
public:
	Map();
	~Map();

	ErrMap addVertex(string vertexdata);
	ErrMap addEdge(string v1_data, string v2_data, double weight);
	ErrMap addEdge(int v1_index, int v2_index, double weight);
	ErrMap addEdge(Vertex* v1, Vertex* v2, double weight);
private:
	Vertex* indexsearch(int id) {
		ans = head;
		for(int i=1; i<id; i++) {ans = ans->nextvertex;}
		return ans;
	}
	Vertex* datasearch(string xdata) {
		ans = head;
		while(!xdata.compare(ans->data)) {ans = ans->nextvertex;}
		return ans;
	}

	int nofedge;
	int nofvertex;
	Vertex* head;
};

#endif // MAP_H
