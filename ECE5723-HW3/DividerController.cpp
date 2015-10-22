//
//  DividerController.cpp
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/20/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#include "DividerController.h"

DividerController::DividerController(bus &clk, bus &rst,
                                     bus &go, bus &gtr, bus &eql, bus &les,
                                     bus &en_quo, bus &ready){
    
    /* Initalize the values */
    this->clk = &clk;
    this->rst = &rst;
    this->go = &go;
    this->gtr = &gtr;
    this->eql = &eql;
    this->les = &les;
    this->en_quo = &en_quo;
    this->ready = &ready;
    
    Pstate = 0;
    Nstate = 0;
    
}

/* Does the evaluation */
void DividerController::eval(){
    
    /* Set the control signals to their inital values */
    *ready = "0";
    *en_quo = "0";
    
    /* State Transitions */
    switch (Pstate) {
        
        /* Idle */
        case 0:
            if (*rst == "1" )
                Nstate = 0;
            else if (*go == "P") // the go pulse
                Nstate = 1;
            else
                Nstate = 0;
            break;
        
        /* The Subtraction state */
        case 1:
            if (*rst == "1" )
                Nstate = 0;
            
            // The remainder is greater than divisor
            else if (*gtr == "1")
                Nstate = 2; // So keep on subracting
            
            // The remainder is equal to the divisor
            else if (*eql == "1")
                Nstate = 3; // Stop subracting
            
            // The remainder is less than the divisor
            else if (*les == "1")
                Nstate = 3; // Stop subracting
            
            // Shouldn't end up in this state
            else
                Nstate = 0; // Something bad happened.
            break;
         
        /* Increase the Quotient */
        case 2:
            if (*rst == "1")
                Nstate = 0;
            else
                Nstate = 1; // go back to the subtraction state
            break;
        
        /* Finished division */
        case 3:
            if (*rst == "1")
                Nstate = 0;
            else
                Nstate = 0; // go back to Idle
            break;
            
        /* Something bad happened */
        default:
            Nstate = 0; break;
    
    } // END OF SWITCH
    
    /* Control Signals */
    switch (Pstate) {
        
        /* Idle */
        case 0:
            if (*rst == "1") {
                *en_quo = "0";
                *ready = "0";
            }
            else{
                *en_quo = "0";
                *ready = "0";
            }
            break;
        
        /* Subtraction */
        case 1:
            if (*rst == "1") {
                *en_quo = "0";
                *ready = "0";
            }
            else{
                *en_quo = "1";
                *ready = "0";
            }
            break;
            
        /* Increase Quotient */
        case 2:
            if (*rst == "1") {
                *en_quo = "0";
                *ready = "0";
            }
            else{
                *en_quo = "0";
                *ready = "0";
            }
            break;
            
        /* Finished */
        case 3:
            if (*rst == "1") {
                *en_quo = "0";
                *ready = "0";
            }
            else{
                *en_quo = "0";
                *ready = "P";
            }
            break;
            
        /* Something bad happened */
        default:
            break;
    }
    
    /* Next state process */
    if (*rst == "1") {
        Pstate = 0;
    }
    else if (*clk == "P"){
        Pstate = Nstate;
    }
    
}

void DividerController::printValues(){
    
    std::cout << "Clk: " << *clk << endl;
    std::cout << "Reset: " << *rst << endl;
    std::cout << "Go: " << *go << endl;
    std::cout << "Greater: " << *gtr << endl;
    std::cout << "Equal: " << *eql << endl;
    std::cout << "Lesser: " << *les << endl;
    std::cout << "Enable Quo: " << *en_quo << endl;
    std::cout << "Ready: " << *ready << endl;
    std::cout << "Present State: " << Pstate << endl;
    std::cout << "Next State: " << Nstate << endl;
    
}