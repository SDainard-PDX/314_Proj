#include "invoice_chain.hpp"
#include <sstream>

#define MEM_REPORTS_PATH "reports/members/"
#define PRO_REPORTS_PATH "reports/providers/"
#define ACC_REPORTS_PATH "reports/accounts/"

using namespace std;

Invoice_ChainNode::Invoice_ChainNode():invoice(nullptr), mem_next(nullptr), pro_next(nullptr),
                                    inv_num_next(nullptr), pro_prev(nullptr), mem_prev(nullptr) {}

Invoice_ChainNode::Invoice_ChainNode(Session_Invoice *toAdd):invoice(toAdd), mem_next(nullptr), pro_next(nullptr),
                                    inv_num_next(nullptr), pro_prev(nullptr), mem_prev(nullptr) {}

Invoice_ChainNode::~Invoice_ChainNode()
{
    delete invoice;
    invoice = nullptr;
    mem_next = nullptr;
    pro_next = nullptr;
    inv_num_next = nullptr;
    pro_prev = nullptr;
    mem_prev = nullptr;
}

Invoice_Chain::Invoice_Chain(): mem_head(nullptr), pro_head(nullptr), inv_num_head(nullptr) {}

Invoice_Chain::~Invoice_Chain()
{
    Invoice_ChainNode *del;
    pro_head = nullptr;
    mem_head = nullptr;
    while(inv_num_head) {
        del = inv_num_head;
        del->pro_next = nullptr;
        del->mem_next = nullptr;
        del->inv_num_next = nullptr;
        del->pro_prev = nullptr;
        del->mem_prev = nullptr;
        inv_num_head = inv_num_head->inv_num_next;
        delete del;
    }
}

int Invoice_Chain::populate(const string& file_in)
{
    //open the indicated file or return
    ifstream in_file(file_in);
    if(!in_file.is_open()) return 0;

    //temp variables for input
    string  servNumIn = {0}, proNumIn = {0}, memNumIn = {0}, commIn = {0};
    string subYr, subMo, subDay, subHr, subMin, subSec, servYr, servMo, servDay;
    int count = 0;  //temp variable to return invoices input
    invoice_count = 0;

    //loop over input until EOF
    while(getline(in_file, servNumIn, ','))
    {
        tm *subTimeIn = new tm, *servDateIn = new tm;
        *subTimeIn = {0}, *servDateIn = {0};

        //get temp values from file
        getline(in_file, proNumIn, ',');
        getline(in_file, memNumIn, ',');
        getline(in_file, subYr, ',');
        subTimeIn->tm_year = stoi(subYr);
        getline(in_file, subMo, ',');
        subTimeIn->tm_mon = stoi(subMo);
        getline(in_file, subDay, ',');
        subTimeIn->tm_mday = stoi(subDay);
        getline(in_file, subHr, ',');
        subTimeIn->tm_hour = stoi(subHr);
        getline(in_file, subMin, ',');
        subTimeIn->tm_min = stoi(subMin);
        getline(in_file, subSec, ',');
        subTimeIn->tm_sec = stoi(subSec);
        getline(in_file, servYr, ',');
        servDateIn->tm_year = stoi(servYr);
        getline(in_file, servMo, ',');
        servDateIn->tm_mon = stoi(servMo);
        getline(in_file, servDay, ',');
        servDateIn->tm_mday = stoi(servDay);
        getline(in_file, commIn);

        //create person to add
        Session_Invoice *toAdd = new Session_Invoice(servNumIn, proNumIn, memNumIn, servDateIn, subTimeIn, commIn);
        toAdd->setInvNum(++invoice_count);

        //add the vehicle to the table & increment count
        if (!add_invoice(toAdd)) { delete toAdd; };
        count++;
    }

    in_file.close(); //close file

    return count; //return the number read in
}

