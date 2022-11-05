#include "functional.hpp"

using namespace std;

void Divider()
{
    cout << "************************************************" << endl;
}

void ClearScreen()
{
    system("clear");
}

void Safety()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
}

void Wait4Enter()
{
    cout << "\nPress Enter to continue..."; while (cin.get()!='\n');
}

int Choice(int low, int high)
{
    char c[20];
    int ci;

    try
    {
        cin.getline(c,20);
        ci = atoi(c);
        if(ci < (low) || ci > high) throw c;
    }

    catch(char * c)
    {
        cout << c <<" is an invalid selection, please make a selection between "
            << low << " to " << high << ": ";
        return Choice(low, high);
    }

    return ci;
}

bool YorN()
{
    string c;
    char ci;
    try
    {
        getline(cin, c);
        ci = toupper(c[0]);
        if(ci != 'Y' && ci != 'N') throw c;
    }

    catch(string c)
    {
        cout << c <<" is an invalid selection, please make a selection between yes(Y) or no(N): ";
        return YorN();
    }

    if(ci == 'Y') return true;
    return false;
}

//*************** validation **************
bool allNum(std::string x)
{
    for(uint i = 0; i < x.length(); i++)
    {
        if(!isdigit(x[i])) return false;
    }
    return true;
}

bool allLet(std::string x)
{
    for(uint i = 0; i < x.length(); i++)
    {
        if(!isalpha(x[i])) return false;
    }
    return true;
}

bool rightSize(string x, int min, int max)
{
    if( (int)(x.length()) >= min && (int)(x.length()) <= max) { return true;}
    return false;
}

