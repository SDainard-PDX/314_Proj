#pragma once

//Createad by Trae Williams

#include "../invoice.hpp"
#include <assert.h>

void init_test();
void complex_init_test(std::string, std::string, std::string, std::string);
void create_test();
void setInvNum_test(int num_in, bool expected);
void getAll_test();

void init_test()
{
    Session_Invoice *test = new Session_Invoice();
    assert(test->getInvNum() == -1);
    assert(test->getSerNum() == "-1");
    assert(test->getProNum() == "-1");
    assert(test->getMemNum() == "-1");
    assert(test->getComments() == "none");
    std::cout << "init() test passed" << std::endl;
    delete test;
}

void complex_init_test(std::string serv_num, std::string pro_num, std::string mem_num, std::string comm_in)
{
    tm *blank = new tm;
    tm *holder= new tm;
    Session_Invoice *test = new Session_Invoice(serv_num, pro_num, mem_num, blank, holder, comm_in);
    assert(test->getSerNum() == serv_num);
    assert(test->getProNum() == pro_num);
    assert(test->getMemNum() == mem_num);
    assert(test->getComments() == comm_in);
    std::cout << "complex_init test passed" << std::endl;
    delete test;
}

void create_test()
{
	Session_Invoice *test = new Session_Invoice();
	std::string yeet;
	assert(test->create(yeet) == false);
	std::cout << "create() test passed" << std::endl;
	delete test;
}

void setInvNum_test(int num_in, bool expected)
{
    Session_Invoice *test = new Session_Invoice();
    if (expected) {
        test->setInvNum(num_in); }
    else {
        test->setInvNum(num_in + 1); }
    assert((test->getInvNum() == num_in) == expected);
    std::cout << "setInvNum() test passed with " << expected << " expected" << std::endl;
}

void getAll_test()
{
    Session_Invoice *test = new Session_Invoice();

    assert(test->getInvNum() == -1);
    std::cout << "getInvNum() test passed" << std::endl;

    assert(test->getSerNum() == "-1");
    std::cout << "getSerNum() test passed" << std::endl;

    assert(test->getProNum() == "-1");
    std::cout << "getProNum() test passed" << std::endl;

    assert(test->getMemNum() == "-1");
    std::cout << "getMemNum() test passed" << std::endl;

    assert(test->getComments() == "none");
    std::cout << "getComments() test passed" << std::endl;

    std::cout << "Passed all get__() tests" << std::endl;
    delete test;
}
