#include "EmployeeStatic.h"

/*
    4. This is the storage for our lastEmpNo variable. As you can see it has been scoped to an
    EmployeeStatic class. It's of type integer. And in this instance we've initialised it
    to have the value 10000.

    Static class member variables are initialise the default for the type. In this case the
    default initialisation for lastEmpNo would be 0.
*/
int EmployeeStatic::lastEmpNo = 10000;      // static variable


/*
    5. Our constructor simply set empNo to incremented lastEmpNo. In this case we are setting
    a member variable, an instance variable to the value of a static variable and incrementing
    it. Everytime we instantiate a new employee setting object we get another incremented empNo.
    This means that we will get unique employee numbers, no matter how many classes or objects
    of the class employee settings we create.
*/
EmployeeStatic::EmployeeStatic()
{
    empNo = ++lastEmpNo;
}

int EmployeeStatic::GetEmpNo()
{
    return empNo;
}
