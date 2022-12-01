#pragma once

#include "invoice.hpp"
#include "service_directory.hpp"
#include "people.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

/*
*/

class Invoice_ChainNode
{
    Invoice_ChainNode();
    explicit Invoice_ChainNode(Session_Invoice *toAdd);
    ~Invoice_ChainNode();

    Session_Invoice    *invoice; //the data
    Invoice_ChainNode  *mem_next;
    Invoice_ChainNode  *pro_next;
    Invoice_ChainNode  *inv_num_next;
    Invoice_ChainNode  *pro_prev;
    Invoice_ChainNode  *mem_prev;
    friend class Invoice_Chain; //because
};


class Invoice_Chain
{
    public:
        Invoice_Chain();
        ~Invoice_Chain();
        int populate(const std::string& file_in);
        bool add_invoice(Session_Invoice *to_add);
        Session_Invoice * find_invoice(int inv_num);
        bool edit_invoice(int invoice_number_to_edit);
        bool remove_invoice(int invoice_number_to_remove);
        void display_all();
        bool write_out(std::string file_out);
		bool member_report(std::string id, People *memDS, People *proDS, Service_Directory *servDS);
		bool provider_report(std::string id, People *proDS, People *memDS, Service_Directory *servDS);
		bool acts_payable(People *proDS, Service_Directory *servDS);

        int getInvoiceCnt();

    protected:
        int invoice_count;
        Invoice_ChainNode *mem_head;
        Invoice_ChainNode *pro_head;
        Invoice_ChainNode *inv_num_head;
};
