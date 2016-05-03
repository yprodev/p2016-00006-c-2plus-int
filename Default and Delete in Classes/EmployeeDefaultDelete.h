#pragma once
#include <string>
using namespace std;

class Employee
{
public:     // function

    /*
        1b. But our class has no default constructor provided. In this instance the compiler
        will not provide one, because we have started to provide overloaded provided ourself.

        The 'default' keyword can be used to force the compiler to provide it's own
        implementation for the default constructor.


        Employee() = default;
        it will cause the compiler to generate an implementation for the default constructor.
    */

    Employee() = default;

    /*
        2. Delete is the oposite for default. Coding the keyword delete is explicetely says
        we do not want a compiler to provide this function.

        There could be instances were you want the compiler to not generate a default for you.
    */

    // Employee() = delete;

    Employee(string nam, int empno, int ext);   // Overloaded constructor
    void SetName(string nam);
    void SetEmpNo(int empno);
    void SetExtension(int ext);
    string GetName() const;
    int GetEmpNo() const;
    int GetExtension() const;

private:    // data

    string name;
    int employeeNo;
    int extention;

};

