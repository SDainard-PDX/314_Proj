//Createad by Trae Williams

#include "invoice_tests.hpp"

/*
g++ -g -o invoice_tests invoice_tests.cpp ../invoice.cpp ../functional.cpp
*/

int main()
{
    std::cout << "\nInvoice Module Tests" << std::endl;
    getAll_test();
    init_test();
    complex_init_test("012345","987654321", "123465789", "Good session");
    setInvNum_test(12, true);

    create_test();
    setInvNum_test(12, false);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
