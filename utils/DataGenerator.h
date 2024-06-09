
#ifndef AIZO2_DATAGENERATOR_H
#define AIZO2_DATAGENERATOR_H

#include "../model/Graph.h"

class DataGenerator {

public:
    Graph *generateRandomDirGraph(int vertexCount, int density);
    Graph *generateUnDirGraph(Graph *dirGraph);
};


#endif //AIZO2_DATAGENERATOR_H
