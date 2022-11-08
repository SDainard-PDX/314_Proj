#include "service_directory.hpp"

using namespace std;

Service_DirectoryNode::Service_DirectoryNode():item(nullptr), next(nullptr) {}

Service_DirectoryNode::Service_DirectoryNode(Service_Item *toAdd):item(toAdd), next(nullptr) {}

Service_DirectoryNode::~Service_DirectoryNode()
{
    delete item;
    item = nullptr;
    next = nullptr;
    delete next;
}


Service_Directory::Service_Directory(): head(nullptr) {}

Service_Directory::~Service_Directory()
{
    Service_DirectoryNode *del;
    while(head) {
        del = head;
        head = head->next;
        delete del;
    }
}

int Service_Directory::populate(const string& file_in)
{
    //open the indicated file or return
    ifstream in_file(file_in);
    if(!in_file.is_open()) return 0;

    //temp variables for input
    string  numIn = {0};
    string  nameIn = {0};
    double  feeIn = 0.0;
    int count = 0;  //temp variable to return items input

    //loop over input until EOF
    while(getline(in_file, numIn, ','))
    {
        //get temp values from file
        getline(in_file, nameIn, ',');
        cin >> feeIn;
        Safety();
        //create person to add
        Service_Item *toAdd = new Service_Item(numIn, nameIn, feeIn);

        //add the vehicle to the table & increment count
        add_item(toAdd);
        count++;
    }

    in_file.close(); //close file

    return count; //return the number read in
}

bool Service_Directory::add_item(Service_Item *toAdd)
{
    Service_DirectoryNode *newItem = new Service_DirectoryNode(toAdd);
    Service_DirectoryNode *curr = head, *prev = nullptr;

    if (!head) { head = newItem; }
    else {
        while (toAdd->getNum() > curr->item->getNum() && curr->next) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr->next) { curr->next = newItem;}
        else {
            if(prev) prev->next = newItem;
            newItem->next = curr;
        }
    }
    return true;
}

bool Service_Directory::edit_item(std::string edit)
{
    if(!head) {return false; }
    Service_Item *temp = find_item(edit);
    return temp->edit();
}

bool Service_Directory::remove_item(string remove)
{
    Service_DirectoryNode *curr = head, *prev = nullptr, *del = nullptr;

    if (!head) { return false; }
    else {
        while (curr) {
            if (curr->item->getNum() == remove) {
                del = curr;
                if (curr == head) { head = curr->next; }
                else { prev->next = curr->next; }
                delete del;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return true;
}

Service_Item * Service_Directory::find_item(string match)
{
    if(!head) return nullptr;
    Service_DirectoryNode *curr = head;
    Service_Item *result = nullptr;

    while (curr && !result) {
        if(curr->item->getNum() == match) result = curr->item;
        curr = curr->next;
    }
    return result;
}

bool Service_Directory::write_out(string file_out)
{
    ofstream output_file(file_out);
    if(!output_file.is_open()) return false;

    Service_DirectoryNode *curr = head;
    while(curr) {
        Service_Item *temp = curr->item;
        output_file << temp->getNum() << "," << temp->getName() << "," << temp->getFee() << endl;
        curr = curr->next;
    }

    output_file.close();
    return true;
}
