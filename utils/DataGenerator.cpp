#include <ctime>
#include "DataGenerator.h"

#include <iostream>
#include <random>


Graph* DataGenerator::generateRandomDirGraph(int vertexCount, int density) {
        Graph* graph = new Graph(vertexCount);

        // Use a random device and Mersenne Twister engine for better randomness
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 2000);

        // Generating a minimum spanning tree (MST)
        for (int i = 0; i < vertexCount - 1; ++i) {
            int weight = dist(gen); // Edge weight is a positive integer
            graph->addDirEdge(i, i + 1, weight);
        }

        // Calculating the number of edges to add to achieve the desired density
        int maxEdges = vertexCount * (vertexCount - 1); // For a directed graph
        int mstEdges = vertexCount - 1;
        int edgesToAdd = static_cast<int>(maxEdges * (density / 100.0)) - mstEdges;

        // Adding remaining edges to achieve the required density
        std::uniform_int_distribution<> vertexDist(0, vertexCount - 1);
        while (edgesToAdd > 0) {
            int u = vertexDist(gen);
            int v = vertexDist(gen);
            if (u != v && graph->getAdjMatrix()[u][v] == 0) {
                int weight = dist(gen);
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




