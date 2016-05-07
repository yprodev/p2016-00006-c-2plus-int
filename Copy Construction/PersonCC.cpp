#include "PersonCC.h"
#include <string.h>

PersonCC::PersonCC()                    // default constructor
{
    name = new char[10];
    strcpy_s(name, 10, "Anonymous");
}

PersonCC::PersonCC(char* nam)           // overloaded constructor
{
    int numchars = strlen(nam) + 1;
    name = new char[numchars];
    strcpy_s(name, numchars, nam);
}

PersonCC::PersonCC(const PersonCC& p)   // copy constructor
{
    int numchars = strlen(p.name) + 1;
    name = new char[numchars];
    strcpy_s(name, numchars, p.name);
}

PersonCC::~PersonCC()
{
    delete[] name;
}

char* PersonCC::GetName() const         // query function
{
    return name;
}
