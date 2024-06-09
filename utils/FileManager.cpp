
#include "FileManager.h"
#include "../model/Graph.h"
#include <fstream>
#include <iostream>

Graph *FileManager::loadGraphFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
        return nullptr;
    }
    int edges, vertices;
    file >> edges >> vertices;

    Graph *graph = new Graph(vertices);
    int u, v, weight;
    while (file >> u >> v >> weight) {
        graph->addDirEdge(u, v, weight);
    }

    file.close();
    return graph;
}