bool Invoice_Chain::add_invoice(Session_Invoice *toAdd)
{
    if (!toAdd) { return false; }
    Invoice_ChainNode *newInvoice = new Invoice_ChainNode(toAdd);
    Invoice_ChainNode *curr = inv_num_head, *prev = nullptr;

    if (toAdd->getInvNum() == 0) {
        int addNum = 1;
        while (curr) {
            addNum = curr->invoice->getInvNum();
            curr = curr->inv_num_next;
        }
        newInvoice->invoice->setInvNum(++addNum);
    }

//this first bit is good for both since if one empty the other empty
    if (!pro_head && !mem_head && !inv_num_head) {
        pro_head = newInvoice;
        mem_head = newInvoice;
        inv_num_head = newInvoice;
    }
    else {
//first run it for inv_num
        while (toAdd->getInvNum() >= curr->invoice->getInvNum() && curr->inv_num_next) {
            if (toAdd->getInvNum() == curr->invoice->getInvNum()) {
                cout << "\n\tCannot add new invoice, id number already exists." << endl;
                delete newInvoice;
                return false;
            }
            prev = curr;
            curr = curr->inv_num_next;
        }
        if (!curr->inv_num_next) {
            if (curr == inv_num_head) {
                inv_num_head = newInvoice;
                newInvoice->inv_num_next = curr;
            } else {
                curr->inv_num_next = newInvoice;
            }
        }
        else {
            if(prev) prev->inv_num_next = newInvoice;
            newInvoice->inv_num_next = curr;
        }
//second run through to place in providers chain
        curr = pro_head;
        prev = nullptr;
        while (toAdd->getProNum() > curr->invoice->getProNum() && curr->pro_next) {
            prev = curr;
            curr = curr->pro_next;
        }
        if (!curr->pro_next) {
            if (curr == pro_head) {
                pro_head = newInvoice;
                newInvoice->pro_next = curr;
            } else {
            curr->pro_next = newInvoice;
            }
        }
        else {
            if(prev) prev->pro_next = newInvoice;
            newInvoice->pro_next = curr;
        }
//lastly the process for members chain
        curr = mem_head;
        prev = nullptr;
        while (toAdd->getMemNum() > curr->invoice->getMemNum() && curr->mem_next) {
            prev = curr;
            curr = curr->mem_next;
        }
        if (!curr->mem_next) {
            if (curr == mem_head) {
                mem_head = newInvoice;
                newInvoice->mem_next = curr;
            } else {
                curr->mem_next = newInvoice;
            }
        }
        else {
            if(prev) prev->mem_next = newInvoice;
            newInvoice->mem_next = curr;
        }
    }
    return true;
}

Session_Invoice * Invoice_Chain::find_invoice(int inv_num) {
    if(!inv_num_head) return nullptr;
    Invoice_ChainNode *curr = inv_num_head;
    Session_Invoice *result = nullptr;

    while (curr && !result) {
        if(curr->invoice->getInvNum() == inv_num) result = curr->invoice;
        curr = curr->inv_num_next;
    }
    return result;
}

bool Invoice_Chain::edit_invoice(int inv_num)
{
    if(!inv_num_head) { return false; }
    Session_Invoice *temp = find_invoice(inv_num);
    if(!temp) {
        cout << "\n\tCould not locate record." << endl;
        return false;
    }
    return temp->edit();
}

bool Invoice_Chain::remove_invoice(int inv_num)
{
    Invoice_ChainNode *curr = inv_num_head, *prev = nullptr, *del = nullptr;

    if (!inv_num_head) { return false; }
    else {
        while (curr) {
            if (curr->invoice->getInvNum() == inv_num) {
                del = curr;
                if (curr == inv_num_head) { inv_num_head = curr->inv_num_next; }
                else { prev->inv_num_next = curr->inv_num_next; }

                if (curr == pro_head) { pro_head = curr->pro_next; }
                else {
                    curr->pro_prev->pro_next = curr->pro_next;
                    if(curr->pro_next) { curr->pro_next->pro_prev = curr->pro_prev; }
                }

                if (curr == mem_head) { mem_head = curr->mem_next; }
                else {
                    curr->mem_prev->mem_next = curr->mem_next;
                    if(curr->mem_next) { curr->mem_next->mem_prev = curr->mem_prev; }
                }
                delete del;
            }
            prev = curr;
            curr = curr->inv_num_next;
        }
    }
    return true;
}

void Invoice_Chain::display_all()
{
    if(!inv_num_head) return;
    Invoice_ChainNode *curr = inv_num_head;
    while (curr) {
        curr->invoice->display();
        cout << endl;
    }
}

bool Invoice_Chain::write_out(string file_out)
{
    ofstream output_file(file_out);
    if(!output_file.is_open()) return false;

    Invoice_ChainNode *curr = inv_num_head;
    while(curr) {
        Session_Invoice *temp = curr->invoice;
        tm *subTime = temp->getSubTime();
        tm *servDate = temp->getServDate();

        output_file << temp->getSerNum() << "," << temp->getProNum() << "," << temp->getMemNum() << ","
                    << subTime->tm_year << "," << subTime->tm_mon << "," << subTime->tm_mday << ","
                    << subTime->tm_hour << "," << subTime->tm_min << "," << subTime->tm_sec << ","
                    << servDate->tm_year << "," << servDate->tm_mon << "," << servDate->tm_mday << ","
                << temp->getComments() << endl;

        curr = curr->inv_num_next;
    }

    output_file.close();
    return true;
}

