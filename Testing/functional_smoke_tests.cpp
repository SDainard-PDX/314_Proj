//
// Created by sdainard on 11/22/22.
//

#include "functional_tests.hpp"
/* 
g++ -g -Wall -Wno-deprecated -o functional_smoke_test functional_smoke_tests.cpp functional.cpp
*/


using namespace functional_tests;

int main() {
    smoke_tests();
    return 0;
}
