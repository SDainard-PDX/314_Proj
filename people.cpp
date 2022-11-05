#include "people.hpp"

using namespace std;

PeopleNode::PeopleNode():person(nullptr), next(nullptr) {}

PeopleNode::PeopleNode(Person *toAdd):person(toAdd), next(nullptr) {}

PeopleNode::~PeopleNode()
{
    delete person;
    next = nullptr;
    delete next;
}


People::People(): head(nullptr) {}

People::~People()
{
    //todo if(head) { del_People(head); }
    delete head;
    head = nullptr;
}

int People::populate(string file_in, char type_in)
{
    //open the indicated file or return
    ifstream in_file(file_in);
    if(!in_file.is_open()) return 0;

    //temp variables for input
    string  numIn = {0};
    string  nameIn = {0};
    string  addressIn = {0};
    string  cityIn = {0};
    string  stateIn = {0};
    string  zIn = {0};
    string  statusIn = "Valid";
    int count = 0;  //temp variable to return items input

    //loop over input until EOF
    while(getline(in_file, numIn, ','))
    {
        //get temp values from file
        int numberIn = stoi(numIn);
        getline(in_file, nameIn, ',');
        getline(in_file, addressIn, ',');
        getline(in_file, cityIn, ',');
        getline(in_file, stateIn, ',');
        getline(in_file, zIn, ',');
        int zipIn = stoi(zIn);
        //create person to add
        Person *toAdd = new Person(numberIn, nameIn, addressIn, cityIn, stateIn, zipIn, statusIn, type_in);

        //add the vehicle to the table & increment count
        add_person(toAdd);
        count++;
    }

    in_file.close(); //close file

    return count; //return the number read in
}

bool People::add_person(Person *toAdd)
{
    PeopleNode *newPerson = new PeopleNode(toAdd);
    PeopleNode *curr = head, *prev = nullptr;

    if (!head) { head = newPerson; }
    else {
        while (toAdd->getNumber() > curr->person->getNumber() && curr->next) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr->next) { curr->next = newPerson;}
        else {
            prev->next = newPerson;
            newPerson->next = curr;
        }
    }
    return true;
};

Person * People::find_person(int match)
{
    if(!head) return nullptr;
    Person *result = nullptr;

    while (head && !result) {
        if(head->person->getNumber() == match) result = head->person;
        head = head->next;
    }
    return result;
}

bool People::write_out(string file_out) { return true;}
