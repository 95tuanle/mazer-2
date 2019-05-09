//
//  RecursiveBacktracking.hpp
//  s3574983-a2
//
//  Created by Tuan Le on 5/1/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#ifndef RecursiveBacktracking_hpp
#define RecursiveBacktracking_hpp

#include <stdio.h>
#include "Generator.hpp"

class RecursiveBacktracking: public Generator {
    
    
public:
    vector<Edge> generate();
};

#endif /* RecursiveBacktracking_hpp */