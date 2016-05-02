#include <iostream>

using namespace std;

#include "EmployeeInitialisation.h"

int main()
{
    Employee worker1;                                   // Will call the default constructor
    Employee worker2("Fred Flintstone", 1234, 99);      // overloaded constructor called
    Employee worker3{ "Fred Flintstone", 1234, 99 };    // very similar to worker2 but we use universal initialisation

    /*
        1. If we try to run a program and use our get functions we will get nothing out from
        our name and employee number.

        Just like for ordinary variables C++ does not initialize values for members of a class.
        We have several options available for this.
    */

    cout << worker1.GetName() << " " << worker1.GetEmpNo() << " " << worker1.GetExtension() << endl;
    cout << worker2.GetName() << " " << worker2.GetEmpNo() << " " << worker2.GetExtension() << endl;    cout << worker1.GetName() << " " << worker1.GetEmpNo() << " " << worker1.GetExtension() << endl;
    cout << worker3.GetName() << " " << worker3.GetEmpNo() << " " << worker3.GetExtension() << endl;


    return 0;
}
