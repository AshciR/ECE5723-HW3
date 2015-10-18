//
//  Subtractor.cpp
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/18/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#include <stdio.h>
#include "classVectorPrimitives.h"
#include "Subtractor.h"

Subtractor::Subtractor(bus& a, bus& b, bus& diff) :
i1(&a), i2(&b), o1(&diff)
{
    o1->fill('X');
}
void Subtractor::evl () {
    
    bus comp; // the bus that holds the 2s complement
    bus tempAns; // holds the answer before truncating
    
    comp = ~(*i2) + "1"; // Do 2s complement on Bus B
    
    /* Logic Subtraction is equal to bus A + the 2s complement of bus B */
    tempAns = *i1 + comp;
    
    /* Get rid of the MSB, to get the correct value */
    *o1 = tempAns.range(tempAns.length() - 2, 0);
    
}