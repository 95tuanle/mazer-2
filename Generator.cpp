//
//  Generator.cpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#include "Generator.hpp"

Generator::Generator() = default;

Generator::Generator(int seed, int width, int height) : seed(seed), width(width), height(height) {}

Generator::~Generator() = default;

int Generator::getSeed() const {
    return seed;
}

void Generator::setSeed(int newSeed) {
    Generator::seed = newSeed;
}

int Generator::getWidth() const {
    return width;
}

void Generator::setWidth(int newWidth) {
    Generator::width = newWidth;
}

int Generator::getHeight() const {
    return height;
}

void Generator::setHeight(int newHeight) {
    Generator::height = newHeight;
}