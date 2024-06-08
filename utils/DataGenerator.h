
#ifndef AIZO2_DATAGENERATOR_H
#define AIZO2_DATAGENERATOR_H

#include "../model/Graph.h"

class DataGenerator {

public:
    Graph *generateRandomGraph(int vertexCount, int density);

  //  Graph *generateUndirectedGraphFromDirected(Graph *directedGraph);
};


#endif //AIZO2_DATAGENERATOR_H
