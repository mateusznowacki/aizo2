
#ifndef AIZO2_CONSOLEMANAGER_H
#define AIZO2_CONSOLEMANAGER_H

#include <iostream>
#include "../model/Graph.h"

class ConsoleManager {
    public:

    void printMenu();
    void print1Menu();
    int getTypeOptions();
    int printMSTAlgorithmsOptions();
    int printShortPathAlgorithmsOptions();
    int printMaxFlowAlgorithmsOptions();
//    int printSortedArrayType();
//    int printGetArraySize();
//    void printAvailableDataSources();
//    string printGetFilename();
//    bool askIfPrintArray();
//    bool askIfWantToCheckOtherAlgorithm();
//    void printConfig();
    int printGetVertexCount();

    int printGetDensity();

    int printGetEdgeMaxWeight();

     void printAdjMatrix(int** adjMatrix, int vertices);
     void printAdjList(Graph::Node** adjList, int vertices);
};


#endif //AIZO2_CONSOLEMANAGER_H
