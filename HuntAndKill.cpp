//
//  HuntAndKill.cpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#include "HuntAndKill.hpp"

vector<Edge> HuntAndKill::generate() {
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

    bool keepHunting = true;
    bool keepKilling = true;

    //    generate a random stating cell
    Coordinator startingCell;
    startingCell.setX(rand() % height);
    startingCell.setY(rand() % width);
    //    flag it as visited
    visitedArray[startingCell.getX()][startingCell.getY()] = true;

    //    loop as hunting continuously
    while (keepHunting) {
        for (int j = 0; j < height; ++j) {
            for (int i = 0; i < width; ++i) {
                if (!visitedArray[j][i]) {
                    keepKilling = true;
                    break;
                } else {
                    keepKilling = false;
                }
            }
            if (keepKilling) {
                break;
            }
        }
        //        loop as killing continuously
        while (keepKilling) {

            //                create a vector to store neighbour cell
            vector<Coordinator> neighbours;
            //                looking for neighbours

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
                //                    hasBottom = true;
                //                    numberOfNeighbours++;
            }

            if (startingCell.getY() - 1 > -1) {
                Coordinator leftCell;
                leftCell.setX(startingCell.getX());
                leftCell.setY(startingCell.getY() - 1);
                neighbours.push_back(leftCell);
            }

            //                create vector to store checked neighbours randomly
            vector<int> randomizedNeighbours;

            //                loop to check all neighbours randomly to find a not visited neighbour
            bool keepSeeking = true;
            while (keepSeeking) {
                int currentRandom = rand() % neighbours.size();
                bool addingRandom = true;
                //                    check if randomized neighbour is checked or not
                for (int randomizedNeighbour: randomizedNeighbours) {
                    if (randomizedNeighbour == currentRandom) {
                        addingRandom = false;
                        break;
                    }
                }
                //                    if not checked, add to checked vector
                if (addingRandom) {
                    randomizedNeighbours.push_back(currentRandom);
                    Coordinator neighbour = neighbours[currentRandom];
                    //                        check if not visited
                    if (!visitedArray[neighbour.getX()][neighbour.getY()]) {
                        keepSeeking = false;
                        //                            mark as visited
                        visitedArray[neighbour.getX()][neighbour.getY()] = true;
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
                        keepKilling = false;
                    }
                }
            }
        }

        //        hunting
        bool foundStarting = false;
        //        loop from left to right, top to bottom to find unvisited cell
        for (int k = 0; k < height; ++k) {
            for (int i = 0; i < width; ++i) {
                //                if unvisited step into a check
                if (!visitedArray[k][i]) {
                    //                    assume it has at least one
                    startingCell.setX(k);
                    startingCell.setY(i);

                    //                    create a vector to store neighbour cell
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
                    //                    check if any neighbour is visited, if not break to find the next cel
                    for (auto neighbour: neighbours) {
                        if (visitedArray[neighbour.getX()][neighbour.getY()]) {
                            foundStarting = true;
                            break;
                        }
                    }
                    //                    if any neighbour is visited
                    if (foundStarting) {
                        //                        create a checked neighbours vector
                        vector<int> randomizedNeighbours;
                        //                        randomizedNeighbours.clear();

                        //                        loop to randomized through neighbours vector
                        bool keepSeeking = true;
                        while (keepSeeking) {
                            int currentRandom = rand() % neighbours.size();
                            bool addingRandom = true;
                            //                            check if randomized neighbour is checked or not
                            for (int randomizedNeighbour: randomizedNeighbours) {
                                if (randomizedNeighbour == currentRandom) {
                                    addingRandom = false;
                                    break;
                                }
                            }
                            //                            if not checked, add to checked vector
                            if (addingRandom) {
                                randomizedNeighbours.push_back(currentRandom);
                                Coordinator neighbour = neighbours[currentRandom];
                                //                                check if visited
                                if (visitedArray[neighbour.getX()][neighbour.getY()]) {
                                    keepSeeking = false;
                                    //                                    mark the starting cell is visited
                                    visitedArray[startingCell.getX()][startingCell.getY()] = true;
                                    //                                    add edge
                                    Edge edge1;
                                    edge1.setCoordinator1(startingCell);
                                    edge1.setCoordinator2(neighbour);
                                    edges.push_back(edge1);
                                }
                            } else {
                                //                                else check if the neighbours vector is all checked
                                if (randomizedNeighbours.size() == neighbours.size()) {
                                    keepSeeking = false;
                                    foundStarting = false;
                                }
                            }
                        }
                    }
                    if (foundStarting) {
                        break;
                    }
                }
            }
            if (foundStarting) {
                break;
            }
        }
        //        check if it needs hunting
        for (int l = 0; l < height; ++l) {
            for (int i = 0; i < width; ++i) {
                if (!visitedArray[l][i]) {
                    keepHunting = true;
                    break;
                } else {
                    keepHunting = false;
                }
            }
            if (keepHunting) {
                break;
            }
        }
    }
    return edges;
}