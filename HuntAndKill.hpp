//
//  HuntAndKill.hpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#ifndef HuntAndKill_hpp
#define HuntAndKill_hpp

#include <cstdio>
#include "Generator.hpp"

class HuntAndKill : public Generator {


public:
    vector<Edge> generate();
};

#endif /* HuntAndKill_hpp */
