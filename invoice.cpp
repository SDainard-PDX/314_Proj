#include "invoice.hpp"

using namespace std;

//<Session_Invoice>
Session_Invoice::Session_Invoice(): serv_code("-1"), pro_num("-1"), mem_num("-1"), comments("none"){}

Session_Invoice::~Session_Invoice() {}

bool Session_Invoice::create(string pro){
    errstruc ERS;
    Session_Invoice *newInvoice = new Session_Invoice();
    try
    {
        string mem, serv, comm;
        int da,mo,yr;

        cout << "Please enter the id number of the Member: ";
        getline(cin,mem);
        if(!rightSize(mem, 9, 9)) throw 'M';

        cout << "Please enter the id number of the Service Item: ";
        getline(cin,serv);
        if(!rightSize(serv, 6, 6)) throw 'S';

        cout << "Please enter the 2 digit month of the service date(eg Jan = 01): ";
        mo = Choice( 1, 12);

        cout << "Please enter the 2 digit day of the service date(eg 12th = 12): ";
        da = Choice( 1, 31);

        cout << "Please enter the 2 digit yr of the service date(eg 2022 = 22): ";
        yr = Choice( 00, 99);

        cout << "Please enter any comments about the session (100 char max): ";
        getline(cin,comm);
        if(!rightSize(serv, 0, 100)) throw 'C';

        newInvoice->pro_num = pro;
        newInvoice->mem_num = mem;
        newInvoice->serv_code = serv;
        newInvoice->serv_date->tm_year = yr;
        newInvoice->serv_date->tm_mon = mo;
        newInvoice->serv_date->tm_mday = da;

        cout << "Please review the following:" << endl;
        newInvoice->display();
        cout << "Would you like to make any changes [Y/N]? ";
        if(YorN()) { newInvoice->edit(pro); }
        else {
            time_t now = time(0);
            newInvoice->sub_time = localtime(&now);
        }

    }
    catch (char E) {
        if (E == 'M')  ERS.genIntMax("Member Number", 9);
        if (E == 'S')  ERS.genIntMax("Service Number", 6);
        if (E == 'C')  ERS.genIntMax("Comments", 100);

        return false;
    }
    return true;
}

bool Session_Invoice::edit(string pro)
{
    cout << "This Service Items current information is: " << endl;
    display();

    cout << "Make changes here, kept information must be re-entered." << endl;
    create(pro);

    return true;
}

void Session_Invoice::display() const
{
    cout << "\nProvider Number: " << pro_num << endl;
    cout << "  Member Number: " << mem_num << endl;
    cout << "  Service Code : " << serv_code << endl;
    cout << "   Service Date: " << serv_date->tm_mon << "-"
        << serv_date->tm_mday << "-" << serv_date->tm_year << endl;
    cout << "Comments: " << comments << endl;
}


string Session_Invoice::getSerNum() const { return serv_code; }
string Session_Invoice::getProNum() const { return pro_num; }
string Session_Invoice::getMemNum() const { return mem_num; }
