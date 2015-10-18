//
//  Tester.cpp
//  ECE5723-HW3
//
//  Created by Richard Walker on 10/18/15.
//  Copyright © 2015 Richard Walker. All rights reserved.
//

#include <iostream>
#include "utilityFunctions.h"

void testUtil(){
    
    char result = _and('1', '1');
    char result1 = _and('0', '1');
    char result2 = _and('X', '1');
    
    std::cout << "Result 0: " << result << std::endl;
    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;


}

void testAdder(){
    
    char a = '1';
    char b = '1';
    char ci = '0';
    char co, sum;

    fullAdder(a, b, ci, co, sum);
    
    std::cout << "1 + 1: " << std::endl;
    std::cout << "The sum is: " << sum << std::endl;
    std::cout << "The carry out is: " << co << std::endl;
    
}