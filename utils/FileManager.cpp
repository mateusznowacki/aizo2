
#include "FileManager.h"
#include "../model/Graph.h"
#include <fstream>
#include <iostream>

using namespace std;


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

void FileManager::saveGraphToFile(Graph *graph, string filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    int vertices = graph->getVertices();
    int **adjMatrix = graph->getAdjMatrix();

    // Counting edges
    int edgesCount = 0;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (adjMatrix[i][j] != 0) {
                edgesCount++;
            }
        }
    }

    outFile << edgesCount << " " << vertices << std::endl;

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (adjMatrix[i][j] != 0) {
                outFile << i << " " << j << " " << adjMatrix[i][j] << std::endl;
            }
        }
    }

    outFile.close();
    }



// Metoda do zapisu wyniku czasu sortowania do pliku
void FileManager::saveResultToFile(std::chrono::duration<int64_t, ratio<1, 1000000000>> time, int algorithm, int reprezentationType,
                      int density, int size) {
    string filename;
    string algorithmName;
    string reprezentationName;

    // Określenie nazwy algorytmu
    switch (algorithm) {
        case 1:
            algorithmName = "prim";
            break;
        case 2:
            algorithmName = "kruskal";
            break;
        case 3:
            algorithmName = "dijsktra";
            break;
        case 4:
            algorithmName = "fordBellman";
            break;
        case 5:
            algorithmName = "fordFulkerson";
            break;
    }

    // Określenie nazwy typu tablicy
    switch (reprezentationType) {
        case 1:
            reprezentationName = "matrix";
            break;
        case 2:
            reprezentationName = "list";
            break;
    }

    // Określenie nazwy pliku na podstawie algorytmu, typu tablicy i rozmiaru
    filename = algorithmName + "_" + to_string(density)  + "_" + reprezentationName + "_" + to_string(size) + ".txt";

    // Otwarcie pliku w trybie dopisywania
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        // Obsługa błędu, jeśli nie udało się otworzyć pliku
        cerr << "Warning: Could not open file, creating a new file." << endl;
        // Utworzenie nowego pliku
        file.open(filename);
        if (!file.is_open()) {
            // Obsługa błędu, jeśli nie udało się utworzyć nowego pliku
            cerr << "Error: Could not create file" << endl;
            return;
        }
    }
    chrono::milliseconds duration_ms = chrono::duration_cast<chrono::milliseconds>(time);

    // Zapisanie wyniku czasu do pliku
    file << duration_ms.count() << endl;

    // Zamknięcie pliku
    file.close();
}

// Metoda do odczytu liczby iteracji z pliku konfiguracyjnego
int FileManager::getConfigFileIterations() {
    ifstream inputFile("config.txt");
    // Obsługa błędu w przypadku nieudanego otwarcia pliku
    if (!inputFile.is_open()) {
        cerr << "Nie udało się otworzyć pliku: " << endl;
        return -1; // Zwróć -1 w przypadku błędu
    }

    string line;
    while (getline(inputFile, line)) {
        // Sprawdzenie, czy linia zawiera "iterations:"
        if (line.find("iterations:") != string::npos) {
            // Znaleziono linię z "iterations:", zwróć wartość po dwukropku
            size_t colonPos = line.find(":");
            string valueStr = line.substr(colonPos + 1);
            // Konwertuj string na int i zwróć
            try {
                return stoi(valueStr);
            } catch (...) {
                cerr << "Błąd konwersji wartości 'iterations' na int." << endl;
                return 0; // Zwróć 0 w przypadku błędu konwersji
            }
        }
    }
    // Nie znaleziono linii z "iterations:"
    cerr << "Nie znaleziono linii z 'iterations:' w pliku: " << endl;
    return 0; // Zwróć 0 jeśli nie znaleziono
}

// Metoda do odczytu rozmiaru tablic z pliku konfiguracyjnego
int *FileManager::getConfigFileGraphSize() {
    ifstream inputFile("config.txt");
    // Obsługa błędu w przypadku nieudanego otwarcia pliku
    if (!inputFile.is_open()) {
        cerr << "Nie udało się otworzyć pliku: config.txt" << endl;
    }

    // Zliczanie linii zawierających klucz "size:"
    int amount = 0;
    string line;
    while (getline(inputFile, line)) {
        if (line.find("size:") != string::npos) {
            amount++;
        }
    }

    // Alokacja pamięci dla tablicy
    int *sizes = new int[amount];

    // Przejście przez plik ponownie i wpisanie wartości do tablicy
    inputFile.clear();
    inputFile.seekg(0, ios::beg); // Przewiń na początek pliku
    int index = 0;
    while (getline(inputFile, line)) {
        if (line.find("size:") != string::npos) {
            // Znaleziono linię zawierającą "size:", pobierz wartość i zapisz do tablicy
            size_t colonPos = line.find(":");
            string valueStr = line.substr(colonPos + 1);
            try {
                sizes[index++] = stoi(valueStr);
            } catch (...) {
                cerr << "Błąd konwersji wartości 'size' na int." << endl;
                delete[] sizes; // Zwolnij zaalokowaną pamięć w przypadku błędu
                return nullptr; // Zwróć nullptr w przypadku błędu konwersji
            }
        }
    }

    inputFile.close();
    return sizes;
}

