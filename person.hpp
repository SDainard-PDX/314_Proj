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
            std::string numberIn,
            std::string nameIn,
            std::string addressIn,
            std::string cityIn,
            std::string stateIn,
            std::string zipIn,
            std::string statusIn,
            char typeIn
        );
        bool create(char type_in);
        bool edit();
        void display() const;

        std::string getNumber() const;
        std::string getName() const;
        std::string getAddress() const;
        std::string getCity() const;
        std::string getState() const;
        std::string getZip() const;
        std::string getStatus() const;

    //Quick number and type compare w/ == operator overload
        bool operator == (std::string x) const; // number
        bool operator == (char x) const;//type

    protected:
    //data members
    std::string     number;     //9 digit primary key
    std::string     name;       //first and last
    std::string     address;
    std::string     city;
    std::string     state;
    std::string     zip;
    std::string     status;
        char        type;
};
