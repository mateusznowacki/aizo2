//
// Created by matty on 08.06.2024.
//
using namespace std;

#include "ConsoleManager.h"
#include <string>


void ConsoleManager::printMenu() {
    cout << "Wybierz opcje z menu" << endl;
    cout << "1. Generowanie grafow do pliku" << endl;
    cout << "2. Sprawdzanie poprawnosci algorytmow" << endl;
    cout << "3. Pomiary automatyczne i generowanie wynikow" << endl;
    cout << "4. Wyjscie" << endl;
}


//int ConsoleManager::printSortingAlgorithmsOptions() {
//    cout << "" << endl;
//    cout << "1. Uruchom algorytm MST" << endl;
//    cout << "2. Uruchom algorytm najkrotszej sciezki" << endl;
//    cout << "3. Uruchom algorytm maksymalnego przeplywu" << endl;
//    cout << "=====================" << endl;
//    cout << "Wybierz opcje: ";
//    int choice = 0;
//    cin >> choice;
//    return choice;
//}

int ConsoleManager::printSortingAlgorithmsOptions() {
    cout << "1. Prim" << endl;
    cout << "2. Kruskal" << endl;
    cout << "3. Dijkstra" << endl;
    cout << "4. Ford-Bellman" << endl;
    cout << "5. Ford-Fulkerson" << endl;
    cout << "=====================" << endl;
    cout << "Wybierz opcje: ";
    int choice = 0;
    cin >> choice;
    return choice;
}

int ConsoleManager::printMST() {
    cout << "1. Prim" << endl;
    cout << "2. Kruskal" << endl;
    cout << "=====================" << endl;
    cout << "Wybierz opcje: ";
    int choice = 0;
    cin >> choice;
    return choice;
}

int ConsoleManager::printShortPath() {
    cout << "1. Dijkstra" << endl;
    cout << "2. Ford-Bellman" << endl;
    cout << "=====================" << endl;
    cout << "Wybierz opcje: ";
    int choice = 0;
    cin >> choice;
    return choice;
}


int ConsoleManager::printMSTAlgorithmsOptions() {
    cout << "1. Kruskal" << endl;
    cout << "2. Prim" << endl;
    int choice = 0;
    cin >> choice;
    return choice;
}

int ConsoleManager::printShortPathAlgorithmsOptions() {
    cout << "1. Dijkstra" << endl;
    cout << "2. Ford-Bellman" << endl;
    int choice = 0;
    cin >> choice;
    return choice;

}

int ConsoleManager::printMaxFlowAlgorithmsOptions() {
    cout << "1. Ford-Fulkerson" << endl;
    int choice = 0;
    cin >> choice;
    return choice;
}

int ConsoleManager::printGetVertexCount() {
    cout << "Podaj liczbe wierzcholkow: " << endl;
    int choice = 0;
    cin >> choice;
    return choice;
}

int ConsoleManager::printGetDensity() {
    cout << "Podaj gestosc grafu w procentach: " << endl;
    int choice = 0;
    cin >> choice;
    return choice;
}

int ConsoleManager::printGetEdgeMaxWeight() {
    cout << "Podaj maksymalna wage krawedzi: " << endl;
    int choice = 0;
    cin >> choice;
    return choice;
}

// Drukowanie macierzy incydencji
void ConsoleManager::printAdjMatrix(int **adjMatrix, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Drukowanie listy następników
void ConsoleManager::printAdjList(Graph::Node **adjList, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << ": ";
        Graph::Node *head = adjList[i];
        while (head != nullptr) {
            std::cout << "(" << head->vertex << ", " << head->weight << ") ";
            head = head->next;
        }
        std::cout << std::endl;
    }
}

string ConsoleManager::printGetFilename() {
    cout << "Podaj nazwe pliku: " << endl;
    string name;
    cin >> name;
    name.append(".txt");
    return name;
}

void ConsoleManager::printAvailableDataSources() {
    cout << "Wybierz zrodlo danych" << endl;
    cout << "1. Wygeneruj losowe dane" << endl;
    cout << "2. Wczytaj dane z pliku" << endl;
}

bool ConsoleManager::askIfPrintArray() {
    cout << "Czy chcesz wyswietlic grafy ?  1-tak 0-nie" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        return true;
    } else {
        return false;
    }
}

bool ConsoleManager::askIfWantToCheckOtherAlgorithm() {
    // Metoda do zapytania użytkownika, czy chce sprawdzić inny algorytm sortowania
    cout << "Czy chcesz sprawdzic inny algorytm sortowania? 1-tak 0-nie" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        return true;
    } else {
        return false;
    }
}

int ConsoleManager::getTypeOptions() {
    cout << "Wybierz typ reprezentacji " << endl;
    cout << "1. Lista " << endl;
    cout << "2. Macierz " << endl;
    int choice = 0;
    cin >> choice;
    return choice;
}

int *ConsoleManager::getVerticesToPath() {
    int* vertices = new int[2];

    cout << "Podaj wierzchołek począktowy:" << endl;
    cin >> vertices[0];
    cout << "Podaj wierzchołek koncowy" << endl;
    cin >> vertices[1];
    return vertices;
}

