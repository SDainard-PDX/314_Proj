#include "functional.h"

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

bool charr_cp(char * & dest, const char * source)
{
    if(!source) return false;
    if(dest) { delete[] dest;}
    dest = new char[strlen(source) + 1];
    strcpy(dest, source);

    return true;
}

int Choice(int low, int high)
{
    char c[20];
    int ci = low - 1;

    try
    {
    cin.getline(c,20);
    ci = atoi(c);
    if(ci < low || ci > high) throw c;
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
    char ci{0};

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

