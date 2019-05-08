cmake_minimum_required(VERSION 3.14)
project(s3574983_a2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

include_directories(.)
include_directories(s3574983-a2)

add_executable(s3574983_a2
        s3574983-a2/Coordinator.cpp
        s3574983-a2/Coordinator.hpp
        s3574983-a2/Edge.cpp
        s3574983-a2/Edge.hpp
        s3574983-a2/Generator.cpp
        s3574983-a2/Generator.hpp
        s3574983-a2/GrowingTree.cpp
        s3574983-a2/GrowingTree.hpp
        s3574983-a2/HuntAndKill.cpp
        s3574983-a2/HuntAndKill.hpp
        s3574983-a2/main.cpp
        s3574983-a2/Prims.cpp
        s3574983-a2/Prims.hpp
        s3574983-a2/RecursiveBacktracking.cpp
        s3574983-a2/RecursiveBacktracking.hpp)
