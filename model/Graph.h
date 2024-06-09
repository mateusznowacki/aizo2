#ifndef AIZO2_GRAPH_H
#define AIZO2_GRAPH_H


#include <iostream>

class Graph {

public:
    struct Node {
        int vertex;
        int weight;
        Node* next;
    };
    Graph(int vertices);
    ~Graph();
    void addDirEdge(int u, int v, int weight);
    void addUnDirEdge(int u, int v, int weight);
    int** getAdjMatrix();
    Node** getAdjList();
    int getVertices();
    int getDensity();
    int *getTwoDifferentVertices();

private:
    int density;
    int vertices; // Liczba wierzchołków
    int **adjMatrix; // Macierz sąsiedztwa
    Node **adjList; // Lista następników

};


#endif //AIZO2_GRAPH_H
