//
//  main.cpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>
#include "Generator.hpp"
#include "Coordinator.hpp"
#include "Edge.hpp"
#include "HuntAndKill.hpp"
#include "GrowingTree.hpp"
#include "Prims.hpp"
#include "RecursiveBacktracking.hpp"

using namespace chrono;

void getUserInput();

void printLineWith(const string& stringToPrint);

void saveSvg(basic_string<char, char_traits<char>, allocator<char>> &fileName, const vector<Edge>& vector, int width,
             int height);

void saveBinary(basic_string<char, char_traits<char>, allocator<char>> &fileName, const vector<Edge>& vector, int width,
                int height);

void printMazePath(const vector<Edge>& vector);

int main(int argc, const char * argv[]) {

    
    getUserInput();
    
//    RecursiveBacktracking growingTree;
//    Generator *generator = &growingTree;
//    generator->setSeed(333);
//    generator->setWidth(200);
//    generator->setHeight(200);
//    generator->setWithSeed(true);
//    vector<Edge> edgesVector = growingTree.generate();
//    saveSvg((basic_string<char, char_traits<char>, allocator<char>> &) "xtuanle.svg", edgesVector, 200, 200);
//    generator->setSeed(999);
//    edgesVector = growingTree.generate();
//    saveSvg((basic_string<char, char_traits<char>, allocator<char>> &) "xtuanleX.svg", edgesVector, 100, 100);
    
//    vector<int> tuan;
//    tuan.push_back(0);
//    tuan.push_back(1);
//    tuan.push_back(2);
//    tuan.push_back(3);
//    tuan.push_back(4);
//    tuan.push_back(5);
//
//    for (int i = 0; i < tuan.size(); i++) {
//        cout << tuan[i] << endl;
//    }
//
//    tuan.erase(tuan.begin() + 1);
//
//    for (int i = 0; i < tuan.size(); i++) {
//        cout << tuan[i] << endl;
//    }
    
    return 0;
}

