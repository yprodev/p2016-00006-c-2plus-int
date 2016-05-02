#include "EmployeeOverview.h"

/*
    2. This is IMPLEMENTATION FILE

    All these functions have :: before the name. This means that they are in scope for the
    employee class, they are incapsulated in the employee class and they have access to the private
    data members of the Employee class.

    Class could be inserted in the project in the number of ways. You could eigther isert it
    manually, inserting the header file and cpp files.

*/

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

string Employee::GetName()
{
    return name;
}

int Employee::GetEmpNo()
{
    return employeeNo;
}

int Employee::GetExtension()
{
    return extention;
}