bool Invoice_Chain::member_report(std::string id, People *memDS, People *proDS, Service_Directory *servDS)
{
	//TODO: throw error?
	if(!mem_head)
		return false;

	Person *mem = memDS->find_person(id);

	if(!mem) { //throw error
		return false;
	}

	tm *curr_time = new tm;
	time_t now = time(0);
	curr_time = localtime(&now);

	string file_out = string(MEM_REPORTS_PATH);

	//we store names in a single string so we split across spaces here
	stringstream ss(mem->getName());
	string token;
	while(ss >> token) {
		file_out += token;
	}

	file_out += (to_string(curr_time->tm_mon + 1) + "-"
			   + to_string(curr_time->tm_mday) + "-"
			   + to_string(curr_time->tm_year + 1900) + ".txt");

    ofstream output_file;
	output_file.open(file_out);
    if(!output_file.is_open()) return false; //throw error

	output_file << "Member Name: " << mem->getName() << endl
				<< "Member ID: #" << mem->getNumber() << endl
				<< "Member Address:\n\t" << mem->getAddress() << endl
				<< "\t" << mem->getCity() << ", " << mem->getState()
				<< " " << mem->getZip() << "\n\nServices Received:" << endl;
	
	cout << "Member Name: " << mem->getName() << endl
		 << "Member ID: #" << mem->getNumber() << endl
		 << "Member Address:\n\t" << mem->getAddress() << endl
		 << "\t" << mem->getCity() << ", " << mem->getState()
		 << " " << mem->getZip() << "\n\nServices Received:" << endl;
	
	Invoice_ChainNode *curr_inv = mem_head;

    while (curr_inv && curr_inv->invoice->getMemNum() != id) {
        curr_inv = curr_inv->mem_next;
    }

	if(!curr_inv) {		//member has not received services
		output_file << "\tMember has received no services for this period." << endl;
		cout << "\tMember has received no services for this period." << endl;
		return true;
	}

	while(curr_inv && curr_inv->invoice->getMemNum() == id) {
		Service_Item *serv = servDS->find_item(curr_inv->invoice->getSerNum());
		Person *pro = proDS->find_person(curr_inv->invoice->getProNum());
		tm *time = curr_inv->invoice->getServDate();

		output_file << "\t" << ((serv) ? serv->getName() : "Invalid service") << " with "
					<< ((pro) ? pro->getName() : "Invalid provider") << " on "
					<< (time->tm_mon + 1) << "-" << (time->tm_mday) << "-"
					<< (time->tm_year + 1900) << "\n" << endl;

		cout << "\t" << ((serv) ? serv->getName() : "Invalid service") << " with "
			 << ((pro) ? pro->getName() : "Invalid provider") << " on "
			 << (time->tm_mon + 1) << "-" << (time->tm_mday) << "-"
			 << (time->tm_year + 1900) << "\n" << endl;

		curr_inv = curr_inv->mem_next;
	}

	return true;
}

bool Invoice_Chain::provider_report(std::string id, People *proDS, People *memDS, Service_Directory *servDS)
{
	//TODO: throw error?
	if(!pro_head)
		return false;

	Person *pro = proDS->find_person(id);

	if(!pro) { //throw error
		return false;
	}

	tm *curr_time = new tm;
	time_t now = time(0);
	curr_time = localtime(&now);

	string file_out = string(PRO_REPORTS_PATH);

	//we store names in a single string so we split across spaces here
	stringstream ss(pro->getName());
	string token;
	while(ss >> token) {
		file_out += token;
	}

	file_out += (to_string(curr_time->tm_mon + 1) + "-"
					  + to_string(curr_time->tm_mday) + "-"
					  + to_string(curr_time->tm_year + 1900) + ".txt");

    ofstream output_file;
	output_file.open(file_out);
    if(!output_file.is_open()) return false; //throw error

	output_file << "Provider Name: " << pro->getName() << endl
				<< "Provider ID: #" << pro->getNumber() << endl
				<< "Provider Address:\n\t" << pro->getAddress() << endl
				<< "\t" << pro->getCity() << ", " << pro->getState()
				<< " " << pro->getZip() << "\n\nServices Received:" << endl;
	
	cout << "Provider Name: " << pro->getName() << endl
		 << "Provider ID: #" << pro->getNumber() << endl
		 << "Provider Address:\n\t" << pro->getAddress() << endl
		 << "\t" << pro->getCity() << ", " << pro->getState()
		 << " " << pro->getZip() << "\n\nServices Received:" << endl;
	
	Invoice_ChainNode *curr_inv = pro_head;

    while (curr_inv && curr_inv->invoice->getProNum() != id) {
        curr_inv = curr_inv->pro_next;
    }

	if(!curr_inv) {		//provider has not provided services
		output_file << "\tProvider has provided no services for this period." << endl;
		cout << "\tProvider has provided no services for this period." << endl;
		return true;
	}

	while(curr_inv && curr_inv->invoice->getProNum() == id) {
		Service_Item *serv = servDS->find_item(curr_inv->invoice->getSerNum());
		Person *mem = memDS->find_person(curr_inv->invoice->getMemNum());
		tm *ser_time = curr_inv->invoice->getServDate();
		tm *sub_time = curr_inv->invoice->getSubTime();

		output_file << "\t" << "Service #" << curr_inv->invoice->getSerNum() << " provided to "
					<< ((mem) ? mem->getName() : "Invalid member") << "\n\tProvided on "
					<< (ser_time->tm_mon) << "-" << (ser_time->tm_mday) << "-"
					<< (ser_time->tm_year) << "\tRecorded on "
					<< (sub_time->tm_mon + 1) << "-" << (sub_time->tm_mday) << "-"
					<< (sub_time->tm_year + 1900) << " " << (sub_time->tm_hour) << ":"
					<< (sub_time->tm_min) << ":" << (sub_time->tm_sec) << "\n\tFee due: "
					<< ((serv) ? ("$" + to_string(serv->getFee())) : "Invalid fee") << endl;

		cout << "\t" << "Service #" << curr_inv->invoice->getSerNum() <<" provided to "
					<< ((mem) ? mem->getName() : "Invalid member") << "\n\tProvided on "
					<< (ser_time->tm_mon) << "-" << (ser_time->tm_mday) << "-"
					<< (ser_time->tm_year) << "\tRecorded on " 
					<< (sub_time->tm_mon + 1) << "-" << (sub_time->tm_mday) << "-"
					<< (sub_time->tm_year + 1900) << " " << (sub_time->tm_hour) << ":"
					<< (sub_time->tm_min) << ":" << (sub_time->tm_sec) << "\n\tFee due: "
					<< ((serv) ? ("$" + to_string(serv->getFee())) : "Invalid fee") << endl;

		curr_inv = curr_inv->pro_next;
	}

	return true;
}

