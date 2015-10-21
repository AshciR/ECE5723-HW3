//
//  DivideDatapath.cpp
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/18/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#include "DividerDatapath.h"

DividerDatapath::DividerDatapath(bus &clk, bus &rst,
                                 bus &a_bus, bus &b_bus,
                                 bus &r_bus, bus q_bus,
                                 bus &en_quoCount, bus &greater, bus &equal, bus &lesser){
    /* Initialize the values */
    this->clk = &clk;
    this->rst = &rst;
    this->a_bus = &a_bus;
    this->b_bus = &b_bus;
    this->r_bus = &r_bus;
    this->q_bus = &q_bus;
    this->en_quoCount = &en_quoCount;
    this->greater = &greater;
    this->equal = &equal;
    this->lesser = &lesser;
    
}

void DividerDatapath::eval(){
    
    /* Needed for the Up Counter constructor */
    bus D; // Loaded Count Data (N/A)
    bus L; // Load trigger (N/A)
    
    /* Wire up the internal modules */
    this->quotient = new upCounterRaE(D, *this->clk, *this->rst, L, *this->en_quoCount, *this->q_bus);
    this->subtract = new Subtractor(this->subtract_result, *this->b_bus, this->subtract_result);
    this->remChecker = new Comparator(*this->r_bus, *this->b_bus, *this->lesser, *this->equal, *this->greater);
    
    /* If the quotient is 0, then it means you haven't subtracted yet
       so use the inital value (a_bus) in the subtractor */
    if (*this->q_bus == "0") {
        this->r_bus = this->a_bus;
    }
    
    /* Do the evaluations */
    this->quotient->evl();
    this->subtract->evl();
    this->remChecker->evl();
    
}