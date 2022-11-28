#include "people.hpp"

using namespace std;

PeopleNode::PeopleNode():person(nullptr), next(nullptr) {}

PeopleNode::PeopleNode(Person *toAdd):person(toAdd), next(nullptr) {}

PeopleNode::~PeopleNode()
{
    delete person;
    person = nullptr;
    next = nullptr;
    delete next;
}


People::People(): head(nullptr) {}

People::~People()
{
    PeopleNode *del;
    while(head) {
        del = head;
        head = head->next;
        delete del;
    }
}

int People::populate(const string& file_in, char type_in)
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
    string  zipIn = {0};
    string  statusIn = {0};
    int count = 0;  //temp variable to return items input

    //loop over input until EOF
    while(getline(in_file, numIn, ','))
    {
        //get temp values from file
        getline(in_file, nameIn, ',');
        getline(in_file, addressIn, ',');
        getline(in_file, cityIn, ',');
        getline(in_file, stateIn, ',');
        getline(in_file, zipIn, ',');
        getline(in_file, statusIn);
        //create person to add
        Person *toAdd = new Person(numIn, nameIn, addressIn, cityIn, stateIn, zipIn, statusIn, type_in);

        //add the vehicle to the table & increment count
        if (!add_person(toAdd)) delete toAdd; //if add fails ensures no leak
        count++;
    }

    in_file.close(); //close file

    return count; //return the number read in
}

bool People::add_person(Person *toAdd)
{
    PeopleNode *newPerson = new PeopleNode(toAdd);
    PeopleNode *curr = head, *prev = nullptr;
    if (!toAdd) { return false; }

    if (!head) { head = newPerson; }
    else {
        while (toAdd->getNumber() > curr->person->getNumber() && curr->next) {
            //ensures not adding a number that exists
            if ( toAdd->getNumber() == curr->person->getNumber() ) {
                cout << "\n\tCannot add new person, id number already exists.\n" << endl;
                return false;
            }
            prev = curr;
            curr = curr->next;
        }
        if (!curr->next) { curr->next = newPerson; }
        else {
            if(prev) { prev->next = newPerson; }
			else {
				head = newPerson;
			}

            newPerson->next = curr;
        }
    }
    return true;
}

bool People::edit_item(std::string edit)
{
    if(!head) {return false; }
    Person *temp = find_person(edit);
    return temp->edit();
}

bool People::remove_person(string remove)
{
    PeopleNode *curr = head, *prev = nullptr, *del = nullptr;

    if (!head) { return false; }
    else {
        while (curr) {
            if (curr->person->getNumber() == remove) {
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

Person * People::find_person(string match)
{
    if(!head) return nullptr;
    PeopleNode *curr = head;
    Person *result = nullptr;

    while (curr && !result) {
        if(curr->person->getNumber() == match) result = curr->person;
        curr = curr->next;
    }
    return result;
}

void People::display_all()
{
    if(!head) return;
    PeopleNode *curr = head;
    while (curr) {
        curr->person->display();
        cout << endl;
    }
}

bool People::write_out(string file_out)
{
    ofstream output_file(file_out);
    if(!output_file.is_open()) return false;

    PeopleNode *curr = head;
    while(curr) {
        Person *temp = curr->person;
        output_file << temp->getNumber() << "," << temp->getName() << "," << temp->getAddress()
            << "," << temp->getCity() << "," << temp->getState() << "," << temp->getZip() << ","
            << temp->getStatus() << endl;
        curr = curr->next;
    }

    output_file.close();
    return true;
}
