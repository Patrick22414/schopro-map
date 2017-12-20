#include <iostream>
#include <algorithm>
#include <cfloat>
#include <vector>
#include "Map.h"

using namespace std;

const int INFINITY = DBL_MAX;

template< typename T >
void iniArr(T* arr, int n, T ini) {
  for (int i=0; i<n; i++) {
    arr[i] = ini;
  }
}

bool allDone(bool visited[], int n) {
  bool flag = true;
  for (int i=0; i<n; i++) {
    if (!visited[i]) {
      flag = false;
    }
  }
  return flag;
}

vector< int > Map::pathfinder(int v1, int v2, double& dist) {
  Vertex* source = NULL;
  ErrMap flag = indexsearch(v1, source);
  if (flag != MAP_SUCCESS) {
    cerr << "Map::pathfinder failed! : Unable to find vertex." << endl;
  }

  if (prev_matrix[v1][0]==0 || dist_matrix[v1][0]!=1) {
    Dijkstra(source);
  }

  vector< int > path(nofvertex, 0);
  path[0] = v2;
  int i = 1;
  while (prev_matrix[v1][path[i-1]] != v1) {
    path[i] = prev_matrix[v1][path[i-1]];
    i ++;
  }
  path[i] = v1;
  path.resize(i+1);
  reverse(path.begin(), path.end());
  dist = dist_matrix[v1][v2];  
  return path;
}

vector< int > Map::pathfinder(string v1, string v2, double& dist) {
  return pathfinder(name2index(v1), name2index(v2), dist);
}

void Map::pathprinter(vector< int > path) {
  Vertex* v = NULL;
  for (unsigned i=0; i<path.size(); i++) {
    indexsearch(path[i], v);
    v->display_short();
  }
}

void Map::Dijkstra(Vertex* source) {
  bool visited[nofvertex];
  vector< double > distance(nofvertex+1, INFINITY);
  vector< int > previous(nofvertex+1, 0);
  iniArr< bool >(visited, nofvertex, false);

  distance[source->index] = 0.0;

  Vertex* curV = source;
  Edge* curE = source->nextedge;
  double alt = 0.0;

  while (!allDone(visited, nofvertex)) {
    double min = INFINITY;
    for (int i=1; i<=nofvertex; i++) {
      if (! visited[i-1] && distance[i] < min) {
        indexsearch(i, curV);
        min = distance[i];
      }
    }

    visited[curV->index - 1] = true;
    curE = curV->nextedge;

    while (curE != NULL) {
      if (!visited[curE->link->index - 1]) {
        alt = distance[curV->index] + curE->weight;
        if (alt < distance[curE->link->index]) {
          previous[curE->link->index] = curV->index;
          distance[curE->link->index] = alt;
        }
      }
      curE = curE->nextedge;
    }
  }

  previous[0] = 1;
  prev_matrix[source->index] = previous;
  distance[0] = 1;
  dist_matrix[source->index] = distance;
}

void Map::matrix_extend() {
  prev_matrix.resize(nofvertex+1);
  for (int i=0; i<=nofvertex; i++) {
    prev_matrix[i].resize(nofvertex+1, 0);
  }
  dist_matrix.resize(nofvertex+1);
  for (int i=0; i<=nofvertex; i++) {
    dist_matrix[i].resize(nofvertex+1, INFINITY);
  }
}
