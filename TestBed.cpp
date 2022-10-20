/*
CS333 F'22 - Dainard, Samuel
This is a main function build for the purpose of testing the ChocAn Simulator.
This test bed provides a menu to demonstrate deliverables only.
*/

using namespace std;

int main()
{
    //Initialization of global variables here
    errstruc ERS;           //error struct manager

    //TODO Build data structures from file here.
    /*
     * Use Func calls to build data items
     * eg:DATASTRUC mem; DATASTRUC pro etc
     */

    int menu_choice{-1}, SP{0};

    //Menu for making selections from cmd line
    do
    {
        ClearScreen();
        cout << "\n\tWelcome to the ChocAn Simulator"  << endl;
        cout << "\n\tWhat would you like to do?"          << endl;
        Divider();
        cout << " 1 - Add a new member or provider"                 << endl;
        cout << " 2 - Edit information for a member or provider"   << endl;
        cout << " 3 - Remove a member or provider"                  << endl;
        cout << " 4 - Run the weekly reports"                       << endl;
        //TODO Add menus and submenus here as needed
        //cout << " 5 - "                    << endl;

        cout << endl;
        cout << " 0 - Quit and exit"                    << endl;
        cout << endl;
        cout << "\tChoice: ";
        menu_choice = Choice(0,7);

        try
        {
            Divider();
            switch (menu_choice)
            {
                case 1:
                    //Ask if member or provider
                    //if member AddPerson(DATASTRUCTURE mem);
                    //if provider AddPerson(DATASTRUCTURE pro);
                    break;
                case 2: //EditPerson();
                    break;
                case 3: //RemPerson();
                    break;
                case 4: //RunReports();
                    break;
                //TODO Add cases w/ calls here as menu grows
                //case 5: etc;

                case 0: cout << "\t\tGood-bye!" << endl;
                    break;
                default: cout << "\tInvalid selection, please enter a valid selection or 0 to quit." << endl;
                    break;
            }
        }
        catch (int x) { if(x == -1) ERS.tmIvalid();}
        Wait4Enter();
    } while (menu_choice != 0);

    Divider();

    //TODO Clean up and closing items to exit program

    return 1; // SUCCESS
}


/* TODO modify above menu functions to call subprograms or submenus as needed
void AddPerson(DATASTRUCTURE member)
{

}
 */