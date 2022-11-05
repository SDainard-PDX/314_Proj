#pragma once

#include <iostream>
#include <string>

#include "functional.hpp"
#include "error.hpp"

/*
*/

//base class <person>
class Person
{
    public:
        Person();
        ~Person();
        Person(
            int numberIn,
            std::string nameIn,
            std::string addressIn,
            std::string cityIn,
            std::string stateIn,
            int zipIn,
            std::string statusIn,
            char typeIn
        );
        bool create(char type_code);
        bool edit();
        void display() const;

        int getNumber() const;

    //Quick number and type compare w/ == operator overload
        bool operator == (int x) const; // number
        bool operator == (char x) const;//type

    protected:
    //data members
        int         number;     //9 digit primary key
    std::string      name;       //first and last
    std::string      address;
    std::string      city;
    std::string      state;
        int         zip;
    std::string     status;
        char        type;
};
