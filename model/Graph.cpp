#include "Graph.h"

// Konstruktor
Graph::Graph(int vertices) : vertices(vertices) {
    // Alokowanie pamięci dla macierzy sąsiedztwa
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j) {
            adjMatrix[i][j] = 0; // Brak krawędzi oznaczamy jako 0
        }
    }

    // Alokowanie pamięci dla listy następników
    adjList = new Node*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjList[i] = nullptr;
    }
}

// Destruktor
Graph::~Graph() {
    for (int i = 0; i < vertices; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    for (int i = 0; i < vertices; ++i) {
        Node* head = adjList[i];
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    delete[] adjList;
}

// Dodawanie krawędzi
void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;

    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Pobieranie macierzy sąsiedztwa
int** Graph::getAdjMatrix() {
    return adjMatrix;
}

// Pobieranie listy następników
Graph::Node** Graph::getAdjList() {
    return adjList;
}

// Pobieranie liczby wierzchołków
int Graph::getVertices() {
    return vertices;
}

