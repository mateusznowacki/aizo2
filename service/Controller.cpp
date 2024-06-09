#include "Controller.h"
#include "../utils/ConsoleManager.h"
#include "../utils/DataGenerator.h"
#include "../utils/FileManager.h"
#include "Algorithms.h"


ConsoleManager console; // Utworzenie obiektu console klasy ConsoleManager
DataGenerator dataGenerator; // Utworzenie obiektu dataGenerator klasy DataGenerator
FileManager fileManag; // Utworzenie obiektu fileManager klasy FileManager
Algorithms algorithms; // Utworzenie obiektu algorithms klasy Algorithms



void Controller::generateGraphsToFile() {
    int vertices = console.printGetVertexCount();
    int density = console.printGetDensity();
    string filename = console.printGetFilename();

    Graph *dirGraph = dataGenerator.generateRandomDirGraph(vertices, density);
    fileManag.saveGraphToFile(dirGraph, filename);
}

std::chrono::microseconds Controller::runGraphAlgorithm(int algorithmType, int vertexCount, int density, int reprezentationType) {
    Graph *dirGraph = dataGenerator.generateRandomDirGraph(vertexCount, density);
    Graph *unDirGraph = dataGenerator.generateUnDirGraph(dirGraph);

    chrono::high_resolution_clock::time_point start, end;

    switch (reprezentationType) {
        case 1: { //matrix
            switch (algorithmType) {
                case 1: {
                    start = chrono::high_resolution_clock::now();
                    algorithms.primMSTMatrix(*unDirGraph);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
                case 2: {
                    start = chrono::high_resolution_clock::now();
                    algorithms.kruskalMSTMatrix(*unDirGraph);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
                case 3: {
                    int *vertices = dirGraph->getTwoDifferentVertices();
                    start = chrono::high_resolution_clock::now();
                    algorithms.dijkstraMatrix(*dirGraph, vertices[0], vertices[1]);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
                case 4: {
                    int *vertices = dirGraph->getTwoDifferentVertices();
                    start = chrono::high_resolution_clock::now();
                    algorithms.bellmanFordMatrix(*dirGraph, vertices[0], vertices[1]);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
                case 5: {
                    int *vertices = dirGraph->getTwoDifferentVertices();
                    start = chrono::high_resolution_clock::now();
                    algorithms.fordFulkersonMatrix(*dirGraph, vertices[0], vertices[1]);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
            }

            chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
            return duration; // Zwróć czas trwania sortowania
        }
        case 2: { //list

            switch (algorithmType) {
                case 1: {
                    start = chrono::high_resolution_clock::now();
                    algorithms.primMSTList(*unDirGraph);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
                case 2: {
                    start = chrono::high_resolution_clock::now();
                    algorithms.kruskalMSTList(*unDirGraph);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
                case 3: {
                    int *vertices = dirGraph->getTwoDifferentVertices();
                    start = chrono::high_resolution_clock::now();
                    algorithms.dijkstraList(*dirGraph, vertices[0], vertices[1]);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
                case 4: {
                    int *vertices = dirGraph->getTwoDifferentVertices();
                    start = chrono::high_resolution_clock::now();
                    algorithms.bellmanFordList(*dirGraph, vertices[0], vertices[1]);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
                case 5: {
                    int *vertices = dirGraph->getTwoDifferentVertices();
                    start = chrono::high_resolution_clock::now();
                    algorithms.fordFulkersonList(*dirGraph, vertices[0], vertices[1]);
                    end = chrono::high_resolution_clock::now();
                    break;
                }
            }

            chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
            return duration; // Zwróć czas trwania sortowania
        }
    }
    delete dirGraph;
    delete unDirGraph;
    return chrono::microseconds(0);
}


