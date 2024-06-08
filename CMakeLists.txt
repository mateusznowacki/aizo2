cmake_minimum_required(VERSION 3.28)
project(aizo2)

set(CMAKE_CXX_STANDARD 17)

add_executable(aizo2 main.cpp
        Algorithms.cpp
        Algorithms.h
        utils/ConsoleManager.cpp
        utils/ConsoleManager.h
        service/AutoPerformanceTester.cpp
        service/AutoPerformanceTester.h
        service/Controller.cpp
        service/Controller.h
        utils/DataGenerator.cpp
        utils/DataGenerator.h
        utils/FileManager.cpp
        utils/FileManager.h
        model/Graph.cpp
        model/Graph.h
        model/Graph.cpp
)
