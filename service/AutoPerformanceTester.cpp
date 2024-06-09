//
// Created by matty on 08.06.2024.
//

#include "AutoPerformanceTester.h"
#include "Controller.h"
#include "../utils/FileManager.h"

Controller controller;
FileManager fileManager;

void AutoPerformanceTester::runAutoTests() {
    std:chrono::microseconds time ;
    int *vertexCount = fileManager.getConfigFileGraphSize();
    int iterations = fileManager.getConfigFileIterations();
    int algorithmsAmount = 5;
    int reprezentationTypesAmount = 2;
    int density[] = {25, 50, 99};

    for (int i = 1; i <= algorithmsAmount; ++i) { // 5 - ilosc algorytmow
        for (int j = 0; j < 7; ++j) {// 7 - ilosc rozmiarow grafu
            for (int k = 0; k < 3; ++k) {// 3 - ilosc gestosci
                for (int l = 1; l <= reprezentationTypesAmount; ++l) {
                    for (int m = 0; m < iterations; ++m) {
                        time = controller.runGraphAlgorithm(i, vertexCount[j], density[k], l);
                        fileManager.saveResultToFile(time, i, l, density[k], vertexCount[j]);
                    }
                }
            }
        }
    }

}



