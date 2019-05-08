//
//  Coordinator.hpp
//  s3574983-a2
//
//  Created by Tuan Le on 4/30/19.
//  Copyright © 2019 RMIT. All rights reserved.
//

#ifndef Coordinator_hpp
#define Coordinator_hpp

#include <stdio.h>

class Coordinator {
private:
    int x;
    int y;
    
public:
    Coordinator();

    Coordinator(int x, int y);

    virtual ~Coordinator();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);
};

#endif /* Coordinator_hpp */
