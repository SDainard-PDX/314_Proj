#include "Menus.hpp"

/*
*/

using namespace std;

int main()
{
    //TODO Build data structures from file here.
    /* Use Func calls to build data items */
    People *memDS = new People();
    People *proDS = new People();
    People *manDS = new People();
    memDS->populate(MEMBERS_IN, 'm');
    proDS->populate(PROVIDERS_IN,'p');
    manDS->populate(MANAGERS_IN,'c');

    int menu_choice;

    //Menu for making selections from cmd line
    do
    {
        ClearScreen();
        cout << "\n\tWelcome to the ChocAn Simulator"  << endl;
        cout << "\n\tWhich interface would you like?"       << endl;
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
            case 1:
                int number;
                cout << "\nEnter your manager id number: ";
                cin >> number;
                Safety();
                if (!rightSize(number, 9, 9));
                else if (!VerifyPerson(manDS, number));
                else Menu2(manDS, proDS, memDS);//goto menu 2
                break;
            case 2: //EditPerson();
                break;
            case 0: cout << "\t\tGood-bye!" << endl;
                break;
            default: cout << "\tInvalid selection, please enter a valid selection or 0 to quit." << endl;
                break;
        }

        Wait4Enter();
    } while (menu_choice != 0);

    Divider();

    //TODO Clean up and closing items to exit program

    return 1; // SUCCESS
}

//Managers Menu
void Menu2(People *manDS, People *proDS, People *memDS)
{
    int menu_choice;

    //Menu for making selections from cmd line
    do
    {
        ClearScreen();
        cout << "\n\tWelcome MANAGER"  << endl;
        cout << "\n\tWhat would you like to do?"       << endl;
        Divider();
        cout << " 1 - Use the Manager Terminal"         << endl;
        cout << " 2 - Use the Provider Terminal"        << endl;
        cout << endl;
        cout << " 0 - Quit and exit"                    << endl;
        cout << endl;
        cout << "\tChoice: ";
        menu_choice = Choice(0,7);

        Divider();
        switch (menu_choice)
        {
            case 1:
                int number;
                cout << "\nEnter your manager id number: ";
                cin >> number;
                Safety();
                if (!rightSize(number, 9, 9)) {}//todo bad input;
                else if (!VerifyPerson(manDS, number)) {}//todo bad input;
                else Menu2(manDS, proDS, memDS);//goto menu 2
                break;
            case 2: //EditPerson();
                break;
            case 0: cout << "\t\tGood-bye!" << endl;
                break;
            default: cout << "\tInvalid selection, please enter a valid selection or 0 to quit." << endl;
                break;
        }

        Wait4Enter();
    } while (menu_choice != 0);

    Divider();

}

bool VerifyPerson(People *pool, int number)
{
    if (pool->find_person(number)) return true;
    return false;
}