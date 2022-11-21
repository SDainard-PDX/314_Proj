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
        cout << " 3 - Display all Providers"            << endl;
        cout << " 4 - Display all Members"              << endl;
        cout << " 5 - Display all Managers"             << endl;
        cout << " 5 - Display Service Directory"        << endl;
        cout << endl;
        cout << " 0 - Quit and exit"                    << endl;
        cout << endl;
        cout << "\tChoice: ";
        menu_choice = Choice(0,6);

        Divider();
        switch (menu_choice)
        {
            case 1: //manager terminal
                cout << "\nEnter your manager id number: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (VerifyPerson(manDS, entry_number, reply)) {
                        menu_choice = Menu2(manDS, proDS, memDS, servDS);
                    }//goto menu 2
                    else { cout << "No match returning to main menu." << endl;}
                }
                break;
            case 2: //providers terminal
                cout << "\nEnter your provider id number: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (VerifyPerson(proDS, entry_number, reply)) {
                        menu_choice = Menu3(entry_number, manDS, proDS, memDS, servDS, invoiceDS);
                    }//goto menu 3
                    else cout << "No match returning to main menu." << endl;
                }
                break;
            case 3:
                cout << endl;
                proDS->display_all();
                break;
            case 4:
                cout << endl;
                memDS->display_all();
                break;
            case 5:
                cout << endl;
                manDS->display_all();
                break;
            case 6:
                cout << endl;
                servDS->display_all();
                break;
            case 0: cout << "\t\tGood-bye!" << endl;
                break;
            default: cout << "\tInvalid selection, please enter a valid selection or 0 to quit." << endl;
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
int Menu2(People *manDS, People *proDS, People *memDS, Service_Directory *servDS)
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
        cout << " 3 - Edit Member / Provider / Manager"      << endl;//TODO
        cout << "\tThese will likely get dropped into a separate menu" << endl;

        cout << " 4 - Add Service"      << endl;
        cout << " 5 - Remove Service"   << endl;
        cout << " 6 - Edit Service"     << endl;
        cout << "\tSame with this group" << endl;

        cout << "Still need:\n\t 7 - ind report mem/pro\n\t8 - all reports" << endl;

        cout << endl;
        cout << " 7 - Return to main menu"         << endl;
        cout << " 0 - Quit and exit"                << endl;
        cout << endl;
        cout << "\tChoice: ";
        menu_choice = Choice(0,7);

        Divider();
        switch (menu_choice)
        {
            case 1:
                cout << "\n\t member = M provider = P manager = C" << endl;
                cout << "\tWhat type of person: " << endl;
                pick = Choice("mpc");

                if(toAdd->create(pick)) {
                    if (pick == 'm') {
                        memDS->add_person(toAdd);
                        cout << "\nAdded person to Members" << endl;
                    } else if (pick == 'p') {
                        proDS->add_person(toAdd);
                        cout << "\nAdded person to Providers" << endl;
                    } else if (pick == 'c') {
                        manDS->add_person(toAdd);
                        cout << "\nAdded person to Managers" << endl;
                    }
                }
                else cout << "\t\tUnable to Add selection" << endl;
                break;

            case 2:
                cout << "\n\t member = M provider = P manager = C" << endl;
                cout << "\tWhat type of person: " << endl;
                pick = Choice("mpc");

                cout << "\nEnter the id number of person to remove: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (pick == 'm') {
                        if (VerifyPerson(memDS, entry_number, reply)) {
                            memDS->remove_person(entry_number);
                            cout << "\nRemoved " << entry_number << " from Members" << endl;
                        } else { cout << "No match returning to menu." << endl;}
                    }
                    else if (pick == 'p') {
                        if (VerifyPerson(proDS, entry_number, reply)) {
                            proDS->remove_person(entry_number);
                            cout << "\nRemoved " << entry_number << " from Providers" << endl;
                        }else { cout << "No match returning to menu." << endl;}
                    }
                    else if (pick == 'c') {
                        if (VerifyPerson(manDS, entry_number, reply)) {
                            manDS->remove_person(entry_number);
                            cout << "\nRemoved " << entry_number << " from Managers" << endl;
                        } else { cout << "No match returning to menu." << endl;}
                    }
                    else cout << "\t\tUnable to Remove selection" << endl;
                }
                break;

            case 3: cout << "\t\tEdit Person Selected, will do later" << endl;
                break;
            case 4:
                cout << "\tAdding a service" << endl;
                if (add_item->create()) {
                    if( servDS->add_item(add_item)) {
                        cout << "\nAdded Service to Directory" << endl;
                    }
                }
                else cout << "\n\t\tUnable to Add selection" << endl;
                break;
            case 5:
                cout << "\nEnter the id number of service to remove: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if(servDS->remove_item(entry_number)) {
                        cout << "\nRemoved Service " << entry_number << " from Directory." << endl;
                    }
                }
                else cout << "\n\t\tUnable to Remove selection" << endl;
                break;
            case 6:
                cout << "\nEnter the id number of service to edit: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if(servDS->edit_item(entry_number)) {
                        cout << "\nEdited Service " << entry_number << " from Directory." << endl;
                    }
                }
                else cout << "\n\t\tUnable to Edit selection" << endl;
                break;

            case 7: cout << "\t\tReturning to main menu" << endl;
                return menu_choice;
            case 0: cout << "\t\tGood-bye!" << endl;
                return menu_choice;
            default: cout << "\tInvalid selection, please enter a valid selection or 0 to quit." << endl;
                break;
        }

        Wait4Enter();
    } while (menu_choice != 0 && menu_choice != 7);
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
        cout << "\n\tWelcome Provider"  << endl;
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
                cout << "\nEnter the member id number: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (VerifyPerson(memDS, entry_number, reply)) {
                        cout << "\tMember status is: " + reply;
                    }
                    else cout << "No match returning to main menu." << endl;
                }
                break;
            case 2:
                addition = new Session_Invoice;
                addition->create(Pro_Number);
                if (addition) { invoiceDS->add_invoice(addition); }
                else cout << "\nUnable to create Invoice, no changes" << endl;
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
            default: cout << "\tInvalid selection, please enter a valid selection or 0 to quit." << endl;
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
