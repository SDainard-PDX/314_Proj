#pragma once

#include "functional.h"
#include <iostream>

/*
 * Basic error handling, struct
 * build 2 0r 3? errNum errStr errChar? or build with a template to accept 1 of any given type
 */

struct errstruc
{
    void tmInvalid()
    {
        std::cout << "\n";
        Divider();
        std::cout << "\nToo many invalid inputs, returning to main menu.\n\n";
        Divider();
    }
};
