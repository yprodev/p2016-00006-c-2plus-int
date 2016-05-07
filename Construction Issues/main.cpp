// Construction Issues
#include <iostream>
#include <vector>
using namespace std;
#include "PersonConstructorIssues.h"
#include "PersonDeletedCC.h"

int main()
{
    //PersonConstructionIssues me1("Simon");      // calls overloaded constructor
    //PersonConstructionIssues clone1("Simon");   // calls overloaded constructor

    //cout << me1.GetName() << endl;
    //cout << clone1.GetName() << endl;

    /*
        4. Here the problem occurs when we get to the end of this function
        and destruction starts take place. The first object will be destroyed
        - is clone2. The destructor deletes the memory for name. The second object
        to destroyed will be me2. The destructor is called. That is again attempt
        to delete the memory for the name, However, since both pointers were pointing
        to the same area memory for name, the second delete causes the error.
    */
    //PersonConstructionIssues me2("Simon");      // calls overloaded constructor
    //PersonConstructionIssues clone2(me2);       // calls compiler provided copy constructor

    //cout << me2.GetName() << endl;
    //cout << clone2.GetName() << endl;


    /*
        5. Code below has exactly the same problem as the previous one.
    */
    //PersonConstructionIssues me3("Simon");      // calls overloaded constructor
    //PersonConstructionIssues clone3 = me3;      // calls compiler provided copy constructor

    //cout << me3.GetName() << endl;
    //cout << clone3.GetName() << endl;

    /*
        7. We are calling copy constructor that has been deleted. This is possible
        solution but it can have some drawbacks.
    */
    //PersonDeletedCC me4("Simon");                 // calls overloaded constructor
    //PersonDeletedCC clone4("Simon");              // calls overloaded constructor

    //cout << me4.GetName() << endl;
    //cout << clone4.GetName() << endl;

    //PersonDeletedCC me5(me4);                     // calls copy constructor which has been deleted

    /*
        8. We are creating an instance of class PersonDeletedCC and then we are pushing
        that instance onto the end of the vector people. But we will get an error
        because the vector uses the copy constructor behind the scenes. There is no
        indication of doing this, so you need to be careful if you delete compiler
        supplier routines. In this case this code will not work even though it
        looks perfect at first sight.
    */
    PersonDeletedCC me6("Simon");
    vector <PersonDeletedCC> people(3);             // create vector of people with 3 elements
    people.push_back(me6);                          // push me4 onto the end of the vector



    return 0;
}
