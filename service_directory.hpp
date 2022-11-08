#pragma once

#include "service_item.hpp"

#include <string>
#include <iostream>
#include <fstream>

/*
*/

class Service_DirectoryNode
{
    Service_DirectoryNode();
    explicit Service_DirectoryNode(Service_Item *toAdd);
    ~Service_DirectoryNode();

    Service_Item      *item; //the data
    Service_DirectoryNode  *next; //the pointer
    friend class Service_Directory; //because
};


class Service_Directory
{
    public:
        Service_Directory();
        ~Service_Directory();
        int populate(const std::string& file_in);
        bool add_item(Service_Item *to_add);
        Service_Item * find_item(std::string num_to_find);
        bool edit_item(std::string num_to_edit);
        bool remove_item(std::string num_to_remove);
        bool write_out(std::string file_out);

    protected:
        Service_DirectoryNode *head;
};
