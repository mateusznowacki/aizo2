#include <iostream>
#include "utils/ConsoleManager.h"
#include "service/AutoPerformanceTester.h"
#include "service/Controller.h"
#include "utils/FileManager.h"
#include "utils/DataGenerator.h"
#include "service/Algorithms.h"


using namespace std;

int main() {

    ConsoleManager consoleManager;
    DataGenerator generator;
    FileManager fileManager;


//        int vertices = 6;
//        int density = 50;

        // Generowanie grafu skierowanego
        std::cout << "Generating directed graph" << std::endl;
        Graph* directedGraph = fileManager.loadGraphFromFile("a.txt");

        // Wyświetlanie grafu skierowanego
        std::cout << "Macierz sąsiedztwa (skierowany):" << std::endl;
        consoleManager.printAdjMatrix(directedGraph->getAdjMatrix(), directedGraph->getVertices());

        std::cout << "Lista następników (skierowany):" << std::endl;
        consoleManager.printAdjList(directedGraph->getAdjList(), directedGraph->getVertices());

        // Generowanie grafu nieskierowanego
        std::cout << "Generating undirected graph" << std::endl;
        Graph* undirectedGraph = generator.generateUnDirGraph(directedGraph);

        // Wyświetlanie grafu nieskierowanego
        std::cout << "Macierz sąsiedztwa (nieskierowany):" << std::endl;
        consoleManager.printAdjMatrix(undirectedGraph->getAdjMatrix(), undirectedGraph->getVertices());

        std::cout << "Lista następników (nieskierowany):" << std::endl;
        consoleManager.printAdjList(undirectedGraph->getAdjList(), undirectedGraph->getVertices());

        delete directedGraph;
       delete undirectedGraph;

    Algorithms algorithms;

// Create a graph with 5 vertices
    Graph graph(5);

    // Add edges for an undirected graph
    graph.addUnDirEdge(0, 1, 2);
    graph.addUnDirEdge(0, 3, 6);
    graph.addUnDirEdge(1, 2, 3);
    graph.addUnDirEdge(1, 3, 8);
    graph.addUnDirEdge(1, 4, 5);
    graph.addUnDirEdge(2, 4, 7);
    graph.addUnDirEdge(3, 4, 9);

    // Create an instance of Algorithms


    // Test Prim's algorithm using adjacency matrix
    std::cout << "Prim's MST using adjacency matrix:" << std::endl;
    algorithms.primMSTMatrix(graph);

    // Test Prim's algorithm using adjacency list
    std::cout << "\nPrim's MST using adjacency list:" << std::endl;
    algorithms.primMSTList(graph);

    // Test Kruskal's algorithm using adjacency matrix
    std::cout << "\nKruskal's MST using adjacency matrix:" << std::endl;
    algorithms.kruskalMSTMatrix(graph);

    // Test Kruskal's algorithm using adjacency list
    std::cout << "\nKruskal's MST using adjacency list:" << std::endl;
    algorithms.kruskalMSTList(graph);

    // Add directed edges for testing Dijkstra and Bellman-Ford algorithms


    // Test Dijkstra's algorithm using adjacency matrix
    std::cout << "\nDijkstra's algorithm using adjacency matrix:" << std::endl;
    algorithms.dijkstraMatrix(graph, 0);

    // Test Dijkstra's algorithm using adjacency list
    std::cout << "\nDijkstra's algorithm using adjacency list:" << std::endl;
    algorithms.dijkstraList(graph, 0);

    // Test Bellman-Ford algorithm using adjacency matrix
    std::cout << "\nBellman-Ford algorithm using adjacency matrix:" << std::endl;
    algorithms.bellmanFordMatrix(graph, 0);

    // Test Bellman-Ford algorithm using adjacency list
    std::cout << "\nBellman-Ford algorithm using adjacency list:" << std::endl;
    algorithms.bellmanFordList(graph, 0);

    // Add edges for testing Ford-Fulkerson algorithm
    Graph flowGraph(6);
    flowGraph.addDirEdge(0, 1, 16);
    flowGraph.addDirEdge(0, 2, 13);
    flowGraph.addDirEdge(1, 2, 10);
    flowGraph.addDirEdge(1, 3, 12);
    flowGraph.addDirEdge(2, 1, 4);
    flowGraph.addDirEdge(2, 4, 14);
    flowGraph.addDirEdge(3, 2, 9);
    flowGraph.addDirEdge(3, 5, 20);
    flowGraph.addDirEdge(4, 3, 7);
    flowGraph.addDirEdge(4, 5, 4);

    // Test Ford-Fulkerson algorithm using adjacency matrix
    std::cout << "\nFord-Fulkerson algorithm using adjacency matrix:" << std::endl;
    algorithms.fordFulkersonMatrix(flowGraph, 0, 5);

    // Test Ford-Fulkerson algorithm using adjacency list
    std::cout << "\nFord-Fulkerson algorithm using adjacency list:" << std::endl;
    algorithms.fordFulkersonList(flowGraph, 0, 5);



























    AutoPerformanceTester tester; // Utworzenie obiektu tester klasy AutoPerformanceTester
    ConsoleManager console; // Utworzenie obiektu console klasy ConsoleManager
    Controller controller; // Utworzenie obiektu controller klasy Controller

    int choice = 0;
    do {
        console.printMenu(); // Wywołanie funkcji printMenu() z obiektu console
        cin >> choice; // Pobranie wyboru użytkownika

        switch (choice) {
            case 1: {
//                controller.generateGraphsToFile(); //  generowanie grafow do pliku
                break;
            }
            case 2: {
             //   controller.getUserDataForAlgorithms(); // sprawdzanie poprawności algorytmów
                break;
            }
            case 3: {
              //  tester.runAutoTests(); // Wywołanie funkcji runAutoTests() do automatycznych testow i zbierania wynikow
                break;
            }
            default:
                cout << "Nie ma takiej opcji" << endl; // Komunikat w przypadku nieprawidłowego wyboru
                break;
        }

    } while (choice != 4); // Pętla wykonuje się dopóki użytkownik nie wybierze opcji 4 (wyjście)

    return 0;
}