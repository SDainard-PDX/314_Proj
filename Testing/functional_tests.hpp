//
// Created by sdainard on 11/22/22.
//

#include "functional_example.hpp"
/*  Because I wrote a version for this only it is as above
 * normally it would be as below due to directory config
#include "../functional.hpp"

*/

#include <cassert>
#include <strstream>
#include <string>
#include <sstream>
#include <iostream>

namespace functional_tests {

//declare test groups here
    void all_tests();
    void smoke_tests();
    void verification_tests();


//declare all the unit tests here
    void divider_test();
    void clearscn_test();
    void sft_test();
    void allLet_test(std::string, bool);
    void allNum_test(std::string, bool);
    void rightsize_test(std::string, int, int, bool);


//these are testing groups

    void smoke_tests() {
        std::cout << "\tFunctional smoke test:" << std::endl;
        /* normally wouldn't include clear screen for obvious issues with losing anything
        * output before it; it's included here commented out as an example.
            clearscn_test(); */
        divider_test();
        sft_test();
        allLet_test("thisisallletters", true);
        allNum_test("1", true);
        rightsize_test("this string is 28 characters", 28, 28, true);
        std::cout << "Smoke Tests: Passed, Functional" << std::endl;
    }

    void verification_tests() {
        std::cout << "\tFunctional verification tests:" << std::endl;
        allLet_test("thishas1numberinit", false);
        allNum_test("123a456", false);
        rightsize_test("this string is 27 characters", 29, 100, false);
        rightsize_test("this string is 27 characters", 0, 27, false);
        std::cout << "Verification Tests: Passed, Functional" << std::endl;
    }

//this is a block test AKA a small system test as you can see it contains both the
//smoke test for functional and the verification test
    void all_tests() {
        std::cout << "\nFunctional Unit Tests" << std::endl;
        smoke_tests();
        verification_tests();
        std::cout << std::endl;
    }


// these are unit test

    void divider_test() //covers ln 5-9
    {
        std::string x;
        std::string y = "************************************************";

        std::stringstream q;
        std::streambuf *mitt = q.rdbuf();
        Divider(mitt);
        getline(q, x);
        assert(x == y);
        std::cout << "PASSED: Divider()" << std::endl; //if assert fails this doesn't print
    }

    void clearscn_test() //covers ln 11-15
    {
        std::cout << "***** CLEAR SCREEN HAS FAILED *****" << std::endl;
        assert(ClearScreen() == true);
        std::cout << "PASSED: ClearScreen()" << std::endl;
    }

    void sft_test() //covers ln 17-22
    {
        std::string s;
        int i;

        std::istrstream in("12 extra input");
        std::streambuf *x = in.rdbuf();

        in >> i;
        Safety(x);
        getline(in, s);
        assert(s == "");
        std::cout << "PASSED: Safety()" << std::endl;
    }

    void allNum_test(std::string input, bool expected) //covers ln 89-95
    {
        assert(allNum(input) == expected);
        std::cout << "PASSED: allNum() expecting " << expected << std::endl;
    }

    void allLet_test(std::string input, bool expected) //covers ln 97-104
    {
        assert(allLet(input) == expected);
        std::cout << "PASSED: allLet() expecting " << expected << std::endl;
    }

    void rightsize_test(std::string x, int min, int max, bool expected) //covers ln 106-110
    {
        assert(rightSize(x, min, max) == expected);
        std::cout << "PASSED: rightSize() expecting " << expected << std::endl;
    }
}