bool Invoice_Chain::acts_payable(People *proDS, Service_Directory *servDS)
{
	if(!pro_head)
		return false; //TODO: throw error?
	
	int total_pro = 1;
	int total_consuls = 0;
	int total_fee = 0;
	int pro_consuls = 0;
	int pro_fee = 0;

	Invoice_ChainNode *curr_inv = pro_head;
	std::string pro_id = curr_inv->invoice->getProNum();

	tm *curr_time = new tm;
	time_t now = time(0);
	curr_time = localtime(&now);

	//TODO: specify path into separate reports folder
	std::string file_out = string(ACC_REPORTS_PATH) + "AccountsPayable"
						  + std::to_string(curr_time->tm_mon + 1) + "-"
						  + std::to_string(curr_time->tm_mday) + "-"
						  + std::to_string(curr_time->tm_year + 1900) + ".txt";

    ofstream output_file;
	output_file.open(file_out);
    if(!output_file.is_open()) return false;

	output_file << "Providers To Be Paid:" << endl;
	cout << "Providers To Be Paid:" << endl;

	//while loop--go through providers,
	while(curr_inv) {
		if(pro_id != curr_inv->invoice->getProNum()) { //new provider
			Person *pro = proDS->find_person(pro_id);

			if(!pro) //invalid provider in session invoices
				return false; //TODO: throw error

			std::string pro_name = pro->getName();

			//write out old provider's info
			output_file << "\t" << pro_name << " #" << pro_id << endl
						<< "\tTotal consultations: " << pro_consuls << endl
						<< "\tFee due: $" << pro_fee << endl;

			cout << "\t" << pro_name << " #" << pro_id << endl
				 << "\tTotal consultations: " << pro_consuls << endl
				 << "\tFee due: $" << pro_fee << endl;

			//now prime for new provider
			pro_fee = pro_consuls = 0;
			pro_id = curr_inv->invoice->getProNum();
			++total_pro;
		}
		Service_Item *serv = servDS->find_item(curr_inv->invoice->getSerNum());

		//TODO: make it so session invoices can't have invalid services
		if(!serv) //invalid service in session invoices
		{
			curr_inv = curr_inv->pro_next;
			continue; //throw error too
		}

		double fee = serv->getFee();
		total_fee += fee;
		pro_fee += fee;
		++total_consuls;
		
		curr_inv = curr_inv->pro_next;
	}
	//total up consuls & fees,
	//write to file
	//afterwards:
	
	output_file << "Total Providers To Be Paid: " << total_pro << endl
	            << "Total Consultations: " << total_consuls << endl
	            << "Total Fee Due: $" << total_fee << endl;

	cout << "Total Providers To Be Paid: " << total_pro << endl
	            << "Total Consultations: " << total_consuls << endl
	            << "Total Fee Due: $" << total_fee << endl;

	output_file.close();

	cout << "\nReport saved as \"" << file_out << "\"" << endl;
	return true;
}

int Invoice_Chain::getInvoiceCnt() { return ++invoice_count; }
