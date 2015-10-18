//
//  Tester.cpp
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/18/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#include <iostream>
#include "utilityFunctions.h"
#include "classVectorPrimitives.h"

void testUtil(){
    
    char result = _and('1', '1');
    char result1 = _and('0', '1');
    char result2 = _and('X', '1');
    
    std::cout << "Result 0: " << result << std::endl;
    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;


}

void testAnd(){
    
    char a = '1';
    char b = '1';
    char ci = '0';
    char co, sum;

    fullAdder(a, b, ci, co, sum);
    
    std::cout << "1 + 1: " << std::endl;
    std::cout << "The sum is: " << sum << std::endl;
    std::cout << "The carry out is: " << co << std::endl;
    
}

void testBus(){
    
    bus a ("10011001");
    bus b ("10000001");
    
    std::cout << "Making 2 8-bit buses\n";
    std::cout << "The value on bus a is: " << a << std::endl;
    std::cout << "The value on bus b is: " << b << std::endl;
    
    std::cout << "The value a & b is: " << (a&b) << std::endl;
    std::cout << "The value a | b is: " << (a|b) << std::endl;
    
    
}

void testAdder(){
    
    bus a ("0001"); // 1
    bus b ("0100"); // 4
    bus sum(4);
    bus cout, cin("0");
    
    Adder * adder = new Adder(a, b, cin, cout, sum);
    adder->evl();
    
    std::cout << "The value on bus a is: " << a << std::endl;
    std::cout << "The value on bus b is: " << b << std::endl;
    
    std::cout << "Adding 1 + 4\n";
    std::cout << "The sum is: " << sum << std::endl;
    std::cout << "The cout is: " << cout << std::endl;
    
    
}