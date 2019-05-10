//
//  GrowingTree.cpp
//  s3574983-a2
//
//  Created by Tuan Le on 5/1/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#include "GrowingTree.hpp"

vector<Edge> GrowingTree::generate() {
//    set up
    int seed = getSeed();
    srand(seed);
    int height = getHeight();
    int width = getWidth();
//    create an array to monitor visited cells
    bool visitedArray[height][width];
    for (int m = 0; m < height; ++m) {
        for (int i = 0; i < width; ++i) {
            visitedArray[m][i] = false;
        }
    }
    
//    create vector to store edges
    vector<Edge> edges;
    vector<Coordinator> visitedCoordinators;
    
//    generate a random stating cell
    Coordinator startingCell;
    startingCell.setX(rand() % height);
    startingCell.setY(rand() % width);
//    flag it as visited
    visitedArray[startingCell.getX()][startingCell.getY()] = true;
    visitedCoordinators.push_back(startingCell);
    
    while (!visitedCoordinators.empty()) {
//        index unvisited neighbour coordinators
        vector<Coordinator> neighbours;
        
        if (startingCell.getX() - 1 > -1) {
            if (!visitedArray[startingCell.getX() - 1][startingCell.getY()]) {
                Coordinator topCell;
                topCell.setX(startingCell.getX() - 1);
                topCell.setY(startingCell.getY());
                neighbours.push_back(topCell);
            }
        }
        
        if (startingCell.getY() + 1 < width) {
            if (!visitedArray[startingCell.getX()][startingCell.getY() + 1]) {
                Coordinator rightCell;
                rightCell.setX(startingCell.getX());
                rightCell.setY(startingCell.getY() + 1);
                neighbours.push_back(rightCell);
            }
        }
        
        if (startingCell.getX() + 1 < height) {
            if (!visitedArray[startingCell.getX() + 1][startingCell.getY()]) {
                Coordinator bottomCell;
                bottomCell.setX(startingCell.getX() + 1);
                bottomCell.setY(startingCell.getY());
                neighbours.push_back(bottomCell);
            }
        }
        
        if (startingCell.getY() - 1 > -1) {
            if (!visitedArray[startingCell.getX()][startingCell.getY() - 1]) {
                Coordinator leftCell;
                leftCell.setX(startingCell.getX());
                leftCell.setY(startingCell.getY() - 1);
                neighbours.push_back(leftCell);
            }
        }
//        if not empty randomize a new stating cell, mark it as visited and add it to edges with the previous staring cell
        if (!neighbours.empty()) {
            Edge edge;
            edge.setCoordinator1(startingCell);
            int currentRandom = rand() % neighbours.size();
            startingCell = neighbours[currentRandom];
            edge.setCoordinator2(startingCell);
            edges.push_back(edge);
            visitedArray[startingCell.getX()][startingCell.getY()] = true;
//            put the new stating cell to visited vector
            visitedCoordinators.push_back(startingCell);
//            randomize a new starting cell from visited vector
            currentRandom = rand() % visitedCoordinators.size();
            startingCell = visitedCoordinators[currentRandom];
//        if empty delete the current stating cell from visited visited
        } else {
            visitedCoordinators.erase(std::remove_if(visitedCoordinators.begin(), visitedCoordinators.end(),
                                                     [&startingCell](const Coordinator& coordinator) {
                                                         return coordinator.getX() == startingCell.getX() &&
                                                         coordinator.getY() == startingCell.getY();
                                                     }), visitedCoordinators.end());
//            if visited vector is not empty, randomize a new starting cell from visited vector
            if (!visitedCoordinators.empty()) {
                int currentRandom = rand() % visitedCoordinators.size();
                startingCell = visitedCoordinators[currentRandom];
            }
        }
    }
    return edges;
}

