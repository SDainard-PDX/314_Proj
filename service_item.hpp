#pragma once

#include <iostream>
#include <string>

#include "functional.hpp"
#include "error.hpp"

/*
*/

class Service_Item
{
    public:
        Service_Item();
        ~Service_Item();
        Service_Item(
            std::string number,
            std::string name,
            double      fee
        );
        bool create();
        bool edit();
        void display() const;

        std::string getNum() const;
        std::string getName() const;
        double      getFee() const;

    //Quick number and type compare w/ == operator overload
        bool operator == (std::string match) const; // number

    protected:
    //data members
    std::string number;
    std::string name;
        double  fee;
};
