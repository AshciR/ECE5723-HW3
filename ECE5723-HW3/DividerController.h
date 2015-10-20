//
//  DividerController.h
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/20/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#ifndef DividerController_h
#define DividerController_h

#include "classVectorPrimitives.h"

class DividerController{
    
    /* Divider Signals */
    bus *clk, *rst;
    bus *go, *gtr, *eql, *les; // the inputs
    bus *en_quo, *ready;       // the outputs
    int Nstate, Pstate;
    
public:
    
    /* Constructor */
    DividerController(bus &clk, bus &rst,
                    bus &go, bus &gtr, bus &eql, bus &les,
                    bus &en_quo, bus &ready);
    
    /* Destructor */
    ~DividerController();
    
    /* Evalulator */
    void eval();
    
    /* Print states */
    void printValues();
    
};
#endif /* DividerController_h */