//Old version
/*
int seed = getSeed();
srand(seed);
int height = getHeight();
int width = getWidth();
//    create an array to monitor visited cells
visitedAndDeleted visitedAndDeletedArray[height][width];
for (int m = 0; m < height; ++m) {
    for (int i = 0; i < width; ++i) {
        visitedAndDeletedArray[m][i].first = false;
        visitedAndDeletedArray[m][i].second = false;
        
    }
}

//    create vector to store edges
vector<Edge> edges;

bool keepDeleting = true;
bool keepCarving = true;

//    generate a random stating cell
Coordinator startingCell;
startingCell.setX(rand() % height);
startingCell.setY(rand() % width);
//    flag it as visited
visitedAndDeletedArray[startingCell.getX()][startingCell.getY()].first = true;

while (keepDeleting) {
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            if (!visitedAndDeletedArray[j][i].first) {
                keepCarving = true;
                break;
            } else {
                keepCarving = false;
            }
        }
        if (keepCarving) {
            break;
        }
    }
    while (keepCarving) {
        vector<Coordinator> neighbours;
        if (startingCell.getX() - 1 > -1) {
            Coordinator topCell;
            topCell.setX(startingCell.getX() - 1);
            topCell.setY(startingCell.getY());
            neighbours.push_back(topCell);
        }
        if (startingCell.getY() + 1 < width) {
            Coordinator rightCell;
            rightCell.setX(startingCell.getX());
            rightCell.setY(startingCell.getY() + 1);
            neighbours.push_back(rightCell);
        }
        if (startingCell.getX() + 1 < height) {
            Coordinator bottomCell;
            bottomCell.setX(startingCell.getX() + 1);
            bottomCell.setY(startingCell.getY());
            neighbours.push_back(bottomCell);
        }
        if (startingCell.getY() - 1 > -1) {
            Coordinator leftCell;
            leftCell.setX(startingCell.getX());
            leftCell.setY(startingCell.getY() - 1);
            neighbours.push_back(leftCell);
        }
        vector<int> randomizedNeighbours;
        //                loop to check all neighbours randomly to find a not visited neighbour
        bool keepSeeking = true;
        while (keepSeeking) {
            int currentRandom = rand() % neighbours.size();
            bool addingRandom = true;
            //                    check if randomized neighbour is checked or not
            for (int i = 0; i < randomizedNeighbours.size(); ++i) {
                if (randomizedNeighbours[i] == currentRandom) {
                    addingRandom = false;
                    break;
                }
            }
            //                    if not checked, add to checked vector
            if (addingRandom) {
                randomizedNeighbours.push_back(currentRandom);
                Coordinator neighbour = neighbours[currentRandom];
                //                        check if not visited
                if (!visitedAndDeletedArray[neighbour.getX()][neighbour.getY()].first) {
                    keepSeeking = false;
                    //                            mark as visited
                    visitedAndDeletedArray[neighbour.getX()][neighbour.getY()].first = true;
                    //                            add edge
                    Edge edge1;
                    edge1.setCoordinator1(startingCell);
                    edge1.setCoordinator2(neighbour);
                    edges.push_back(edge1);
                    startingCell.setX(neighbour.getX());
                    startingCell.setY(neighbour.getY());
                }
            } else {
                //                        else check if the neighbours vector is all checked
                if (randomizedNeighbours.size() == neighbours.size()) {
                    keepSeeking = false;
                    keepCarving = false;
                }
            }
        }
    }
    vector<Coordinator> visitedAndUndeletedArray;
    for (int k = 0; k < height; ++k) {
        for (int i = 0; i < width; ++i) {
            if (visitedAndDeletedArray[k][i].first && !visitedAndDeletedArray[k][i].second) {
                Coordinator visitedCoordinator;
                visitedCoordinator.setX(k);
                visitedCoordinator.setY(i);
                visitedAndUndeletedArray.push_back(visitedCoordinator);
            }
        }
    }
    //        bool foundStarting = false;
    
    bool keepSeeking = !visitedAndUndeletedArray.empty();
    while (keepSeeking) {
        int currentRandom = rand() % visitedAndUndeletedArray.size();
        startingCell = visitedAndUndeletedArray[currentRandom];
        vector<Coordinator> neighbours;
        if (startingCell.getX() - 1 > -1) {
            if (!visitedAndDeletedArray[startingCell.getX() - 1][startingCell.getY()].first) {
                Coordinator topCell;
                topCell.setX(startingCell.getX() - 1);
                topCell.setY(startingCell.getY());
                neighbours.push_back(topCell);
            }
        }
        if (startingCell.getY() + 1 < width) {
            if (!visitedAndDeletedArray[startingCell.getX()][startingCell.getY() + 1].first) {
                Coordinator rightCell;
                rightCell.setX(startingCell.getX());
                rightCell.setY(startingCell.getY() + 1);
                neighbours.push_back(rightCell);
            }
        }
        if (startingCell.getX() + 1 < height) {
            if (!visitedAndDeletedArray[startingCell.getX() + 1][startingCell.getY()].first) {
                Coordinator bottomCell;
                bottomCell.setX(startingCell.getX() + 1);
                bottomCell.setY(startingCell.getY());
                neighbours.push_back(bottomCell);
            }
        }
        if (startingCell.getY() - 1 > -1) {
            if (!visitedAndDeletedArray[startingCell.getX()][startingCell.getY() - 1].first) {
                Coordinator leftCell;
                leftCell.setX(startingCell.getX());
                leftCell.setY(startingCell.getY() - 1);
                neighbours.push_back(leftCell);
            }
        }
        if (neighbours.empty()) {
            visitedAndDeletedArray[startingCell.getX()][startingCell.getY()].second = true;
            visitedAndUndeletedArray.erase(visitedAndUndeletedArray.begin() + currentRandom - 1);
            keepSeeking = !visitedAndUndeletedArray.empty();
        } else {
            Edge edge;
            edge.setCoordinator1(startingCell);
            keepSeeking = false;
            keepCarving = true;
            currentRandom = rand() % neighbours.size();
            startingCell = neighbours[currentRandom];
            visitedAndDeletedArray[startingCell.getX()][startingCell.getY()].first = true;
            edge.setCoordinator2(startingCell);
            edges.push_back(edge);
        }
    }
    for (int l = 0; l < height; ++l) {
        for (int i = 0; i < width; ++i) {
            if (!visitedAndDeletedArray[l][i].second) {
                keepDeleting = true;
                break;
            } else {
                keepDeleting = false;
            }
        }
        if (keepDeleting) {
            break;
        }
    }
}
*/
