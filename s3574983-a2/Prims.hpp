//
//  Prims.hpp
//  s3574983-a2
//
//  Created by Tuan Le on 5/1/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#ifndef Prims_hpp
#define Prims_hpp

#include <stdio.h>
#include "Generator.hpp"

class Prims: public Generator {
    
    
public:
    vector<Edge> generate();
};

#endif /* Prims_hpp */
