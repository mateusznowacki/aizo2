#include <ctime>
#include "DataGenerator.h"

#include <iostream>



Graph* DataGenerator::generateRandomDirGraph(int vertexCount, int density) {
    Graph* graph = new Graph(vertexCount);

    // Inicjalizacja generatora liczb losowych
    std::srand(std::time(0));

    // Generowanie minimalnego drzewa rozpinającego (MST)
    for (int i = 0; i < vertexCount - 1; ++i) {
        int weight = std::rand() % 100 + 1; // Przepustowość/koszt krawędzi jest liczbą całkowitą (dodatnią)
        graph->addDirEdge(i, i + 1, weight);
    }

    // Obliczanie liczby krawędzi do osiągnięcia pożądanej gęstości
    int maxEdges = vertexCount * (vertexCount - 1); // Dla grafu skierowanego
    int edgesToAdd = maxEdges * (density / 100.0) - (vertexCount - 1);

    // Dodawanie pozostałych krawędzi do osiągnięcia wymaganej gęstości
    while (edgesToAdd > 0) {
        int u = std::rand() % vertexCount;
        int v = std::rand() % vertexCount;
        if (u != v && graph->getAdjMatrix()[u][v] == 0) {
            int weight = std::rand() % 100 + 1;
            graph->addDirEdge(u, v, weight);
            --edgesToAdd;
        }
    }

    return graph;
}

Graph *DataGenerator::generateUnDirGraph(Graph *dirGraph) {
    int vertices = dirGraph->getVertices();
    Graph* unDirGraph = new Graph(vertices);

    for (int i = 0; i < vertices; ++i) {
        Graph::Node* node = dirGraph->getAdjList()[i];
        while (node != nullptr) {
            // Dodawanie krawędzi w obu kierunkach
            unDirGraph->addUnDirEdge(i, node->vertex, node->weight);
            node = node->next;
        }
    }

    return unDirGraph;
}




