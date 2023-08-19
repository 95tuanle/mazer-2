//
//  Coordinator.cpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#include "Coordinator.hpp"

Coordinator::Coordinator() = default;

Coordinator::Coordinator(int x, int y) : x(x), y(y) {}

int Coordinator::getX() const {
    return x;
}

void Coordinator::setX(int newX) {
    Coordinator::x = newX;
}

int Coordinator::getY() const {
    return y;
}

void Coordinator::setY(int newY) {
    Coordinator::y = newY;
}

Coordinator::~Coordinator() = default;