#pragma once
#ifndef EMPLOYEE_DEFINED
#define EMPLOYEE_DEFINED
#include <string>

using namespace std;

/*
    1. Classes are normally split over two files in a C++ project. We have a file contains class
    declaration and an implamentation file - contains code for implementation.

    This is DECLARATION FILE.

    Reasons:
        1. It separates declarating from the implementation.
        2. Any uses of your class must have access to the class declaration (in other word they
           have a file).
        3. It could be a security or confidentiality issue. If you put your code in your header file
           which is not forbidden, then that code would be exposed to the users of your class
           because they must have access to your header file.

           If you put confidential calculations or have no forbidd passwords in your header file
           so these would be visible to the users of your class. Obviously it is not a good practice.

    The header file has been protected with two include guards. The '#pragma once' prevent file to
    be included more than once in any compilation unit.

    #ifndef EMPLOYEE_DEFINED, #define EMPLOYEE_DEFINED, #endif (at the end) - prevent this file
    to being included. This is an older way of doing '#pragma once'.

*/

class Employee
{
public:     // Functions

    /*
        A1 - means another lesson but in the same project

        A1a. That is reasonable to expect that any function that request data from our class
        which gets data or returns data might be called a query function.

        This is also reasonable to suggest these functions will not modify class data. We could
        name our set function as modifer functions and get functions as query functions.

        To formilize this definition we should declare all of our query functions as const member
        functions. The keyword 'const' should be applied to the header for the member function
        in both the declararion and implementation.

    */
    void SetName(string name);
    void SetEmpNo(int empno);
    void SetExtension(int ext);
    string GetName() const;
    int GetEmpNo() const;
    int GetExtension() const;


protected:  // Functions

private:    // functions

public:     // data (avoid wherever possible)

protected:  // data (only used in class hierarchies and inheritance)

private:    // data
    string name;
    int employeeNo;
    int extention;

};
#endif // EMPLOYEE_DEFINED
