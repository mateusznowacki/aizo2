//
// Created by matty on 08.06.2024.
//
using namespace std;

#include "ConsoleManager.h"
#include "../model/Graph.h"


void ConsoleManager::printMenu(){
        cout << "Wybierz opcje z menu" << endl;
        cout << "1. Generowanie grafow do pliku" << endl;
        cout << "2. Sprawdzanie poprawnosci algorytmow" << endl;
        cout << "3. Pomiary automatyczne i generowanie wynikow" << endl;
        cout << "4. Wyjscie" << endl;
}


void ConsoleManager::print1Menu() {
    cout << "" << endl;
    cout << "2. Wygeneruj graf losowo" << endl;
    cout << "3. Wyswietl graf" << endl;
    cout << "4. Uruchom algorytm MST" << endl;
    cout << "5. Uruchom algorytm najkrotszej sciezki" << endl;
    cout << "6. Uruchom algorytm maksymalnego przeplywu" << endl;
    cout << "7. Wyjscie" << endl;
    cout << "=====================" << endl;
    cout << "Wybierz opcje: ";
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
    cout << "Podaj liczbe wierzcholkow: ";
    int choice = 0;
    cin >> choice;
    return choice;
}

int ConsoleManager::printGetDensity() {
    cout << "Podaj gestosc grafu w procentach: ";
    int choice = 0;
    cin >> choice;
    return choice;
}

int ConsoleManager::printGetEdgeMaxWeight() {
    cout << "Podaj maksymalna wage krawedzi: ";
     int choice = 0;
    cin >> choice;
    return choice;
}

// Drukowanie macierzy incydencji
void ConsoleManager::printAdjMatrix(int** adjMatrix, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Drukowanie listy następników
void ConsoleManager::printAdjList(Graph::Node** adjList, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        std::cout << i << ": ";
        Graph::Node* head = adjList[i];
        while (head != nullptr) {
            std::cout << "(" << head->vertex << ", " << head->weight << ") ";
            head = head->next;
        }
        std::cout << std::endl;
    }
}

