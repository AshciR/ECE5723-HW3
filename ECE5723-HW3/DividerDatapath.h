//
//  DivideDatapath.h
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/18/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#ifndef DivideDatapath_h
#define DivideDatapath_h

#include "classVectorPrimitives.h"
#include "Subtractor.h"

class DividerDatapath{
    
    /* Divider Signals */
    bus *clk, *rst;
    bus *a_bus, *b_bus; // inputs to be divided
    bus *r_bus, *q_bus; // the remainder and the quotient
    
    /* Controller signals */
    bus *en_quoCount; // enable the quotient counter
    bus *greater;     // the remainder is > B_bus
    bus *equal;     // the remainder is = B_bus
    bus *lesser;     // the remainder is < B_bus
    
    /* Internal buses */
    bus subtract_result;
    
    /* The internal modules */
    upCounterRaE* quotient; // Counter that keep track of the quotient
    Comparator* remChecker; // Comparator that determines if remainder > b_bus
    Subtractor* subtract;   // The substractor
    
public:
    
    /* Constructor */
    DividerDatapath(bus &clk, bus &rst,
                    bus &a_bus, bus &b_bus,
                    bus &r_bus, bus q_bus,
                    bus &en_quoCount, bus &greater, bus &equal, bus &lesser);
    
    /* Destructor */
    ~DividerDatapath();
    
    /* Evalulator */
    void eval();
    
};

#endif /* DivideDatapath_h */
