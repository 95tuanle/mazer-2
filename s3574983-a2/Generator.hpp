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
    int seed;
    int width;
    int height;

public:
    Generator();

    Generator(int seed, int width, int height);

    virtual ~Generator();

    int getSeed() const;

    void setSeed(int seed);

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);
};

#endif /* Generator_hpp */