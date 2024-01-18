//
//  GrowingTree.hpp
//  s3574983-a2
//
//  Created by Tuan Le on 5/1/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#ifndef GrowingTree_hpp
#define GrowingTree_hpp

#include <cstdio>
#include "Generator.hpp"

class GrowingTree : public Generator {


public:
    vector<Edge> generate();
};

#endif /* GrowingTree_hpp */
