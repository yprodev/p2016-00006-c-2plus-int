#pragma once
#include <string>
using namespace std;
#include "EmployeeExcplicit.h"

class PersonExcplicit
{
public:
    PersonExcplicit(char* name, int age, char sex);
    /*
        1b. If you apply an 'explicit' keyword to the conversion constructor...
    */
    /*
        1d. An 'excplicit' keyword is only applied is to the declaration on the conversion
        constructor in the class. Recent changes in a C++ mean that excplicit keyword can also
        now be applied to conversion operators as well as conversion constructors.
    */
    PersonExcplicit(EmployeeExcplicit e);           //conversion constructor
private:
    string name;
    int age;
    char sex;
};
