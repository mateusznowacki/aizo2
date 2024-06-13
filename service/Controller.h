//
// Created by matty on 08.06.2024.
//

#ifndef AIZO2_CONTROLLER_H
#define AIZO2_CONTROLLER_H


#include <chrono>
#include "../model/Graph.h"

class Controller {
    public:
    std::chrono::microseconds runGraphAlgorithm(int algorithmType, int vertexCount, int density, int reprezentationType);
   void generateGraphsToFile();

    void runUserTest();

    void generateOwnDataAndSort();

    void getDataFromFileAndSort();

    void runManualTest(int choice);

    void runListAlgorithm(int type, Graph *pGraph, Graph *pGraph1);

    void runMatrixAlgorithm(int type, Graph *pGraph, Graph *pGraph1);
};


#endif //AIZO2_CONTROLLER_H
