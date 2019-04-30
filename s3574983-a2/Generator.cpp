//
//  Generator.cpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#include "Generator.hpp"

Generator::Generator(const vector<Edge> &vectors) : vectors(vectors) {}

Generator::Generator() {}

Generator::~Generator() {

}

const vector<Edge> &Generator::getVectors() const {
    return vectors;
}

void Generator::setVectors(const vector<Edge> &vectors) {
    Generator::vectors = vectors;
}
