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
    
    bus comp(4); // the bus that holds the 2s complement
    
    comp = *i2;
    comp = ~comp + "1";
    
    std::cout << "The b is: " << *i2 << std::endl;
    std::cout << "The complemented value is: " << comp << std::endl;
    
    
//    Adder * adder = new Adder(a, b, cin, cout, sum);
//    adder->evl();
//
//    
//    bus result(i1->length() + 1);
//    result = *i1 + *i2 + *i3;
//    int leftIndex = result.length() - 1;
//    *o2 = result.at(leftIndex);
//    *o1 = result.range(leftIndex-1, 0);
}