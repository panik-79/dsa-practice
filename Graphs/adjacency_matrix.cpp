#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;
    bool isDirected;

public:
    Graph(int vertices, bool directed = false) {
        numVertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
        isDirected = directed;
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] = 1;
        if (!isDirected) {
            adjMatrix[j][i] = 1;
        }
    }

    void removeEdge(int i, int j) {
        adjMatrix[i][j] = 0;
        if (!isDirected) {
            adjMatrix[j][i] = 0;
        }
    }

    void display() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;

    // Create an undirected graph
    Graph undirectedGraph(vertices, false);

    // Adding edges
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 4);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(1, 3);
    undirectedGraph.addEdge(1, 4);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(3, 4);

    cout << "Adjacency Matrix of the undirected graph:" << endl;
    undirectedGraph.display();

    // Create a directed graph
    Graph directedGraph(vertices, true);

    // Adding edges
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 4);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(1, 3);
    directedGraph.addEdge(1, 4);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 4);

    cout << "\nAdjacency Matrix of the directed graph:" << endl;
    directedGraph.display();

    return 0;
}