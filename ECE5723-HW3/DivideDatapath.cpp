//
//  DivideDatapath.cpp
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/18/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#include <stdio.h>
#include "DivideDatapath.h"

DividerDatapath::DividerDatapath(bus &clk, bus &rst,
                                 bus &a_bus, bus &b_bus,
                                 bus &r_bus, bus q_bus,
                                 bus &en_quoCount, bus &greater){
    /* Initialize the values */
    this->clk = &clk;
    this->rst = &rst;
    this->a_bus = &a_bus;
    this->b_bus = &b_bus;
    this->r_bus = &r_bus;
    this->q_bus = &q_bus;
    this->en_quoCount = &en_quoCount;
    this->greater = &greater;
    
}

void DividerDatapath::eval(){
    
    //upCounterRaE (bus& D, bus& C, bus& R, bus& L, bus& E, bus& Q);
    //
    bus D; // Loaded Count Data (N/A)
    bus L; // Load trigger (N/A)
    
    this->quotient = new upCounterRaE(D, *this->clk, *this->rst, L, *this->en_quoCount, *this->q_bus);
    
    
    
}