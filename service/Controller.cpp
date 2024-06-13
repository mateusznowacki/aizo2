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

void Controller::runUserTest() {
    int choice = 0;
    console.printAvailableDataSources(); // Wyświetlenie dostępnych źródeł danych
    cin >> choice;
    if (choice == 1) {
        generateOwnDataAndSort(); // Generowanie własnych danych i sortowanie
    } else if (choice == 2) {
        getDataFromFileAndSort(); // Pobieranie danych z pliku i sortowanie
    }
}


std::chrono::microseconds
Controller::runGraphAlgorithm(int algorithmType, int vertexCount, int density, int reprezentationType) {
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

void Controller::generateOwnDataAndSort() {

    bool printArray = console.askIfPrintArray();

    int choice ;

    Graph *dirGraph = dataGenerator.generateRandomDirGraph(console.printGetVertexCount(), console.printGetDensity());
    Graph *unDirGraph = dataGenerator.generateUnDirGraph(dirGraph);
    chrono::high_resolution_clock::time_point start, end;

    if(printArray) {
        cout << "Macierz incydencji dla grafu skierowanego " << endl;
        dirGraph->printAdjMatrix(printArray);
        cout << "Lista sąsiedztwa dla grafu skierowanego " << endl;
        dirGraph->printAdjList(printArray);
        cout << "Macierz incydencji dla grafu nieskierowanego " << endl;
        unDirGraph->printAdjMatrix(printArray);
        cout << "Lista sąsiedztwa dla grafu nieskierowanego " << endl;
        unDirGraph->printAdjList(printArray);
    }

    do {
        choice = console.printSortingAlgorithmsOptions();
        switch (choice) {

            case 1: //mst
            {
                int mstChoice = console.printMSTAlgorithmsOptions();
                int reprezentationType = console.getTypeOptions();
                if (mstChoice == 1) {
                    if (reprezentationType == 2) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.primMSTMatrix(*unDirGraph);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    } else if (reprezentationType == 1) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.primMSTList(*unDirGraph);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    }

                } else if (mstChoice == 2) {
                    if (reprezentationType == 2) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.kruskalMSTList(*unDirGraph);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    } else if (reprezentationType == 1) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.kruskalMSTMatrix(*unDirGraph);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    }

                }
            }
            case 2: //sciezka

            {  int pathChoice = console.printShortPathAlgorithmsOptions();
                int reprezentationType = console.getTypeOptions();
                int *vertices = console.getVerticesToPath();
                if (pathChoice == 1) {
                    if (reprezentationType == 1) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.dijkstraList(*dirGraph, vertices[0], vertices[1],true);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    } else if (reprezentationType == 2) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.dijkstraMatrix(*dirGraph, vertices[0], vertices[1],true);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    }
                } else if (pathChoice == 2) {
                    if (reprezentationType == 2) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.bellmanFordMatrix(*dirGraph, vertices[0], vertices[1],true);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    } else if (reprezentationType == 1) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.bellmanFordList(*dirGraph, vertices[0], vertices[1],true);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    }
                }

            }
            case 3: //maxflow
            {
                int *vertices = console.getVerticesToPath();
                int reprezentationType = console.getTypeOptions();
                if (reprezentationType == 2) {
                    start = chrono::high_resolution_clock::now();
                    algorithms.fordFulkersonMatrix(*dirGraph, vertices[0], vertices[1], true);
                    end = chrono::high_resolution_clock::now();
                    chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                    break;
                } else if (reprezentationType == 1) {
                    start = chrono::high_resolution_clock::now();
                    algorithms.fordFulkersonList(*dirGraph, vertices[0], vertices[1], true);
                    end = chrono::high_resolution_clock::now();
                    chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                    break;
                }
            }
        }
    } while (console.askIfWantToCheckOtherAlgorithm());
}

void Controller::getDataFromFileAndSort() {
    bool printArray = console.askIfPrintArray();

    int choice;

    Graph *dirGraph = fileManag.loadGraphFromFile(console.printGetFilename());
    Graph *unDirGraph = dataGenerator.generateUnDirGraph(dirGraph);
    chrono::high_resolution_clock::time_point start, end;

    if (printArray) {
        cout << "Macierz incydencji dla grafu skierowanego " << endl;
        dirGraph->printAdjMatrix(printArray);
        cout << "Lista sąsiedztwa dla grafu skierowanego " << endl;
        dirGraph->printAdjList(printArray);
        cout << "Macierz incydencji dla grafu nieskierowanego " << endl;
        unDirGraph->printAdjMatrix(printArray);
        cout << "Lista sąsiedztwa dla grafu nieskierowanego " << endl;
        unDirGraph->printAdjList(printArray);
    }

    do {
        choice = console.printSortingAlgorithmsOptions();
        switch (choice) {

            case 1: //mst
            {
                int mstChoice = console.printMSTAlgorithmsOptions();
                int reprezentationType = console.getTypeOptions();
                if (mstChoice == 1) {
                    if (reprezentationType == 2) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.primMSTMatrix(*unDirGraph);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    } else if (reprezentationType == 1) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.primMSTList(*unDirGraph);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    }

                } else if (mstChoice == 2) {
                    if (reprezentationType == 2) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.kruskalMSTList(*unDirGraph);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    } else if (reprezentationType == 1) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.kruskalMSTMatrix(*unDirGraph);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    }

                }
            }
            case 2: //sciezka

            {
                int pathChoice = console.printShortPathAlgorithmsOptions();
                int reprezentationType = console.getTypeOptions();
                int *vertices = console.getVerticesToPath();
                if (pathChoice == 1) {
                    if (reprezentationType == 1) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.dijkstraList(*dirGraph, vertices[0], vertices[1], true);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    } else if (reprezentationType == 2) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.dijkstraMatrix(*dirGraph, vertices[0], vertices[1], true);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    }
                } else if (pathChoice == 2) {
                    if (reprezentationType == 2) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.bellmanFordMatrix(*dirGraph, vertices[0], vertices[1], true);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    } else if (reprezentationType == 1) {
                        start = chrono::high_resolution_clock::now();
                        algorithms.bellmanFordList(*dirGraph, vertices[0], vertices[1], true);
                        end = chrono::high_resolution_clock::now();
                        chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                        cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                        break;
                    }
                }

            }
            case 3: //maxflow
            {
                int *vertices = console.getVerticesToPath();
                int reprezentationType = console.getTypeOptions();
                if (reprezentationType == 2) {
                    start = chrono::high_resolution_clock::now();
                    algorithms.fordFulkersonMatrix(*dirGraph, vertices[0], vertices[1], true);
                    end = chrono::high_resolution_clock::now();
                    chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                    break;
                } else if (reprezentationType == 1) {
                    start = chrono::high_resolution_clock::now();
                    algorithms.fordFulkersonList(*dirGraph, vertices[0], vertices[1], true);
                    end = chrono::high_resolution_clock::now();
                    chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(end - start);
                    cout << "Czas trwania: " << duration.count() << " mikrosekund" << endl;
                    break;
                }
            }
        }
    } while (console.askIfWantToCheckOtherAlgorithm());

}
