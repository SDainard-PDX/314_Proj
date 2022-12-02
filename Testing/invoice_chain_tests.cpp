#include "invoice_chain_tests.hpp"

/*
g++ -g -o invoice_chain_tests invoice_chain_tests.cpp ../invoice_chain.cpp ../invoice.cpp
 ../functional.cpp ../person.cpp ../people.cpp ../service_item.cpp ../service_directory.cpp
 */

int main()
{
    std::cout << "\n\tInvoice Chain Module Tests" << std::endl;
    add_invoice_G_test();
    add_invoice_test();
    populate_G_test("../invoices.csv");
    populate_test();
    find_invoice_nh_test();
    find_invoice_M_test(1234, true);
    find_invoice_M_test(1234, false);
    edit_invoice_test();
    getInvoiceCnt_test();
    write_out_test("../invoices.csv");
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
