//
//  Generator.hpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#ifndef Generator_hpp
#define Generator_hpp

#include <stdio.h>
#include <vector>
#include "Edge.hpp"

using namespace std;

class Generator {
private:
    vector<Edge> vectors;
public:
    Generator();

    Generator(const vector<Edge> &vectors);

    virtual ~Generator();

    const vector<Edge> &getVectors() const;

    void setVectors(const vector<Edge> &vectors);
};

#endif /* Generator_hpp */
