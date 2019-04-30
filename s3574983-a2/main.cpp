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
#include "Generator.hpp"
#include "Coordinator.hpp"
#include "Edge.hpp"

using namespace std;

void getUserInput();

void printLineWith(const string& stringToPrint);

void saveSvg(basic_string<char, char_traits<char>, allocator<char>> &fileName, const vector<Edge>& vector, int width,
             int height);

void saveBinary(basic_string<char, char_traits<char>, allocator<char>> &fileName, const vector<Edge>& vector, int width,
                int height);

int main(int argc, const char * argv[]) {
    // insert code here...
//    cout << "Hello, World!\n";
    return 0;
}

void getUserInput() {
    string DUPLICATE_FLAG_MESSAGE = "duplication of flag occurs, please try again";
    string INVALID_INPUT_MESSAGE = "invalid input, please try again";
    string WRONG_FORMAT_G_FLAG = "invalid input format, please follow '--g seed width height'";
    string WRONG_FORMAT_G_OPT_FLAG = "invalid input format, please follow '-g seed width height' or '-g width height'";
    string NOT_LARGER_THAN_ZERO = "your specifications must be larger than 0";
    string EXIT = "exit";
    string userInput;
    
    while (userInput != EXIT) { // check if user input is exit
        vector<string> userInputVector; // create vector to store user input
        // userInputVector.clear();
        pair<int, bool> hasGen;
        pair<int, bool> hasGenOpt;
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
            if (userInputVector[i] == "--g") {
                if (!hasGen.second) {
                    hasGen.first = i;
                    hasGen.second = true;
                    isValidInputFlag = true;
                } else {
                    isValidInputFlag = false;
                    printLineWith(DUPLICATE_FLAG_MESSAGE);
                    break;
                }
            } else if (userInputVector[i] == "-g") {
                if (!hasGenOpt.second) {
                    hasGenOpt.first = i;
                    hasGenOpt.second = true;
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
            if (hasGen.second) {
                int seed = 0;
                int width = 0;
                int height = 0;
                // printLineWithInt(seed);
                // printLineWithInt(width);
                // printLineWithInt(height);
                try {
                    // convert input to int
                    seed = stoi(userInputVector[hasGen.first+1]);
                    width = stoi(userInputVector[hasGen.first+2]);
                    height = stoi(userInputVector[hasGen.first+3]);
                    // cout << userInputVector[hasGen.first+1];
                    // cout << userInputVector[hasGen.first+2];
                    // cout << userInputVector[hasGen.first+3];
                    // printLineWith(userInputVector[hasGen.first+1]);
                    // printLineWith(userInputVector[hasGen.first+2]);
                    // printLineWith(userInputVector[hasGen.first+3]);
                    if (seed > 0 && width > 0 && height > 0) {
                        canCallSaveFunctions = true;
                        printLineWith("calling generating func");
                        mainWidth = width;
                        mainHeight = height;
//                        edgesVector = mazeGenerator(seed, width, height, true);
                    } else {
                        canCallSaveFunctions = false;
                        printLineWith(NOT_LARGER_THAN_ZERO);
                    }
                } catch (...) {
                    canCallSaveFunctions = false;
                    printLineWith(WRONG_FORMAT_G_FLAG);
                }
            }
            if (hasGenOpt.second) {
                int firstField = 0;
                int secondField = 0;
                // printLineWithInt(firstField);
                // printLineWithInt(secondField);
                try {
                    // convert input to int
                    firstField = stoi(userInputVector[hasGenOpt.first+1]);
                    secondField = stoi(userInputVector[hasGenOpt.first+2]);
                    // printLineWithInt(firstField);
                    // printLineWithInt(secondField);
                    int thirdField = 0;
                    // printLineWithInt(thirdField);
                    try {
                        thirdField = stoi(userInputVector[hasGenOpt.first+3]);
                        // printLineWithInt(thirdField);
                        if (firstField > 0 && secondField > 0 && thirdField > 0) {
                            canCallSaveFunctions = true;
                            printLineWith("calling generating with optional seed func");
                            mainWidth = secondField;
                            mainHeight = thirdField;
//                            edgesVector = mazeGenerator(firstField, secondField, thirdField, true);
                        } else {
                            canCallSaveFunctions = false;
                            printLineWith(NOT_LARGER_THAN_ZERO);
                        }
                    } catch (...) {
                        if (firstField > 0 && secondField > 0) {
                            canCallSaveFunctions = true;
                            printLineWith("calling generating without optional seed func");
                            mainWidth = firstField;
                            mainHeight = secondField;
//                            edgesVector = mazeGenerator(0, firstField, secondField, false);
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
            
            if ((hasGen.second || hasGenOpt.second || hasLoadBinary.second || hasLoadSvg.second) && canCallSaveFunctions) {
                if (hasSaveBinary.second) {
                    // TODO check file format and validate user input
                    saveBinary(userInputVector[hasSaveBinary.first + 1], edgesVector, mainWidth, mainHeight);
                    printLineWith("calling save binary func");
                    
                }
                if (hasSaveSvg.second) {
                    // TODO check file format and validate user input
                    saveSvg(userInputVector[hasSaveSvg.first + 1], edgesVector, mainWidth, mainHeight);
                    printLineWith("calling save SVG func");
                }
            } else {
                if (hasSaveBinary.second || hasSaveSvg.second) {
                    printLineWith("you must create or load the maze first");
                }
            }
        } else {
            // if (userInputVector[0] != EXIT) {
            printLineWith(INVALID_INPUT_MESSAGE);
            // }
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
//            int x1 =  edge.first.first;
//            int y1 =  edge.first.second;
//            int x2 =  edge.second.first;
//            int y2 =  edge.second.second;
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
//        int x1 =  edge.first.first;
//        int y1 =  edge.first.second;
//        int x2 =  edge.second.first;
//        int y2 =  edge.second.second;
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
