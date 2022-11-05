#pragma once

#include <iostream>
#include <string>

#include "functional.hpp"

struct errstruc
{
    void gen(std::string message)
    {
        std::cout << "\n";
        Divider();
        std::cout << "\n" << message << "\n\n";
        Divider();
    }

    void genIntMax(std::string value, int max_size)
    {
        std::cout << "\n";
        Divider();
        std::cout << "\n" << value << " is required and must be < " << max_size << " char\n\n";
        Divider();
    }
};
