// Static Class members
#include <iostream>

using namespace std;

#include "EmployeeStatic.h"
#include "PersonStatic.h"

int counter()
{

    /*
        1. Static variables are declared within a function. They have local scope - that means
        they can be visible and only used within the function at which they were declared. They
        also have static persistence or lifetime. Their lifetime is effectively the lifetime
        of a program.
    */
    static int count;       // local scope (visibility), static persistence (lifetime)
    ++count;
    return count;
}

int main()
{
    /*
        2. Here we have a for loop that calls the counter function 5 times. The first time the
        counter is called the count variable will already be ..., it created outside the
        function. It is also initialised by the compiler to the default for the type.

        So, the first time we call counter the value of the count would be 0. Counter than increaments
        count and this count is returned. As we leave the count, the variable count is not destroyed
        like any local variable would be. Instead it's value is held and kept until the next time
        we call counter.
    */
    for (int x = 0; x < 5; ++x) {
        cout << counter() << '\t';
    }
    cout << endl << endl;

    // The following lines demonstrate static class members used to create unique v....
    cout << "Unique employee numbers: " << endl;
    EmployeeStatic we;
    EmployeeStatic you;

    cout << we.GetEmpNo() << endl;
    cout << you.GetEmpNo() << endl;


    /*
        6. PersonStatic::GetNumPeople() - this is the usual way that we call static member
        function. We don't call them on any instance of a class or than you can do so. Instead
        we call it on the class itself.
    */
    // The following lines demonstrate static class members used for resource count
    cout << "Resource counting: " << endl;
    cout << PersonStatic::GetNumPeople() << endl;                   // should return a 0 value
    PersonStatic him;
    cout << "Plus one employee: " << him.GetNumPeople() << endl;    // this is just a proof that it is possible
    PersonStatic* her = new PersonStatic;                           // here we creating a pointer to a person - there is no difference - the default constructor will be called
    cout << "Before deleting an instance " << PersonStatic::GetNumPeople() << endl;
    delete her;                                                     // deleting the pointer - the destructor should be called
    cout << "after deleting the instance " << PersonStatic::GetNumPeople() << endl;



    return 0;
}
