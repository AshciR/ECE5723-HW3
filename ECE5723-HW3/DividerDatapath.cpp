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
                                 bus &r_bus, bus &q_bus,
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
    
    /* If the quotient is 0, then it means you haven't subtracted yet
     so use the inital value (a_bus) in the subtractor */
    if (*this->q_bus == "0" || *this->q_bus == "X") {
        this->which_miniuend = *this->a_bus;
    }
    /* You have initally subtracted, so use the remainder to do
     further subtractions */
    else {
        this->which_miniuend = *this->r_bus;
    }
    
    /* Wire up the internal modules */
    this->quotient = new upCounterRaE(D, *this->clk, *this->rst, L, *this->en_quoCount, *this->q_bus);
    this->subtract = new Subtractor(this->miniuend, *this->b_bus, *this->r_bus);
    this->remChecker = new Comparator(*this->r_bus, *this->b_bus, *this->lesser, *this->equal, *this->greater);
    this->miniuend_reg = new dRegisterRa(this->which_miniuend, *this->clk, *this->rst, this->miniuend);
    
    /* Do the evaluations */
    this->miniuend_reg->evl();
    this->subtract->evl();
    this->remChecker->evl();
    this->quotient->evl();
    
}

void DividerDatapath::printValues(){
    
    std::cout << "Clock: " << *clk << endl;
    std::cout << "Reset: " << *rst << endl;
    std::cout << "A-Bus: " << *a_bus << endl;
    std::cout << "B-Bus: " << *b_bus << endl;
    std::cout << "Remainder: " << *r_bus << endl;
    std::cout << "Quotient: " << *q_bus << endl;
    std::cout << "Enable Q count: " << *en_quoCount << endl;
    std::cout << "Greater: " << *greater << endl;
    std::cout << "Equal: " << *equal << endl;
    std::cout << "Lesser: " << *lesser << endl;
    
    std::cout << "--- Internal Signals ---\n";
    std::cout << "Miniuend into the Reg: " << which_miniuend << endl;
    std::cout << "Miniuend out of the Reg: " << miniuend << endl;
    

}