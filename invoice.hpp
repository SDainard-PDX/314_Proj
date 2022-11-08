#pragma once

#include <iostream>
#include <string>
#include <ctime>

#include "functional.hpp"
#include "error.hpp"

/*
*/

class Session_Invoice
{
    public:
        Session_Invoice();
        ~Session_Invoice();
        bool create(std::string pro);
        bool edit(std::string pro);
        void display() const;

        std::string getSerNum() const;
        std::string getProNum() const;
        std::string getMemNum() const;

    protected:
    std::string serv_code;
    std::string pro_num;
    std::string mem_num;
    tm          *sub_time;
    tm          *serv_date;
    std::string comments;
};
