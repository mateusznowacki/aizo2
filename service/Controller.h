//
// Created by matty on 08.06.2024.
//

#ifndef AIZO2_CONTROLLER_H
#define AIZO2_CONTROLLER_H


#include <chrono>

class Controller {
    public:
    std::chrono::microseconds runGraphAlgorithm(int algorithmType, int vertexCount, int density, int reprezentationType);
   void generateGraphsToFile();

};


#endif //AIZO2_CONTROLLER_H
