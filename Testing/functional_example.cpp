#include "functional_example.hpp"

using namespace std;

void Divider(streambuf* t)
{
    iostream x(t);
    x << "************************************************" << endl;
}

bool ClearScreen()
{
    system("clear");
    return true;
}

void Safety(streambuf *t)
{
    istream x(t);
    x.ignore(numeric_limits<streamsize>::max(), '\n');
    x.clear();
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