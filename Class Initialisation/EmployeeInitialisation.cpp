#include "EmployeeInitialisation.h"

/*
    5. These constructors obviously have to be implemented because they are the members of
    a class.
*/

Employee::Employee()                                // Default Constructor
    :name("Unknown"), employeeNo(0), extention(0)   // colon initialisation
{
    /*
        6. This is not the best way of initialisation. The better is use the colon initialisation.

    name = "Unknown";
    employeeNo = 0;
    extention = 0;
    */
}

Employee::Employee(string n, int eno, int e)        // Overloaded Constructor
    :name{ n }, employeeNo{eno}, extention{e}       // colon universal initialisation
{
    /*
    name = n;
    employeeNo = eno;
    extention = e;
    */
}

void Employee::SetName(string nam)
{
    name = nam;
}
void Employee::SetEmpNo(int empno)
{
    employeeNo = empno;
}
void Employee::SetExtension(int ext)
{
    extention = ext;
}

string Employee::GetName() const
{
    return name;
}

int Employee::GetEmpNo() const
{
    return employeeNo;
    // employeeNo = 0;      // not allowed in const function
}

int Employee::GetExtension() const
{
    return extention;
}
