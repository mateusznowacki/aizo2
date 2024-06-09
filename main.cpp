#include <iostream>
#include "utils/ConsoleManager.h"
#include "service/AutoPerformanceTester.h"
#include "service/Controller.h"
#include "utils/FileManager.h"
#include "utils/DataGenerator.h"


using namespace std;

int main() {

    ConsoleManager consoleManager;
    DataGenerator generator;


        int vertices = 6;
        int density = 50;

        // Generowanie grafu skierowanego
        std::cout << "Generating directed graph" << std::endl;
        Graph* directedGraph = generator.generateRandomDirGraph(vertices, density);

        // Wyświetlanie grafu skierowanego
        std::cout << "Macierz sąsiedztwa (skierowany):" << std::endl;
        consoleManager.printAdjMatrix(directedGraph->getAdjMatrix(), vertices);

        std::cout << "Lista następników (skierowany):" << std::endl;
        consoleManager.printAdjList(directedGraph->getAdjList(), vertices);

        // Generowanie grafu nieskierowanego
        std::cout << "Generating undirected graph" << std::endl;
        Graph* undirectedGraph = generator.generateUnDirGraph(directedGraph);

        // Wyświetlanie grafu nieskierowanego
        std::cout << "Macierz sąsiedztwa (nieskierowany):" << std::endl;
        consoleManager.printAdjMatrix(undirectedGraph->getAdjMatrix(), vertices);

        std::cout << "Lista następników (nieskierowany):" << std::endl;
        consoleManager.printAdjList(undirectedGraph->getAdjList(), vertices);

        delete directedGraph;
       delete undirectedGraph;



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