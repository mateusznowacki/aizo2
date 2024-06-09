#ifndef AIZO2_FILEMANAGER_H
#define AIZO2_FILEMANAGER_H


#include <chrono>
#include <cstdint>
#include "../model/Graph.h"

using namespace std;

class FileManager {
public:
 Graph* loadGraphFromFile(const std::string& filename);
    void saveGraphToFile(Graph *graph, string filename);
    void saveResultToFile(std::chrono::duration<int64_t, ratio<1, 1000000000>> time, int algorithm, int reprezentationType,int density, int size);
    int *getConfigFileGraphSize();
    int getConfigFileIterations();

    int getConfigFileAlgorithmType();
};

#endif //AIZO2_FILEMANAGER_H
