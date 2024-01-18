//
//  Edge.hpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#ifndef Edge_hpp
#define Edge_hpp

#include <cstdio>
#include "Coordinator.hpp"

class Edge {
private:
    Coordinator coordinator1;
    Coordinator coordinator2;

public:
    Edge();

    Edge(const Coordinator &coordinator1, const Coordinator &coordinator2);

    virtual ~Edge();

    const Coordinator &getCoordinator1() const;

    void setCoordinator1(const Coordinator &newCoordinator1);

    const Coordinator &getCoordinator2() const;

    void setCoordinator2(const Coordinator &newCoordinator2);
};

#endif /* Edge_hpp */
