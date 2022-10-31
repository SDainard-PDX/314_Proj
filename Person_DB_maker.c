#include <iostream> //in/out operations
#include <fstream> //file operations
#include <cstring> //char array operations
#include <stdlib.h> //rand() operations
#include <time.h> //time()
#include <string> // 'cause

using namespace std;

/*
Creates a csv file of a given size of people
*/


int main()
{
    //Variables
    string name = "", address = "", city = "", state = "", memstat = "";
    int  x=0, number = 0, zip = 0;
    char MP = 'P';

    string firstName[7] = {"Samuel", "Nevada", "Trae", "Ken", "Matt", "Poly", "Nihar"};
    string lastName[7] = {"Koppolu", "Duyck", "Kuleshova", "Williams", "Tyrell", "Dainard", "Newman"};
    string stateOpt[3] = {"WA", "OR", "CA"};
    string cityOpt[8] = {"Seattle", "Olympia", "Portland", "Salem", "Sacremento", "San Francisco", "Los Angles", "San Diego"};
    string stNames[8] = {"Elm", "Oak", "Pine", "Fir", "Spruce", "Willow", "Ash", "Popular"};
    string stAbrv[4] = {"St.", "Ave.", "Blvd.", "Lane"};
    string MemberStat[3] = {"Valid", "Valid", "Suspended"};

    srand(time(0)); //this keeps things more or less actually random no touchy

    //Build the possible vehicles from in file
    cout << " ... loading people choices ... " << endl;

    //Build a BD for testing
    cout << "Please enter number of entries you want: ";
    cin >> x;
    cout << "\nMembers [M] or Providers [P]? ";
    cin >> MP;
    cout << "\n ... please wait, building test data ... " << endl;

    //create and open out file
    ofstream output_file("new_person_DB.txt");

    //Write to file
    for( auto i = 0; i < x; i++)
    {
        number = (rand() % 1000000000); //creates a random 9 digit number
        name = firstName[rand() % 7] + " " + lastName[rand() % 7];
        address = to_string(rand() % 1000) + " " + stNames[rand() % 8] + " " + stAbrv[rand() % 4];
        city = cityOpt[rand() % 8];
        state = stateOpt[rand() % 3];
        zip = rand() % 10000; //creates a random digit number
        if (MP == 'M') { memstat = MemberStat[rand() % 3]; }

        cout << number << "," << name << "," << address << "," 
                    << city << "," << state << "," << zip; 
        if(MP == 'M') { cout << "," << memstat; }
        cout <<  endl;
        
        output_file << number << "," << name << "," << address << "," 
                    << city << "," << state << "," << zip; 
        if(MP == 'M') { output_file << "," << memstat; }
        output_file <<  endl;
    }

    output_file.close();

    cout << "\nFile is ready, file name is 'new_person_DB.txt';\n" << endl;
    cout << "File WILL BE OVERWRITTEN if run again." << endl;
    cout << "I recommend changing person to Member or Provider w/ mv.\n" << endl;

    return 1;
}
