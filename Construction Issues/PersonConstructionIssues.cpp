#include <string.h>
#include "PersonConstructorIssues.h"

PersonConstructionIssues::PersonConstructionIssues()                        // default constructor
{
    /*
        2. We know that word "Anonymous" has 9 characters but for string we need
        to allocate space for additional character for the NULL terminator - '\0'.
    */
    name = new char[10];
    strcpy_s(name, 10, "Anonymous");
}

PersonConstructionIssues::PersonConstructionIssues(char* nam)               // overloaded constructor
{
    int numchars = strlen(nam) +1;     // string length plus 1
    name = new char[numchars];
    strcpy_s(name, numchars, nam);
}

PersonConstructionIssues::~PersonConstructionIssues()                       // destructor
{
    /*
        3. Because we are allocating memory in our constructors using 'new', we should
        also delete that memory in the destructor using operator 'delete' to ensure that there
        is no memory leak which is in our class.
    */
    delete[] name;
}

char* PersonConstructionIssues::GetName() const                             // query function
{
    return name;
}


