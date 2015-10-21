//
//  DividerDesign.cpp
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/20/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#include "DividerDesign.h"

DividerDesign::DividerDesign(bus &clk, bus &rst,
                             bus &a_bus, bus &b_bus, bus &go,
                             bus &r_bus, bus &q_bus, bus &ready)
{
    
    /* Initalize Values */
    this->clk = &clk;
    this->rst = &rst;
    this->a_bus = &a_bus;
    this->b_bus = &b_bus;
    this->go = &go;
    this->r_bus = &ready;
    this->q_bus = &q_bus;
    this->ready = &ready;
    
    /* Wire up the Datapath */
    this->DP = new DividerDatapath(clk, rst, a_bus, b_bus, r_bus, q_bus, enableQuo, greater, equal, lesser);
    
    /* Wire up the Controller */
    this->CT = new DividerController(clk, rst, go, greater, equal, lesser, enableQuo, ready);
}

/* The evaluation function */
void DividerDesign::eval() {
    DP -> eval();
    CT -> eval();
}

/* Prints the values on the busses */
void DividerDesign::printValues() {
    
    std::cout << "Clk: " << *clk << endl;
    std::cout << "Reset: " << *rst << endl;
    
    std::cout << "Go: " << *go << endl;
    std::cout << "A Bus: " << *a_bus << endl;
    std::cout << "B Bus: " << *b_bus << endl;
    
    std::cout << "Quotient: " << *q_bus << endl;
    std::cout << "Remainder: " << *r_bus << endl;
    std::cout << "Ready: " << *ready << endl;
   
}