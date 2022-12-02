#include "chocan.hpp"

/*
*/

using namespace std;

int main()
{
//Build data structures from file here
    People *memDS = new People();
    People *proDS = new People();
    People *manDS = new People();
    memDS->populate(MEMBERS_FILE, 'm');
    proDS->populate(PROVIDERS_FILE, 'p');
    manDS->populate(MANAGERS_FILE, 'c');
    Service_Directory *servDS = new Service_Directory();
    servDS->populate(SERVICE_DIR_FILE);
    Invoice_Chain *invoiceDS = new Invoice_Chain();
    invoiceDS->populate(INVOICE_FILE);

//Initial Menu Selection and log-in
    int menu_choice;
    string entry_number, reply;

    do      //Menu for making selections from cmd line
    {
        ClearScreen();
        cout << "\n\tWelcome to the ChocAn Simulator"   << endl;
        cout << "\n\tWhich interface would you like?"   << endl;
        Divider();
        cout << " 1 - Use the Manager Terminal"         << endl;
        cout << " 2 - Use the Provider Terminal"        << endl;
        cout << " 3 - Display Service Directory"        << endl;
        cout << endl;
        cout << " 0 - Quit and exit"                    << endl;
        cout << endl;
        cout << "\tChoice: ";
        menu_choice = Choice(0,3);

        Divider();
        switch (menu_choice)
        {
            case 1: //manager terminal
                cout << "\nEnter your manager ID number: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (VerifyPerson(manDS, entry_number, reply)) {
                        menu_choice = Menu2(manDS, proDS, memDS, servDS, invoiceDS);
                    }//goto menu 2
                    else { cout << "Invalid login. Returning to main menu." << endl;}
                }
				else { cout << "Invalid ID format. Returning to main menu." << endl; }
                break;
            case 2: //providers terminal
                cout << "\nEnter your provider ID number: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (VerifyPerson(proDS, entry_number, reply)) {
                        menu_choice = Menu3(entry_number, manDS, proDS, memDS, servDS, invoiceDS);
                    }//goto menu 3
                    else cout << "Invalid login. Returning to main menu." << endl;
                }
				else { cout << "Invalid ID format. Returning to main menu." << endl; }
                break;
            case 3:
                cout << endl;
                servDS->display_all();
                break;
            case 0: cout << "\t\tGood-bye!" << endl;
                break;
            default: cout << "\tInvalid selection. Please enter a valid selection or 0 to quit." << endl;
                break;
        }
        Wait4Enter();
    } while (menu_choice != 0);
    Divider();

    //Clean up and closing items to exit program
    manDS->write_out(MANAGERS_FILE);
    proDS->write_out(PROVIDERS_FILE);
    memDS->write_out(MEMBERS_FILE);
    delete manDS;
    delete proDS;
    delete memDS;
    servDS->write_out(SERVICE_DIR_FILE);
    delete servDS;
    invoiceDS->write_out(INVOICE_FILE);
    delete invoiceDS;

    return 1; // SUCCESS
}

