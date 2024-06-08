#include <ctime>
#include "DataGenerator.h"

Graph* DataGenerator::generateRandomGraph(int vertices, int density) {
    Graph* graph = new Graph(vertices);

    // Inicjalizacja generatora liczb losowych
    std::srand(std:: time(0));

    // Generowanie minimalnego drzewa rozpinającego (MST)
    for (int i = 0; i < vertices - 1; ++i) {
        int weight = std::rand() % 100 + 1; // Przepustowość/koszt krawędzi jest liczbą całkowitą (dodatnią)
        graph->addEdge(i, i + 1, weight);
        graph->addEdge(i + 1, i, weight); // Krawędź nieskierowana
    }

    // Obliczanie liczby krawędzi do osiągnięcia pożądanej gęstości
    int maxEdges = vertices * (vertices - 1) / 2;
    int edgesToAdd = maxEdges * (density/100) - (vertices - 1);

    // Dodawanie pozostałych krawędzi do osiągnięcia wymaganej gęstości
    while (edgesToAdd > 0) {
        int u = std::rand() % vertices;
        int v = std::rand() % vertices;
        if (u != v && graph->getAdjMatrix()[u][v] == 0) {
            int weight = std::rand() % 100 + 1;
            graph->addEdge(u, v, weight);
            graph->addEdge(v, u, weight); // Krawędź nieskierowana
            --edgesToAdd;
        }
    }

    return graph;
}