void getUserInput() {
    string DUPLICATE_FLAG_MESSAGE = "duplication of flag occurs, please try again";
    string INVALID_INPUT_MESSAGE = "invalid input, please try again";
    string WRONG_FORMAT_G_FLAG = "invalid input format, please follow '--gh or --gg or --gp or --gr seed width height'";
    string WRONG_FORMAT_G_OPT_FLAG =
            "invalid input format, please follow '-gh or -gg or -gp or -gr seed width height' or '-gh or -gg or -gp or -gr width height'";
    string NOT_LARGER_THAN_ZERO = "your specifications must be larger than 0";
    string EXIT = "exit";
    string userInput;
    
    while (userInput != EXIT) { // check if user input is exit
        vector<string> userInputVector; // create vector to store user input
        // userInputVector.clear();
        pair<int, bool> hasHuntAndKill;
        pair<int, bool> hasHuntAndKillOpt;
        pair<int, bool> hasGrowingTree;
        pair<int, bool> hasGrowingTreeOpt;
        pair<int, bool> hasPrims;
        pair<int, bool> hasPrimsOpt;
        pair<int, bool> hasRecursiveBacktracking;
        pair<int, bool> hasRecursiveBacktrackingOpt;
        pair<int, bool> hasLoadBinary;
        pair<int, bool> hasLoadSvg;
        pair<int, bool> hasSaveBinary;
        pair<int, bool> hasSaveSvg;
        bool isValidInputFlag = false;
        
        // get user input
        cout << "./mazer ";
        getline (cin, userInput);
        
        // split it by space and add to vector
        stringstream stringStream(userInput);
        copy(istream_iterator<string>(stringStream), istream_iterator<string>(), back_inserter(userInputVector));
        // check if first elment of user input vector = exit
        if (userInputVector[0] == EXIT) {
            break;
        }
        
        // loop to check flag
        for (int i = 0; i < userInputVector.size(); ++i) {
            if (userInputVector[i] == "--gh") {
                if (!hasHuntAndKill.second) {
                    hasHuntAndKill.first = i;
                    hasHuntAndKill.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "-gh") {
                if (!hasHuntAndKillOpt.second) {
                    hasHuntAndKillOpt.first = i;
                    hasHuntAndKillOpt.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "--gg") {
                if (!hasGrowingTree.second) {
                    hasGrowingTree.first = i;
                    hasGrowingTree.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "-gg") {
                if (!hasGrowingTreeOpt.second) {
                    hasGrowingTreeOpt.first = i;
                    hasGrowingTreeOpt.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "--gp") {
                if (!hasPrims.second) {
                    hasPrims.first = i;
                    hasPrims.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "-gp") {
                if (!hasPrimsOpt.second) {
                    hasPrimsOpt.first = i;
                    hasPrimsOpt.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "--gr") {
                if (!hasRecursiveBacktracking.second) {
                    hasRecursiveBacktracking.first = i;
                    hasRecursiveBacktracking.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "-gr") {
                if (!hasRecursiveBacktrackingOpt.second) {
                    hasRecursiveBacktrackingOpt.first = i;
                    hasRecursiveBacktrackingOpt.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "--lb") {
                if (!hasLoadBinary.second) {
                    hasLoadBinary.first = i;
                    hasLoadBinary.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "--lv") {
                if (!hasLoadSvg.second) {
                    hasLoadSvg.first = i;
                    hasLoadSvg.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "--sb") {
                if (!hasSaveBinary.second) {
                    hasSaveBinary.first = i;
                    hasSaveBinary.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "--sv") {
                if (!hasSaveSvg.second) {
                    hasSaveSvg.first = i;
                    hasSaveSvg.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            }
        }
        // check if input contains flags/flag
        if (isValidInputFlag) {
            bool canCallSaveFunctions = true;
            vector<Edge> edgesVector;
            int mainWidth = 0;
            int mainHeight = 0;
            if (hasHuntAndKill.second) {
                int seed = 0;
                int width = 0;
                int height = 0;
                // printLineWithInt(seed);
                // printLineWithInt(width);
                // printLineWithInt(height);
                try {
                    // convert input to int
                    seed = stoi(userInputVector[hasHuntAndKill.first+1]);
                    width = stoi(userInputVector[hasHuntAndKill.first+2]);
                    height = stoi(userInputVector[hasHuntAndKill.first+3]);
                    // cout << userInputVector[hasGen.first+1];
                    // cout << userInputVector[hasGen.first+2];
                    // cout << userInputVector[hasGen.first+3];
                    // printLineWith(userInputVector[hasGen.first+1]);
                    // printLineWith(userInputVector[hasGen.first+2]);
                    // printLineWith(userInputVector[hasGen.first+3]);
                    if (seed > 0 && width > 0 && height > 0) {
                        canCallSaveFunctions = true;
//                        printLineWith("calling hunt and kill func");
                        mainWidth = width;
                        mainHeight = height;
                        HuntAndKill huntAndKill;
                        Generator *generator = &huntAndKill;
                        generator->setSeed(seed);
                        generator->setWidth(width);
                        generator->setHeight(height);
                        auto start = high_resolution_clock::now();
                        edgesVector = huntAndKill.generate();
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                        printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                        printMazePath(edgesVector);
                    } else {
                        canCallSaveFunctions = false;
                        printLineWith(NOT_LARGER_THAN_ZERO);
                    }
                } catch (...) {
                    canCallSaveFunctions = false;
                    printLineWith(WRONG_FORMAT_G_FLAG);
                }
            }
            if (hasHuntAndKillOpt.second) {
                int firstField = 0;
                int secondField = 0;
                // printLineWithInt(firstField);
                // printLineWithInt(secondField);
                try {
                    // convert input to int
                    firstField = stoi(userInputVector[hasHuntAndKillOpt.first+1]);
                    secondField = stoi(userInputVector[hasHuntAndKillOpt.first+2]);
                    // printLineWithInt(firstField);
                    // printLineWithInt(secondField);
                    int thirdField = 0;
                    // printLineWithInt(thirdField);
                    try {
                        thirdField = stoi(userInputVector[hasHuntAndKillOpt.first+3]);
                        // printLineWithInt(thirdField);
                        if (firstField > 0 && secondField > 0 && thirdField > 0) {
                            canCallSaveFunctions = true;
//                            printLineWith("calling hunt and kill with optional seed func");
                            mainWidth = secondField;
                            mainHeight = thirdField;
                            HuntAndKill huntAndKill;
                            Generator *generator = &huntAndKill;
                            generator->setSeed(firstField);
                            generator->setWidth(secondField);
                            generator->setHeight(thirdField);
                            auto start = high_resolution_clock::now();
                            edgesVector = huntAndKill.generate();
                            auto stop = high_resolution_clock::now();
                            auto duration = duration_cast<milliseconds>(stop - start);
                            printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                            printMazePath(edgesVector);
                        } else {
                            canCallSaveFunctions = false;
                            printLineWith(NOT_LARGER_THAN_ZERO);
                        }
                    } catch (...) {
                        if (firstField > 0 && secondField > 0) {
                            canCallSaveFunctions = true;
//                            printLineWith("calling hunt and kill without optional seed func");
                            mainWidth = firstField;
                            mainHeight = secondField;
                            HuntAndKill huntAndKill;
                            Generator *generator = &huntAndKill;
                            int seed = (int) time(0);
                            printLineWith("Your seed is " + to_string(seed));
                            generator->setSeed(seed);
                            generator->setWidth(firstField);
                            generator->setHeight(secondField);
                            auto start = high_resolution_clock::now();
                            edgesVector = huntAndKill.generate();
                            auto stop = high_resolution_clock::now();
                            auto duration = duration_cast<milliseconds>(stop - start);
                            printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                            printMazePath(edgesVector);
                        } else {
                            canCallSaveFunctions = false;
                            printLineWith(NOT_LARGER_THAN_ZERO);
                        }
                    }
                } catch (...) {
                    canCallSaveFunctions = false;
                    printLineWith(WRONG_FORMAT_G_OPT_FLAG);
                }
            }
            if (hasGrowingTree.second) {
                int seed = 0;
                int width = 0;
                int height = 0;
                try {
                    // convert input to int
                    seed = stoi(userInputVector[hasGrowingTree.first+1]);
                    width = stoi(userInputVector[hasGrowingTree.first+2]);
                    height = stoi(userInputVector[hasGrowingTree.first+3]);
                    if (seed > 0 && width > 0 && height > 0) {
                        canCallSaveFunctions = true;
//                        printLineWith("calling growing tree func");
                        mainWidth = width;
                        mainHeight = height;
                        GrowingTree growingTree;
                        Generator *generator = &growingTree;
                        generator->setSeed(seed);
                        generator->setWidth(width);
                        generator->setHeight(height);
                        auto start = high_resolution_clock::now();
                        edgesVector = growingTree.generate();
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                        printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                        printMazePath(edgesVector);
                    } else {
                        canCallSaveFunctions = false;
                        printLineWith(NOT_LARGER_THAN_ZERO);
                    }
                } catch (...) {
                    canCallSaveFunctions = false;
                    printLineWith(WRONG_FORMAT_G_FLAG);
                }
            }
            if (hasGrowingTreeOpt.second) {
                int firstField = 0;
                int secondField = 0;
                try {
                    // convert input to int
                    firstField = stoi(userInputVector[hasGrowingTreeOpt.first+1]);
                    secondField = stoi(userInputVector[hasGrowingTreeOpt.first+2]);
                    int thirdField = 0;
                    try {
                        thirdField = stoi(userInputVector[hasGrowingTreeOpt.first+3]);
                        if (firstField > 0 && secondField > 0 && thirdField > 0) {
                            canCallSaveFunctions = true;
//                            printLineWith("calling growing tree with optional seed func");
                            mainWidth = secondField;
                            mainHeight = thirdField;
                            GrowingTree growingTree;
                            Generator *generator = &growingTree;
                            generator->setSeed(firstField);
                            generator->setWidth(secondField);
                            generator->setHeight(thirdField);
                            auto start = high_resolution_clock::now();
                            edgesVector = growingTree.generate();
                            auto stop = high_resolution_clock::now();
                            auto duration = duration_cast<milliseconds>(stop - start);
                            printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                            printMazePath(edgesVector);
                        } else {
                            canCallSaveFunctions = false;
                            printLineWith(NOT_LARGER_THAN_ZERO);
                        }
                    } catch (...) {
                        if (firstField > 0 && secondField > 0) {
                            canCallSaveFunctions = true;
//                            printLineWith("calling growing tree without optional seed func");
                            mainWidth = firstField;
                            mainHeight = secondField;
                            GrowingTree growingTree;
                            Generator *generator = &growingTree;
                            int seed = (int) time(0);
                            printLineWith("Your seed is " + to_string(seed));
                            generator->setSeed(seed);
                            generator->setWidth(firstField);
                            generator->setHeight(secondField);
                            auto start = high_resolution_clock::now();
                            edgesVector = growingTree.generate();
                            auto stop = high_resolution_clock::now();
                            auto duration = duration_cast<milliseconds>(stop - start);
                            printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                            printMazePath(edgesVector);
                        } else {
                            canCallSaveFunctions = false;
                            printLineWith(NOT_LARGER_THAN_ZERO);
                        }
                    }
                } catch (...) {
                    canCallSaveFunctions = false;
                    printLineWith(WRONG_FORMAT_G_OPT_FLAG);
                }
            }
            
            if (hasPrims.second) {
                int seed = 0;
                int width = 0;
                int height = 0;
                try {
                    // convert input to int
                    seed = stoi(userInputVector[hasPrims.first+1]);
                    width = stoi(userInputVector[hasPrims.first+2]);
                    height = stoi(userInputVector[hasPrims.first+3]);
                    if (seed > 0 && width > 0 && height > 0) {
                        canCallSaveFunctions = true;
//                        printLineWith("calling prim's func");
                        mainWidth = width;
                        mainHeight = height;
                        Prims prims;
                        Generator *generator = &prims;
                        generator->setSeed(seed);
                        generator->setWidth(width);
                        generator->setHeight(height);
                        auto start = high_resolution_clock::now();
                        edgesVector = prims.generate();
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                        printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                        printMazePath(edgesVector);
                    } else {
                        canCallSaveFunctions = false;
                        printLineWith(NOT_LARGER_THAN_ZERO);
                    }
                } catch (...) {
                    canCallSaveFunctions = false;
                    printLineWith(WRONG_FORMAT_G_FLAG);
                }
            }
            if (hasPrimsOpt.second) {
                int firstField = 0;
                int secondField = 0;
                try {
                    // convert input to int
                    firstField = stoi(userInputVector[hasPrimsOpt.first+1]);
                    secondField = stoi(userInputVector[hasPrimsOpt.first+2]);
                    int thirdField = 0;
                    try {
                        thirdField = stoi(userInputVector[hasPrimsOpt.first+3]);
                        if (firstField > 0 && secondField > 0 && thirdField > 0) {
                            canCallSaveFunctions = true;
//                            printLineWith("calling prim's with optional seed func");
                            mainWidth = secondField;
                            mainHeight = thirdField;
                            Prims prims;
                            Generator *generator = &prims;
                            generator->setSeed(firstField);
                            generator->setWidth(secondField);
                            generator->setHeight(thirdField);
                            auto start = high_resolution_clock::now();
                            edgesVector = prims.generate();
                            auto stop = high_resolution_clock::now();
                            auto duration = duration_cast<milliseconds>(stop - start);
                            printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                            printMazePath(edgesVector);
                        } else {
                            canCallSaveFunctions = false;
                            printLineWith(NOT_LARGER_THAN_ZERO);
                        }
                    } catch (...) {
                        if (firstField > 0 && secondField > 0) {
                            canCallSaveFunctions = true;
//                            printLineWith("calling prim's without optional seed func");
                            mainWidth = firstField;
                            mainHeight = secondField;
                            Prims prims;
                            Generator *generator = &prims;
                            int seed = (int) time(0);
                            printLineWith("Your seed is " + to_string(seed));
                            generator->setSeed(seed);
                            generator->setWidth(firstField);
                            generator->setHeight(secondField);
                            auto start = high_resolution_clock::now();
                            edgesVector = prims.generate();
                            auto stop = high_resolution_clock::now();
                            auto duration = duration_cast<milliseconds>(stop - start);
                            printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                            printMazePath(edgesVector);
                        } else {
                            canCallSaveFunctions = false;
                            printLineWith(NOT_LARGER_THAN_ZERO);
                        }
                    }
                } catch (...) {
                    canCallSaveFunctions = false;
                    printLineWith(WRONG_FORMAT_G_OPT_FLAG);
                }
            }
            if (hasRecursiveBacktracking.second) {
                int seed = 0;
                int width = 0;
                int height = 0;
                try {
                    // convert input to int
                    seed = stoi(userInputVector[hasRecursiveBacktracking.first+1]);
                    width = stoi(userInputVector[hasRecursiveBacktracking.first+2]);
                    height = stoi(userInputVector[hasRecursiveBacktracking.first+3]);
                    if (seed > 0 && width > 0 && height > 0) {
                        canCallSaveFunctions = true;
//                        printLineWith("calling recursive backtracking func");
                        mainWidth = width;
                        mainHeight = height;
                        RecursiveBacktracking recursiveBacktracking;
                        Generator *generator = &recursiveBacktracking;
                        generator->setSeed(seed);
                        generator->setWidth(width);
                        generator->setHeight(height);
                        auto start = high_resolution_clock::now();
                        edgesVector = recursiveBacktracking.generate();
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<milliseconds>(stop - start);
                        printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                        printMazePath(edgesVector);
                    } else {
                        canCallSaveFunctions = false;
                        printLineWith(NOT_LARGER_THAN_ZERO);
                    }
                } catch (...) {
                    canCallSaveFunctions = false;
                    printLineWith(WRONG_FORMAT_G_FLAG);
                }
            }
            if (hasRecursiveBacktrackingOpt.second) {
                int firstField = 0;
                int secondField = 0;
                try {
                    // convert input to int
                    firstField = stoi(userInputVector[hasRecursiveBacktrackingOpt.first+1]);
                    secondField = stoi(userInputVector[hasRecursiveBacktrackingOpt.first+2]);
                    int thirdField = 0;
                    try {
                        thirdField = stoi(userInputVector[hasRecursiveBacktrackingOpt.first+3]);
                        if (firstField > 0 && secondField > 0 && thirdField > 0) {
                            canCallSaveFunctions = true;
//                            printLineWith("calling recursive backtracking with optional seed func");
                            mainWidth = secondField;
                            mainHeight = thirdField;
                            RecursiveBacktracking recursiveBacktracking;
                            Generator *generator = &recursiveBacktracking;
                            generator->setSeed(firstField);
                            generator->setWidth(secondField);
                            generator->setHeight(thirdField);
                            auto start = high_resolution_clock::now();
                            edgesVector = recursiveBacktracking.generate();
                            auto stop = high_resolution_clock::now();
                            auto duration = duration_cast<milliseconds>(stop - start);
                            printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                            printMazePath(edgesVector);
                        } else {
                            canCallSaveFunctions = false;
                            printLineWith(NOT_LARGER_THAN_ZERO);
                        }
                    } catch (...) {
                        if (firstField > 0 && secondField > 0) {
                            canCallSaveFunctions = true;
//                            printLineWith("calling recursive backtracking without optional seed func");
                            mainWidth = firstField;
                            mainHeight = secondField;
                            RecursiveBacktracking recursiveBacktracking;
                            Generator *generator = &recursiveBacktracking;
                            int seed = (int) time(0);
                            printLineWith("Your seed is " + to_string(seed));
                            generator->setSeed(seed);
                            generator->setWidth(firstField);
                            generator->setHeight(secondField);
                            auto start = high_resolution_clock::now();
                            edgesVector = recursiveBacktracking.generate();
                            auto stop = high_resolution_clock::now();
                            auto duration = duration_cast<milliseconds>(stop - start);
                            printLineWith("Generating time is " + to_string(duration.count()) + " milliseconds");
//                            printMazePath(edgesVector);
                        } else {
                            canCallSaveFunctions = false;
                            printLineWith(NOT_LARGER_THAN_ZERO);
                        }
                    }
                } catch (...) {
                    canCallSaveFunctions = false;
                    printLineWith(WRONG_FORMAT_G_OPT_FLAG);
                }
            }
            
            if (hasLoadBinary.second) {
                // TODO build load binary function
                // canCallSaveFunctions = true;
                printLineWith("calling load binary func");
            }
            if (hasLoadSvg.second) {
                // TODO build load svg function
                // canCallSaveFunctions = true;
                printLineWith("calling load SVG func");
            }
            
            if ((hasHuntAndKill.second || hasHuntAndKillOpt.second || hasGrowingTree.second ||
            hasGrowingTreeOpt.second || hasPrims.second || hasPrimsOpt.second || hasRecursiveBacktracking.second ||
            hasRecursiveBacktrackingOpt.second || hasLoadBinary.second || hasLoadSvg.second) && canCallSaveFunctions) {
                if (hasSaveBinary.second) {
                    // TODO check file format and validate user input
//                    printLineWith("calling save binary func");
                    auto start = high_resolution_clock::now();
                    saveBinary(userInputVector[hasSaveBinary.first + 1], edgesVector, mainWidth, mainHeight);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(stop - start);
                    printLineWith("Saving binary file time is " + to_string(duration.count()) + " milliseconds");
                }
                if (hasSaveSvg.second) {
                    // TODO check file format and validate user input
//                    printLineWith("calling save SVG func");
                    auto start = high_resolution_clock::now();
                    saveSvg(userInputVector[hasSaveSvg.first + 1], edgesVector, mainWidth, mainHeight);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<milliseconds>(stop - start);
                    printLineWith("Saving binary file time is " + to_string(duration.count()) + " milliseconds");
                }
            } else {
                if (hasSaveBinary.second || hasSaveSvg.second) {
                    printLineWith("you must create or load the maze first");
                }
            }
        } else {
            printLineWith(INVALID_INPUT_MESSAGE);
        }
    }
    // while (userInputVector[0] != EXIT && userInput != EXIT);
}

void printLineWith(const string& stringToPrint) {
    cout << stringToPrint << endl;
}

void saveBinary(basic_string<char, char_traits<char>, allocator<char>> &fileName, const vector<Edge>& vector, int width,
                int height) {
    fstream binary(fileName, ios::binary | ios::in | ios::out | ios::trunc);
    if (!binary.is_open()) {
        printLineWith("error while opening the file");
    } else {
        binary.write((char *) &width, sizeof(width));
        binary.write((char *) &height, sizeof(height));
        long numberOfEdges = vector.size();
        binary.write((char *) &numberOfEdges, sizeof(width));
        
        for (auto & edge : vector) {
            int x1 =  edge.getCoordinator1().getX();
            int y1 =  edge.getCoordinator1().getY();
            int x2 =  edge.getCoordinator2().getX();
            int y2 =  edge.getCoordinator2().getY();
            binary.write((char *) &x1, sizeof(x1));
            binary.write((char *) &y1, sizeof(y1));
            binary.write((char *) &x2, sizeof(x2));
            binary.write((char *) &y2, sizeof(y2));
        }
        
        binary.seekg(0);
        binary.close();
    }
}

void saveSvg(basic_string<char, char_traits<char>, allocator<char>> &fileName, const vector<Edge>& vector, int width,
             int height) {
    ofstream svg(fileName, ofstream::out);
    svg << "<svg" << " viewBox=" << "\"0 0 " << width << " " << height << "\""<< " width" << "=" << "\"" << width*10
    << "\"" << " height=\"" << height*10 << "\"" << " xmlns=" << "\"http://www.w3.org/2000/svg\">" << endl;
    svg << "<rect width =" << "\'" << width << "\' " << "height=\'" << height << "\' " << "style=\'"
    << "fill: black\' " << "/>" << endl;
    for (auto & edge : vector) {
        int x1 =  edge.getCoordinator1().getX();
        int y1 =  edge.getCoordinator1().getY();
        int x2 =  edge.getCoordinator2().getX();
        int y2 =  edge.getCoordinator2().getY();
        svg << "<line stroke=\'" << "white\' " << "stroke-width=\'" << "0.5\'" << " x1=\'" << x1 << "\' y1=\'" << y1
        << "\' x2=\'" << x2 << "\' y2=\'" << y2 << "\'/>" << endl;
    }
    svg << "</svg>";
    svg.close();
}

void printMazePath(const vector<Edge>& vector) {
    for (auto & edge : vector) {
        cout << edge.getCoordinator1().getX() << ":" << edge.getCoordinator1().getY() << " | " << edge.getCoordinator2().getX() << ":" << edge.getCoordinator2().getY() << endl;
    }
}