//Managers Menu
int Menu2(People *manDS, People *proDS, People *memDS, Service_Directory *servDS, Invoice_Chain *invoiceDS)
{
    int menu_choice;
    string entry_number, reply;
    char pick = {0};
    Person *toAdd = nullptr;
    Service_Item *add_item = nullptr;

    do      //Menu for making selections from cmd line
    {
        ClearScreen();
        cout << "\n\tWelcome MANAGER"  << endl;
        cout << "\n\tWhat would you like to do?"    << endl;
        Divider();
        cout << " 1 - Add Member / Provider / Manager"       << endl;
        cout << " 2 - Remove Member / Provider / Manager"    << endl;
        cout << " 3 - Edit Member / Provider / Manager"      << endl;
        cout << " 4 - View All Members / Providers / Managers" << endl;
        cout << " 5 - Add Service"      << endl;
        cout << " 6 - Remove Service"   << endl;
        cout << " 7 - Edit Service"     << endl;

        cout << " 8 - Generate Summary Report for Member"   << endl;
        cout << " 9 - Generate Summary Report for Provider" << endl;
		cout << "10 - Generate Report of Accounts Payable and EFT File"  << endl;

        cout << endl;
        cout << "11 - Return to main menu"         << endl;
        cout << " 0 - Quit and exit"                << endl;
        cout << endl;
        cout << "\tChoice: ";
        menu_choice = Choice(0,11);

        Divider();
        switch (menu_choice)
        {
            case 1:
                cout << "\n\t Member = 'M' | Provider = 'P' | Manager = 'C'" << endl;
                cout << "\tEnter the type of person to view: ";
                pick = Choice("mpc");

				toAdd = new Person;
                if(toAdd->create(pick)) {
                    if (pick == 'm') {
                        if (memDS->add_person(toAdd)) {
                            cout << "\nAdded person to Members" << endl; }
                    } else if (pick == 'p') {
                        if (proDS->add_person(toAdd)) {
                        cout << "\nAdded person to Providers" << endl; }
                    } else if (pick == 'c') {
                        if (manDS->add_person(toAdd)) {
                        cout << "\nAdded person to Managers" << endl; }
                    }
                }
                else {
                    cout << "\t\tUnable to Add selection" << endl;
                    delete toAdd;
                }
                break;

            case 2:
                cout << "\n\t Member = 'M' | Provider = 'P' | Manager = 'C'" << endl;
                cout << "\tEnter the type of person to view: ";
                pick = Choice("mpc");

                cout << "\nEnter the ID number of the person to remove: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (pick == 'm') {
                        if (VerifyPerson(memDS, entry_number, reply)) {
                            memDS->remove_person(entry_number);
                            cout << "\nRemoved " << entry_number << " from Members" << endl;
                        } else { cout << "Invalid member. Returning to menu." << endl;}
                    }
                    else if (pick == 'p') {
                        if (VerifyPerson(proDS, entry_number, reply)) {
                            proDS->remove_person(entry_number);
                            cout << "\nRemoved " << entry_number << " from Providers" << endl;
                        }else { cout << "Invalid provider. Returning to menu." << endl;}
                    }
                    else if (pick == 'c') {
                        if (VerifyPerson(manDS, entry_number, reply)) {
                            manDS->remove_person(entry_number);
                            cout << "\nRemoved " << entry_number << " from Managers" << endl;
                        } else { cout << "Invalid manager. Returning to menu." << endl;}
                    }
                    else cout << "\t\tUnable to Remove selection" << endl;
                }
				else { cout << "Invalid ID format. Returning to main menu." << endl; }
                break;

            case 3:
                cout << "\n\t Member = 'M' | Provider = 'P' | Manager = 'C'" << endl;
                cout << "\tEnter the type of person to view: ";
                pick = Choice("mpc");

                cout << "\nEnter the ID number of the person to edit: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (pick == 'm') {
                        if (VerifyPerson(memDS, entry_number, reply)) {
                            memDS->edit_person(entry_number);
                            cout << "\nEdited " << entry_number << " in Members" << endl;
                        } else { cout << "Invalid member. Returning to menu." << endl;}
                    }
                    else if (pick == 'p') {
                        if (VerifyPerson(proDS, entry_number, reply)) {
                            proDS->edit_person(entry_number);
                            cout << "\nEdited " << entry_number << " in Providers" << endl;
                        }else { cout << "Invalid provider. Returning to menu." << endl;}
                    }
                    else if (pick == 'c') {
                        if (VerifyPerson(manDS, entry_number, reply)) {
                            manDS->edit_person(entry_number);
                            cout << "\nEdited " << entry_number << " in Managers" << endl;
                        } else { cout << "Invalid manager. Returning to menu." << endl;}
                    }
                    else cout << "\t\tUnable to Edit selection" << endl;
                }
				else { cout << "Invalid ID format. Returning to main menu." << endl; }
                break;

            case 4:
                cout << "\n\t Member = 'M' | Provider = 'P' | Manager = 'C'" << endl;
                cout << "\tEnter the type of person to view: ";
                pick = Choice("mpc");
                if (pick == 'm') {
                    cout << endl;
                    memDS->display_all();
                    break;
                }
                if (pick == 'p') {
                    cout << endl;
                    proDS->display_all();
                    break;
                }
                if (pick == 'c') {
                    cout << endl;
                    manDS->display_all();
                    break;
                }
            case 5:
                cout << "\tAdding a service" << endl;
				add_item = new Service_Item;
                if (add_item->create()) {
                    if(servDS->add_item(add_item)) {
                        cout << "\nAdded Service to Directory" << endl;
                    }
                }
                else cout << "\n\t\tUnable to add Service. No changes saved." << endl;
                break;
            case 6:
                cout << "\nEnter the Service number of the Service to remove: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 6, 6)) {
                    if(servDS->remove_item(entry_number)) {
                        cout << "\nRemoved Service " << entry_number << " from Directory." << endl;
                    }
					else cout << "\n\t\tUnable to Remove selection" << endl;
                }
				else { cout << "Invalid code format. Returning to main menu." << endl; }
                break;
            case 7:
                cout << "\nEnter the Service number of the Service to edit: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 6, 6)) {
                    if(servDS->edit_item(entry_number)) {
                        cout << "\nEdited Service " << entry_number << " from Directory." << endl;
                    }
					else cout << "\n\t\tUnable to edit selection. No changes saved." << endl;
                }
				else { cout << "Invalid code format. Returning to main menu." << endl; }
                break;

			case 8:			//member summary report
                cout << "\nEnter the ID number of the member to generate a report for: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (VerifyPerson(memDS, entry_number, reply)) {
						invoiceDS->member_report(entry_number, memDS, proDS, servDS);
                    }
                    else cout << "That member is not within the system." << endl;
                }
				else { cout << "Invalid ID format. Returning to main menu." << endl; }
				break;
			case 9:			//provider summary report
                cout << "\nEnter the ID number of the provider to generate a report for: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (VerifyPerson(proDS, entry_number, reply)) {
						invoiceDS->provider_report(entry_number, proDS, memDS, servDS);
                    }
                    else cout << "That provider is not within the system." << endl;
                }
				else { cout << "Invalid ID format. Returning to main menu." << endl; }
				break;
			case 10: 		//accounts payable
				invoiceDS->acts_payable(proDS, servDS);	
				break;
            case 11: cout << "\t\tReturning to main menu" << endl;
                return menu_choice;
            case 0: cout << "\t\tGood-bye!" << endl;
                return menu_choice;
            default: cout << "\tInvalid selection. Please enter a valid selection or 0 to quit." << endl;
                break;
        }

        Wait4Enter();
    } while (menu_choice != 0 && menu_choice != 11);
    Divider();
    return menu_choice;
}

