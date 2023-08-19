//
//  Edge.cpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#include "Edge.hpp"

Edge::Edge() = default;

Edge::~Edge() = default;

Edge::Edge(const Coordinator &coordinator1, const Coordinator &coordinator2) : coordinator1(coordinator1),
                                                                               coordinator2(coordinator2) {}

const Coordinator &Edge::getCoordinator1() const {
    return coordinator1;
}

void Edge::setCoordinator1(const Coordinator &newCoordinator1) {
    Edge::coordinator1 = newCoordinator1;
}

const Coordinator &Edge::getCoordinator2() const {
    return coordinator2;
}

void Edge::setCoordinator2(const Coordinator &newCoordinator2) {
    Edge::coordinator2 = newCoordinator2;
}