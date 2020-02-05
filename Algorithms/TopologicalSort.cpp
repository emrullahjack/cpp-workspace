// Topological sorting of a directed acyclic graph (DAG)

#include <iostream>
#include <list>
#include <stack>

using namespace std;

// A class to represent graph
class Graph {
    int V;      // Number of vertices
    list<int> *adj;     // Pointer to an array containing adjacency lists

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); // A utility function used by topologicalSort

    public:
        Graph(int v);   // Constructor

        void addEdge(int v, int w);     // Function to add an edge to the graph
        void topologicalSort();     // Prints a topological sort of the complete graph
};

Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true; // Mark the current node as visited.

    // Recur for all the vertices adjacent to this vertex.
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    Stack.push(v);
}

void Graph::topologicalSort() {
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological Sort
    // starting from all the vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main(int argc, char const *argv[]) {

    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a topological sort of the given graph \n";
    g.topologicalSort();
    cout << "\n";

    return 0;
}
