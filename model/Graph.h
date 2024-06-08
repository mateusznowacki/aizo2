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
    void addEdge(int u, int v, int weight);
    int** getAdjMatrix();
    Node** getAdjList();
    int getVertices();
    void printAdjMatrix();
    void printAdjList();

private:

    int vertices; // Liczba wierzchołków
    int **adjMatrix; // Macierz sąsiedztwa
    Node **adjList; // Lista następników

};


#endif //AIZO2_GRAPH_H
