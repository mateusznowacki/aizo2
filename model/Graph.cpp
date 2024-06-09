#include "Graph.h"
#include <iostream>

// Konstruktor z listą inicjalizacyjną
Graph::Graph(int vertices) : vertices(vertices) {

    // Alokowanie pamięci dla macierzy sąsiedztwa dla grafu nieskierowanego
    adjMatrix = new int *[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j) {
            adjMatrix[i][j] = 0; // Brak krawędzi oznaczamy jako 0
        }
    }

    // Alokowanie pamięci dla listy następników dla grafu nieskierowanego
    adjList = new Node *[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjList[i] = nullptr;
    }


}

// Destruktor
Graph::~Graph() {

    // Zwolnienie pamięci dla macierzy i listy grafu
    for (int i = 0; i < vertices; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    for (int i = 0; i < vertices; ++i) {
        Node *head = adjList[i];
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    delete[] adjList;

}

// Dodawanie krawędzi skierowanej
void Graph::addDirEdge(int u, int v, int weight) {
    std::cout << "Adding directed edge: " << u << " -> " << v << " with weight " << weight << std::endl;
    adjMatrix[u][v] = weight;

    Node *newNode = new Node;
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Dodawanie krawędzi nieskierowanej
void Graph::addUnDirEdge(int u, int v, int weight) {
    std::cout << "Adding undirected edge: " << u << " <-> " << v << " with weight " << weight << std::endl;
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;

    Node *newNode = new Node;
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = new Node;
    newNode->vertex = u;
    newNode->weight = weight;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// Pobieranie macierzy sąsiedztwa
int **Graph::getAdjMatrix() {
    return adjMatrix;
}

// Pobieranie listy następników dla grafu skierowanego
Graph::Node **Graph::getAdjList() {
    return adjList;
}

// Pobieranie liczby wierzchołków dla grafu skierowanego
int Graph::getVertices() {
    return vertices;
}




