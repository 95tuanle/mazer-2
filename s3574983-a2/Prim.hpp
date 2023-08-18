//
//  Prim.hpp
//  s3574983-a2
//
//  Created by Tuan Le on 5/1/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#ifndef Prim_hpp
#define Prim_hpp

#include <stdio.h>
#include "Generator.hpp"

class Prim : public Generator {


public:
    vector <Edge> generate();
};

#endif /* Prim_hpp */