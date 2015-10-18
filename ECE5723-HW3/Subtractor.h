//
//  Subtractor.h
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/18/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#ifndef Subtractor_h
#define Subtractor_h

class Subtractor {
    bus *i1, *i2, *o1;
public:
    Subtractor(bus& a, bus& b, bus& diff);
    Subtractor();
    void evl();
};

#endif /* Subtractor_h */
