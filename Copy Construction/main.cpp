#include <iostream>
#include <vector>
using namespace std;
#include "PersonCC.h"

int main()
{
    /*
        1. We learned that copy constructor supplied by the compiler does a shallow
        copy. If the class contains pointers which are allocated to memory on the
        heap in particular the compiler provide a copy constructor is not sufficient.

        It made the copy of the values at the pointer rather than taking a copy of
        a memory at the pointer.

        We have seen that other functions such as vectors and if many other stdl
        classes use the copy constructor. So if we delete it a deleting copy
        constructor can cause the functions to fail.

        We are going to define our own copy constructor.
    */

    PersonCC me1("Simon");      // calls overloaded constructor
    PersonCC clone1("Simon");   // calls overloaded constructor

    cout << me1.GetName() << endl;
    cout << clone1.GetName() << endl;


    PersonCC me2("Simon");      // calls overloaded constructor
    PersonCC clone2(me2);       // calls copy constructor

    cout << me2.GetName() << endl;
    cout << clone2.GetName() << endl;


    PersonCC me3("Simon");      // calls overloaded constructor
    PersonCC clone3 = me3;      // calls copy constructor

    cout << me3.GetName() << endl;
    cout << clone3.GetName() << endl;


    vector <PersonCC> people(3);    // create vector of people with 3 elements
    people.push_back(me3);          // push me3 onto the end of the vector

    /*
        3. If your class contains pointers which are allocating and deleting
        within a class that it is kindly likely that you will require the copy
        constructor. You may not know when you need the copy constructor. The stdl
        and particular use the copy constructor behind the scenes and there may be
        other third party products that which use copy constructors too.
    */




    return 0;
}
