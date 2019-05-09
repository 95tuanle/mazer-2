//
//  Generator.cpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#include "Generator.hpp"

Generator::Generator() {}

Generator::Generator(int seed, int width, int height) : seed(seed), width(width), height(height) {}

Generator::~Generator() {

}

int Generator::getSeed() const {
    return seed;
}

void Generator::setSeed(int seed) {
    Generator::seed = seed;
}

int Generator::getWidth() const {
    return width;
}

void Generator::setWidth(int width) {
    Generator::width = width;
}

int Generator::getHeight() const {
    return height;
}

void Generator::setHeight(int height) {
    Generator::height = height;
}