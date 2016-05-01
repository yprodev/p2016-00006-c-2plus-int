#include <iostream>

using namespace std;

struct date {
    int dd;
    int mm;
    int ccyy;
};

class Employee
{
public:

    // It's Employee default constructor
    Employee ()
        : salary(0.0), empNumber(0)
    {

    }

    // It's Employee overloaded constructor
    Employee (double sal, int eno)
        : salary(sal), empNumber(eno)
    {

    }
private:
    double salary;
    int empNumber;

};

/*
    4. Universal class initialization
*/

class UniversalEmployee
{
public:
    UniversalEmployee()
        : salary{ 0.0 }, empNumber{ 0 }
    {

    }

    UniversalEmployee(double sal, int eno)
        : salary{ sal }, empNumber{ eno }
    {

    }


private:
    doube salary = 0.0;
    int empNumber;
};


int main()
{
    // The next two lines show fundamental initialization
    int a = 0;
    int b(0);


    /*
        1. Universal initializer uses curly braces.
    */
    // The next line shows universal initialization of fundamental types
    int c{ 0 }; // initializes it to 0 (zero)

    // The next four lines show initialization of arrays and structs
    int numbers1[5] = { 0,1,2,3,4 };
    int numbers2[] = { 1,2,3,4,5 };
    int numbers3[10] = { 0 };
    date millenium = { 1,1,2000 };

    // The next four lines show universal initialization of arrays and structs
    int numbers4[5]{ 0,1,2,3,4,5 };
    int numbers5[]{ 1,2,3,4,5 };
    int numbers6[10]{ 0 };
    date firstmillenium{ 1,1,1000 };

    // The next two lines show initialization of objects of class Employee
    Employee worker1;
    Employee worker2(20000.00, 1234);

    // The next two lines show universal initialization of objects of class Employee
    Employee worker3{};
    Employee worker4{ 20000.00,1234 };


    /*
        2. vector<int> digits1(3, 999); - creates vector with 3 integers which values
        equal to 999 ([999, 999, 999]).
    */
    // The next line shows vector initialization
    vector<int> digits1(3, 999);

    /*
        3. With universal initialization vector<int> digits2{ 3,999}; - creates vector with
        2 integers which values equal to 3 and 99 ([3, 999]).

        To create vector like in previous example, we have to type the value three times -
        vector<int> digits2{ 999,999,999 };
    */
    // The next line show universal vector initialization
    vector<int> digits2{ 3,999 };








    return 0;
}
