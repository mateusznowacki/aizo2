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
    void primMSTMatrix(Graph graph);
    void primMSTList(Graph graph);
    void kruskalMSTMatrix(Graph graph);
    void kruskalMSTList(Graph graph);
    void dijkstraMatrix(Graph graph, int src, int dest);
    void dijkstraList(Graph graph, int src, int dest);
    void bellmanFordMatrix(Graph graph, int src, int dest);
    void bellmanFordList(Graph graph, int src, int dest);
    void fordFulkersonMatrix(Graph graph, int source, int sink);
    void fordFulkersonList(Graph graph, int source, int sink);

private:
    int minKey(int key[], bool mstSet[], int vertices);
    void printMST(int parent[], int n, int **graph);
    bool bfs(int **rGraph, int s, int t, int parent[], int vertices);
    int find(int parent[], int i);
    void Union(int parent[], int rank[], int x, int y);
};

#endif //AIZO2_ALGORITHMS_H
