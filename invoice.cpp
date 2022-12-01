#include "invoice.hpp"

using namespace std;

//<Session_Invoice>
Session_Invoice::Session_Invoice(): invoice_num(-1), serv_code("-1"),
                pro_num("-1"), mem_num("-1"), comments("none") {}

Session_Invoice::Session_Invoice(string servNumIn, string proNumIn,
                    string memNumIn, tm *subTimeIn, tm *servDateIn, string commIn):
        invoice_num(-1), serv_code(servNumIn), pro_num(proNumIn), mem_num(memNumIn),
                sub_time(subTimeIn), serv_date(servDateIn), comments(commIn) {}

Session_Invoice::~Session_Invoice()
{
    delete serv_date;
    delete sub_time;
}

bool Session_Invoice::create(string pro){
    errstruc ERS;

    if (pro == "") { return false; }

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
        --mo;

        cout << "Please enter the 2 digit day of the service date(eg 12th = 12): ";
        da = Choice( 1, 31);
        --da;

        cout << "Please enter the 4 digit yr of the service date(eg 2022 = 2022): ";
        yr = Choice( 1900, 2100);

        cout << "Please enter any comments about the session (100 char max): ";
        getline(cin,comm);
        if(!rightSize(serv, 0, 100)) throw 'C';

        serv_date = new tm;
        sub_time = new tm;

        invoice_num = 0;
        pro_num = pro;
        mem_num = mem;
        serv_code = serv;
        serv_date->tm_year = yr;
        serv_date->tm_mon = mo;
        serv_date->tm_mday = da;
        comments = comm;

        cout << "Please review the following:" << endl;
        display();
        cout << "Would you like to make any changes [Y/N]? ";
        if(YorN()) { edit(); }
        else {
            time_t now = time(0);
            sub_time = localtime(&now);
			sub_time->tm_year += 1900;
			sub_time->tm_mon += 1;
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

bool Session_Invoice::edit()
{
    cout << "This Service Items current information is: " << endl;
    display();

    cout << "Make changes here, kept information must be re-entered." << endl;
    create(this->getProNum());

    return true;
}

void Session_Invoice::display() const
{
    cout << "\n Invoice Number: " << setfill('0') << setw(6) << invoice_num << endl;
    cout << "Provider Number: " << pro_num << endl;
    cout << "  Member Number: " << mem_num << endl;
    cout << "  Service Code : " << serv_code << endl;
    cout << "  Service Date : " << serv_date->tm_mon + 1 << "-"
        << serv_date->tm_mday + 1 << "-" << serv_date->tm_year << endl;
    cout << "Comments: " << comments << endl;
}

int Session_Invoice::getInvNum() const { return invoice_num; }
string Session_Invoice::getSerNum() const { return serv_code; }
string Session_Invoice::getProNum() const { return pro_num; }
string Session_Invoice::getMemNum() const { return mem_num; }
tm * Session_Invoice::getServDate() const { return serv_date; }
tm * Session_Invoice::getSubTime() const { return  sub_time; }
string Session_Invoice::getComments() const { return comments; }

void Session_Invoice::setInvNum(int cnt_in) { invoice_num = cnt_in; }
