#ifndef AIZO2_FILEMANAGER_H
#define AIZO2_FILEMANAGER_H

#include "../model/Graph.h"

class FileManager {
public:
static Graph* loadGraphFromFile(const std::string& filename);
};

#endif //AIZO2_FILEMANAGER_H
