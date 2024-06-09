#ifndef AIZO2_ALGORITHMS_H
#define AIZO2_ALGORITHMS_H

#include "../model/Graph.h"
#include "../model/Graph.h"
#include <limits.h>

class Algorithms {
public:
    struct Edge {
        int src, dest, weight;
    };

    // Prim's algorithm using adjacency matrix
    void primMSTMatrix(Graph &graph);

    // Prim's algorithm using adjacency list
    void primMSTList(Graph &graph);

    // Kruskal's algorithm using adjacency matrix
    void kruskalMSTMatrix(Graph &graph);

    // Kruskal's algorithm using adjacency list
    void kruskalMSTList(Graph &graph);

    // Dijkstra's algorithm using adjacency matrix
    void dijkstraMatrix(Graph &graph, int src);

    // Dijkstra's algorithm using adjacency list
    void dijkstraList(Graph &graph, int src);

    // Bellman-Ford algorithm using adjacency matrix
    void bellmanFordMatrix(Graph &graph, int src);

    // Bellman-Ford algorithm using adjacency list
    void bellmanFordList(Graph &graph, int src);

    // Ford-Fulkerson algorithm using adjacency matrix
    void fordFulkersonMatrix(Graph &graph, int source, int sink);

    // Ford-Fulkerson algorithm using adjacency list
    void fordFulkersonList(Graph &graph, int source, int sink);

private:
    void printMST(int parent[], int n, int **graph);
    int minKey(int key[], bool mstSet[], int vertices);
    int find(int parent[], int i);
    void Union(int parent[], int rank[], int x, int y);
    bool bfs(int **rGraph, int s, int t, int parent[], int vertices);
};

#endif //AIZO2_ALGORITHMS_H
