#pragma once
#include <string>
using namespace std;
#include "EmployeeConversion.h"


/*
    1. Sometimes it can make sence to construct one object from the similar, but not the same
    type of object. Constructing one object from exactly the same type is called copy
    construction.

    Here we gonna look at creating one object from another object of a similar type - this is
    called CONVERSION CONSTRUCTION.

    We have defined a PersonConversion class. It has 3 data members (string name, int age, char
    sex).

    We also have EmployeeConversion class. It contains a very similar data set or data members.
    It also contains a string name, int age and a GENDER sex, and also employeeNumber.

    These classes sufficiently similar for us to be able to make sence to be able to create
    Person from an Employee. In doing so we simply have to copy the name across the Employee to
    the Person. The sex has to be ... to conversion and we can simply ignore the employeeNumber.


*/
class PersonConversion
{
public:
    PersonConversion(char* name, int age, char sex);
    /*
        3. And in this class we have added another constructor to our class called
        PersonConversion. This particular constructor takes an Empoyee as a parameter.
        Just like other constructors in the class the constructor is called the same
        as the class name. The conversion constructor takes a single parameter
        of an Employee object. Object should not be passed by value. It should be passed by
        reference. And EmployeeConversion& - is reference.

        And also we would not expect the conversion to a Person to affect the Employee this
        being passed in. Therefore we passed a const reference to an Employee.

    */
    PersonConversion(const EmployeeConversion& e);
private:
    string name;
    int age;
    char sex;
};
