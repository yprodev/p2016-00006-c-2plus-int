#pragma once

class EmployeeStatic
{
public:
    EmployeeStatic();       // default constructor
    int GetEmpNo();

private:
    int empNo;              // class member variable - created on instantiation

    /*
        3. Whereas class member variables are instance scope, static member variables are
        sometimes going to be class scope. There is one instance of a class scope variable
        for all instances of the class.
    */
    static int lastEmpNo;   // placeholder - no storage created on instantiation

};
