#include <iostream>
#include <limits.h>
#include <list>
#include <stack>
#define NINF INT_MIN
using namespace std;

// Graph is represented using adjacency list.

class AdjListNode {
  int v;
  int weight;

public:
  AdjListNode(int v, int weight) {
    this->v = v;
    this->weight = weight;
  }
};

class Graph {
  int V;

  list<AdjListNode>* adj;

  void topologicalSortUntil(int v, bool visited[], stack<int>& Stack);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
