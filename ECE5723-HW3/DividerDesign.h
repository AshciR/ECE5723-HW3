//
//  DividerDesign.h
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/20/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#ifndef DividerDesign_h
#define DividerDesign_h

#include "DividerController.h"
#include "DividerDatapath.h"

class DividerDesign
{
    bus *clk, *rst;
    bus *a_bus, *b_bus, *go;
    bus *r_bus, *q_bus, *ready;
    
    // Internal busses
    bus enableQuo; // the count enable for the quotient tracker
    bus greater;
    bus equal;
    bus lesser;
    
    // module
    DividerDatapath* DP;
    DividerController* CT;

public:
    DividerDesign ( bus &clk, bus &rst,
                    bus &a_bus, bus &b_bus, bus &go,
                    bus &r_bus, bus &q_bus, bus &ready);
    ~DividerDesign();
    void eval();
    void printValues();
};

#endif /* DividerDesign_h */
