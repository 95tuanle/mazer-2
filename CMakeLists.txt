cmake_minimum_required(VERSION 3.14)
project(s3574983_a2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(.)

add_executable(
        Coordinator.cpp
        Coordinator.hpp
        Edge.cpp
        Edge.hpp
        Generator.cpp
        Generator.hpp
        GrowingTree.cpp
        GrowingTree.hpp
        HuntAndKill.cpp
        HuntAndKill.hpp
        main.cpp
        Prim.cpp
        Prim.hpp
        RecursiveBacktracking.cpp
        RecursiveBacktracking.hpp)
