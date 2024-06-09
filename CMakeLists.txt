cmake_minimum_required(VERSION 3.28)
project(aizo2)

set(CMAKE_CXX_STANDARD 17)
MATH(EXPR stack_size "16 * 1024 * 1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,16777216")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(aizo2 main.cpp
        service/Algorithms.cpp
        service/Algorithms.h
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
