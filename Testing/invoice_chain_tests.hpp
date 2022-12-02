#include "../invoice_chain.hpp"

#include <assert.h>
#include <fstream>

void populate_test();
void populate_G_test(std::string);
void add_invoice_test();
void add_invoice_G_test();
void find_invoice_nh_test();
void find_invoice_M_test(int, bool);
void edit_invoice_test();
void write_out_test(std::string in_file);

void getInvoiceCnt_test();

void add_invoice_G_test()
{
    Session_Invoice *fake = new Session_Invoice();
    Invoice_Chain test = Invoice_Chain();
    assert(test.add_invoice(fake) == true);
    std::cout << "add_Invoice() 'Good' test passed" << std::endl;
}

void add_invoice_test()
{
    Invoice_Chain test = Invoice_Chain();
    assert(test.add_invoice(nullptr) == false);
    std::cout << "add_Invoice() bad input test passed" << std::endl;
}

void populate_G_test(std::string in_file)
{
    int cnt = -1;
    std::string line;
    Invoice_Chain test = Invoice_Chain();
    std::ifstream in(in_file);
    while (!in.eof()) {
        getline(in, line);
        ++cnt;
    }
    in.close();
    assert(test.populate(in_file) == cnt);
    std::cout << "populate() 'Good' test passed" << std::endl;
}

void populate_test()
{
    std::string fake_file = "blank";
    Invoice_Chain test = Invoice_Chain();
    assert(test.populate(fake_file) == 0);
    std::cout << "populate() bad input test passed" << std::endl;
}

void find_invoice_M_test(int inv_num, bool expected)
{
    Session_Invoice *fake = new Session_Invoice();
    if (expected) {
        fake->setInvNum(inv_num); }
    else {
        fake->setInvNum(inv_num + 1); }
    Invoice_Chain *test = new Invoice_Chain();
    test->add_invoice(fake);
    if (expected) {
        assert(test->find_invoice(inv_num) == fake); }
    else {
        assert(test->find_invoice(inv_num) == nullptr); }
    std::cout << "find_Invoice() 'Match' expecting " << expected << " test passed" << std::endl;
    fake = nullptr;
}

void find_invoice_nh_test()
{
    Invoice_Chain test = Invoice_Chain();
    assert(test.find_invoice(0) == nullptr);
    std::cout << "find_Invoice() 'no head' test passed" << std::endl;
}

void edit_invoice_test()
{
    Invoice_Chain test = Invoice_Chain();
    assert(test.edit_invoice(0) == false);
    std::cout << "edit_invoice test passed" << std::endl;
}

void write_out_test(std::string in_file)
{
    Invoice_Chain test = Invoice_Chain();
    test.populate(in_file);
    test.write_out("test.txt");

    std::ifstream I(in_file);
    std::ifstream O("test.txt");

    std::ifstream::pos_type sizeI, sizeO;
    sizeI = I.seekg(0, std::ifstream::end).tellg();
    I.seekg(0, std::ifstream::beg);
    sizeO = O.seekg(0, std::ifstream::end).tellg();
    O.seekg(0, std::ifstream::beg);

    assert(sizeI == sizeO);
    std::cout << "write_out() 'Good' test passed" << std::endl;

    std::remove("test.txt");
}

void getInvoiceCnt_test()
{
    Invoice_Chain test = Invoice_Chain();
    assert(test.getInvoiceCnt() == 1);
    assert(test.getInvoiceCnt() == 2);
    std::cout << "getInvoiceCnt test passed" << std::endl;
}