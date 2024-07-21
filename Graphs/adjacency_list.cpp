#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList; // Each pair contains a vertex and the weight of the edge
    bool isDirected;

public:
    Graph(int vertices, bool directed = false) {
        numVertices = vertices;
        adjList.resize(vertices);
        isDirected = directed;
    }

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(make_pair(dest, weight));
        if (!isDirected) {
            adjList[dest].push_back(make_pair(src, weight));
        }
    }

    void display() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ":";
            for (auto edge : adjList[i]) {
                cout << " -> (" << edge.first << ", " << edge.second << ")";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;

    // Create an undirected graph
    Graph undirectedGraph(vertices, false);

    // Adding edges with weights
    undirectedGraph.addEdge(0, 1, 10);
    undirectedGraph.addEdge(0, 4, 20);
    undirectedGraph.addEdge(1, 2, 30);
    undirectedGraph.addEdge(1, 3, 40);
    undirectedGraph.addEdge(1, 4, 50);
    undirectedGraph.addEdge(2, 3, 60);
    undirectedGraph.addEdge(3, 4, 70);

    cout << "Adjacency List of the undirected graph:" << endl;
    undirectedGraph.display();

    // Create a directed graph
    Graph directedGraph(vertices, true);

    // Adding edges with weights
    directedGraph.addEdge(0, 1, 10);
    directedGraph.addEdge(0, 4, 20);
    directedGraph.addEdge(1, 2, 30);
    directedGraph.addEdge(1, 3, 40);
    directedGraph.addEdge(1, 4, 50);
    directedGraph.addEdge(2, 3, 60);
    directedGraph.addEdge(3, 4, 70);

    cout << "\nAdjacency List of the directed graph:" << endl;
    directedGraph.display();

    return 0;
}