//Providers Menu
int Menu3(string Pro_Number, People *manDS, People *proDS, People *memDS,
          Service_Directory *servDS, Invoice_Chain *invoiceDS)
{
    int menu_choice;
    string entry_number, reply;
    Session_Invoice *addition = nullptr;

    do      //Menu for making selections from cmd line
    {
        ClearScreen();
        cout << "\n\tWelcome PROVIDER"  << endl;
        cout << "\n\tWhat would you like to do?"    << endl;
        Divider();
        cout << " 1 - Verify Member (pre-service)"  << endl;
        cout << " 2 - Submit a Session Invoice"     << endl;
        cout << " 3 - Request a Service Directory"  << endl;
        cout << endl;
        cout << " 4 - Return to main menu"          << endl;
        cout << " 0 - Quit and exit"                << endl;
        cout << endl;
        cout << "\tChoice: ";
        menu_choice = Choice(0,4);

        Divider();
        switch (menu_choice)
        {
            case 1:
                cout << "\nEnter the member ID number: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9) && entry_number.find_first_not_of("0123456789") == string::npos) {
                    if (VerifyPerson(memDS, entry_number, reply)) {
                        cout << "\tMember status: " + reply;
                    }
                    else cout << "Member status: Invalid" << endl;
                }
				else { cout << "Invalid ID format. Returning to main menu." << endl; }
                break;
            case 2:
                addition = new Session_Invoice;
                addition->create(Pro_Number);
                if (addition) { invoiceDS->add_invoice(addition); }
                else cout << "\nUnable to create Invoice. No changes have been saved." << endl;
                break;
            case 3:
                cout << "Please enter the email to send to: ";
                getline(cin, reply);
                servDS->write_out(reply);
                cout << "\n\nCurrent Service Directory sent to " << reply << endl;
                break;
            case 4: cout << "\t\tReturning to main menu" << endl;
                return menu_choice;
            case 0: cout << "\t\tGood-bye!" << endl;
                return menu_choice;
            default: cout << "\tInvalid selection. Please enter a valid selection or 0 to quit." << endl;
                break;
        }

        Wait4Enter();
    } while (menu_choice != 0 && menu_choice != 4);
    Divider();
    return menu_choice;
}

bool VerifyPerson(People *pool, string number, string &reply)
{
    Person *result = pool->find_person(number);
    if (result) {
        reply = result->getStatus();
        return true;
    }
    return false;
}
