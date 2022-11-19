#pragma once

#include <iomanip>
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
        Session_Invoice(
                std::string servNumIn,
                std::string proNumIn,
                std::string memNumIn,
                struct tm *subTimeIn,
                struct tm *servDateIn,
                std::string commIn);
        Session_Invoice * create(std::string pro);
        bool edit();
        void display() const;

        int getInvNum() const;
        std::string getSerNum() const;
        std::string getProNum() const;
        std::string getMemNum() const;
        tm          *getServDate() const;
        tm          *getSubTime() const;
        std::string getComments() const;

        void setInvNum(int cnt_in);

    protected:
        int         invoice_num;
        std::string serv_code;
        std::string pro_num;
        std::string mem_num;
        tm          *serv_date;
        tm          *sub_time;
        std::string comments;
};
