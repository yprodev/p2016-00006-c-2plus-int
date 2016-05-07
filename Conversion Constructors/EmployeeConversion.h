#pragma once
#include <string>

using namespace std;

enum class gender { Male, Female, Uknown };


/*
    2. If we wish to convert an Employee to a Person the conversion must be done in a Person
    class.
*/
class EmployeeConversion
{
public:
    EmployeeConversion() = delete;
    EmployeeConversion(char* name, int age, gender sex, int empno);
    string GetName() const;
    int GetAge() const;
    gender GetSex() const;
    int GetEmpNo() const;
private:
    string name;
    int age;
    gender sex;
    int employeeNumber;
};
