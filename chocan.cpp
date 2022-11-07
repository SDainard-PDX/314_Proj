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

//Initial Menu Selection and log-in
    int menu_choice;
    string entry_number;

    do      //Menu for making selections from cmd line
    {
        ClearScreen();
        cout << "\n\tWelcome to the ChocAn Simulator"   << endl;
        cout << "\n\tWhich interface would you like?"   << endl;
        Divider();
        cout << " 1 - Use the Manager Terminal"         << endl;
        cout << " 2 - Use the Provider Terminal"        << endl;
        cout << endl;
        cout << " 0 - Quit and exit"                    << endl;
        cout << endl;
        cout << "\tChoice: ";
        menu_choice = Choice(0,2);

        Divider();
        switch (menu_choice)
        {
            case 1: //manager terminal
                cout << "\nEnter your manager id number: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (VerifyPerson(manDS, entry_number)) {
                        menu_choice = Menu2(manDS, proDS, memDS, servDS);
                    }//goto menu 2
                    else { cout << "No match returning to main menu." << endl;}
                }
                break;
            case 2: //providers terminal
                cout << "\nEnter your provider id number: ";
                getline(cin, entry_number);
                if (rightSize(entry_number, 9, 9)) {
                    if (VerifyPerson(proDS, entry_number)) {
                        menu_choice = Menu3(manDS, proDS, memDS, servDS);
                    }//goto menu 3
                    else cout << "No match returning to main menu." << endl;
                }
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

    return 1; // SUCCESS
}

//Managers Menu
int Menu2(People *manDS, People *proDS, People *memDS, Service_Directory *servDS)
{
    int menu_choice;
    do      //Menu for making selections from cmd line
    {
        ClearScreen();
        cout << "\n\tWelcome MANAGER"  << endl;
        cout << "\n\tWhat would you like to do?"    << endl;
        Divider();
        cout << " 1 - Member 1"     << endl;
        cout << " 2 - Provider 1"    << endl;
        cout << endl;
        cout << " 3 - Return to main menu"          << endl;
        cout << " 0 - Quit and exit"                << endl;
        cout << endl;
        cout << "\tChoice: ";
        menu_choice = Choice(0,3);

        Divider();
        switch (menu_choice)
        {
            case 1: cout << "\t\tMember one selected" << endl;
                break;
            case 2: cout << "\t\tProvider one selected" << endl;
                break;
            case 3: cout << "\t\tReturning to main menu" << endl;
                return menu_choice;
            case 0: cout << "\t\tGood-bye!" << endl;
                return menu_choice;
            default: cout << "\tInvalid selection, please enter a valid selection or 0 to quit." << endl;
                break;
        }

        Wait4Enter();
    } while (menu_choice != 0 && menu_choice != 3);
    Divider();
    return menu_choice;
}

//Providers Menu
int Menu3(People *manDS, People *proDS, People *memDS, Service_Directory *servDS)
{
    int menu_choice;
    string entry;

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
                getline(cin, entry);
                if (rightSize(entry, 9, 9)) {
                    if (VerifyPerson(memDS, entry)) {
                        cout << "\tMember status is: " + entry;
                    }
                    else cout << "No match returning to main menu." << endl;
                }
                break;
            case 2: cout << "\t\tSubmit selected" << endl;
                break;
            case 3:
                cout << "Please enter the email to send to: ";
                getline(cin, entry);
                servDS->write_out(entry);
                cout << "\n\nCurrent Service Directory sent to " + entry << endl;
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

bool VerifyPerson(People *pool, string &number)
{
    Person *result = pool->find_person(number);
    if (result) {
        number = result->getStatus();
        //if (number == "Valid" ) {
            return true;
        //}
    }
    return false;
}