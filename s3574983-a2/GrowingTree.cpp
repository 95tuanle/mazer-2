//
//  GrowingTree.cpp
//  s3574983-a2
//
//  Created by Tuan Le on 5/1/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#include "GrowingTree.hpp"

vector<Edge> GrowingTree::generate() {
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
        
        if (!neighbours.empty()) {
            Edge edge;
            edge.setCoordinator1(startingCell);
            int currentRandom = rand() % neighbours.size();
            startingCell = neighbours[currentRandom];
            edge.setCoordinator2(startingCell);
            edges.push_back(edge);
            visitedArray[startingCell.getX()][startingCell.getY()] = true;
            visitedCoordinators.push_back(startingCell);
            
            currentRandom = rand() % visitedCoordinators.size();
            startingCell = visitedCoordinators[currentRandom];
        } else {
            visitedCoordinators.erase(std::remove_if(visitedCoordinators.begin(), visitedCoordinators.end(),
                                                     [&startingCell](const Coordinator& coordinator) {
                                                         return coordinator.getX() == startingCell.getX() &&
                                                         coordinator.getY() == startingCell.getY();
                                                     }), visitedCoordinators.end());
            if (!visitedCoordinators.empty()) {
                int currentRandom = rand() % visitedCoordinators.size();
                startingCell = visitedCoordinators[currentRandom];
            }
        }
    }
    return edges;
}
