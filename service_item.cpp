#include "service_item.hpp"
#include <iomanip>

using namespace std;

//<Service_Item>
Service_Item::Service_Item(): number("-1"), name("none"), fee(0.0) {}

Service_Item::~Service_Item() {}

Service_Item::Service_Item(string num, string nam, double fe)
                    :number(std::move(num)), name(std::move(nam)), fee(fe) {}

bool Service_Item::create(){
    errstruc ERS;
    try
    {
        cout << "Please enter the id number of the Service Item: ";
        getline(cin,number);
        if(!rightSize(number, 6, 6)) throw 'I';
		if(!(number.find_first_not_of("0123456789") == string::npos)) throw 'I';

        cout << "Please enter the name of the Service Item(max 25 char): ";
        getline(cin,name);
        if(!rightSize(name, 1, 20)) throw 'N';

        cout << "Please enter the fee paid for the Service_Item(max $999.99): $";
        cin >> fee;
        Safety();
        if(fee < 0) { throw 'L'; }
        if(fee > 999.99) { throw 'H'; }
    }
    catch (char E) {
        if (E == 'I')  ERS.gen("Id number isn't 6 digits.");
        if (E == 'N')  ERS.genIntMax("Name", 20);
        if (E == 'L')  ERS.gen("Fee must be non-negative.");
        if (E == 'H')  ERS.gen("Fee must be less than $1000.");

        return false;
    }
    return true;
}

bool Service_Item::edit()
{
    cout << "This Service Items current information is: " << endl;
    display();

    cout << "Make changes here, kept information must be re-entered." << endl;
    while(!create());

    return true;
}

void Service_Item::display() const
{
    cout << "Number: " << number << "\tFee: $" << std::fixed << std::setprecision(2);
	cout << fee << "\nName: " << name << endl;
}


string Service_Item::getNum() const { return number; }
string Service_Item::getName() const { return name; }
double Service_Item::getFee() const { return fee; }


bool Service_Item::operator == (string match) const
{
    if(this->number == match) return true;

    return false;
}
