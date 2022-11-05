#include "person.hpp"

using namespace std;

//<person>
Person::Person(): number(-1), name("none"), address("blank"),city("blank"),
    state("XX"), zip(-1), status("Valid"), type('x') {}

Person::~Person() {}

Person::Person(int numberIn, string nameIn, string addressIn, string cityIn,
               string stateIn, int zipIn, string statusIn, char typeIn):
                number(numberIn), name(nameIn), address(addressIn),city(cityIn),
                state(stateIn), zip(zipIn), status(statusIn), type(typeIn) {}

bool Person::create(char type_code){
    errstruc ERS;

    try
    {
        cout << "Please enter the id number of the person: ";
        cin >> number;
        Safety();
        if(!rightSize(number, 9, 9)) throw 'I';

        cout << "Please enter the name of the person(max 25 char): ";
        getline(cin,name);
        if(!rightSize(name, 1, 25)) throw 'N';

        if(type_code == 'c') return true; //ChocAn Manager, no other info needed

        cout << "Please enter the address of the person(max 25 char): ";
        getline(cin,address);
        if(!rightSize(address, 1, 25)) throw 'A';

        cout << "Please enter the city of the person(max 14 char): ";
        getline(cin,city);
        if(!rightSize(city, 1, 14)) throw 'C';

        cout << "Please enter the state abbrev. of the person(max 2 char): ";
        getline(cin,state);
        if(!rightSize(state, 1, 2)) throw 'S';

        cout << "Please enter the zip code of the person: ";
        cin >> zip;
        Safety();
        if(!rightSize(zip, 5, 5)) throw 'Z';

        type = type_code;
    }
    catch (char E) {
        if (E == 'I')  ERS.gen("Id number isn't 9 digits.");
        if (E == 'N')  ERS.genIntMax("Name", 25);
        if (E == 'A')  ERS.genIntMax("Address", 25);
        if (E == 'C')  ERS.genIntMax("City", 14);
        if (E == 'S')  ERS.genIntMax("State", 2);
        if (E == 'Z')  ERS.gen("Zip code isn't 5 digits.");

        return false;
    }
    return true;
}

bool Person::edit()
{
    cout << "This persons current personal information is: " << endl;
    display();

    cout << "Make changes here, kept information must be re-entered." << endl;
    create(type);

    return true;
}

void Person::display() const
{
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
    if (type == 'c') { return;}
    cout << "Address: " << address << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Zip: " << zip << endl;
    cout << "Status: " << status << endl;
}


int Person::getNumber() const
{
    return number;
}


bool Person::operator == (int x) const
{
    if(this->number == x) return true;

    return false;
}

bool Person::operator == (char x) const
{
    if(this->type == x) return true;

    return false;
}