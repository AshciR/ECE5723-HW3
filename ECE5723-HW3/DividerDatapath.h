//
//  DividerDatapath.h
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/18/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#include "classVectorPrimitives.h"
#include "Subtractor.cpp"

#ifndef DividerDatapath_h
#define DividerDatapath_h

class DividerDatapath{
    
    /* Divider Signals */
    bus *clk, *rst;
    bus *a_bus, *b_bus; // inputs to be divided
    bus *r_bus, *q_bus; // the remainder and the quotient
    
    /* Controller signals */
    bus *en_quoCount; // enable the quotient counter
    bus *greater;     // the remainder is > B_bus
    
    /* The internal modules */
    upCounterRaE* quotient; // Counter that keep track of the quotient
    Comparator* remChecker; // Comparator that determines if remainder > b_bus
    Subtractor* subtract;   // The substractor
    
public:
    
    /* Constructor */
    DividerDatapath(bus &clk, bus &rst,
                    bus &a_bus, bus &b_bus,
                    bus &r_bus, bus q_bus,
                    bus &en_quoCount, bus &greater);
    
    /* Destructor */
    ~DividerDatapath();
    
    /* Evalulator */
    void eval();
    
};

#endif /* DividerDatapath_h */
