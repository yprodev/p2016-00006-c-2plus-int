#include <iostream>

using namespace std;

#include "PersonConversion.h"
#include "EmployeeConversion.h"


/*
    5. This doSomething function takes Person as a parameter. The code within the function
    does not matter. The conversion is going to take place when we call the function.
*/
void doSomething(PersonConversion p)
{
    // do something
}


int main()
{
    EmployeeConversion Fred("Fred Flinstone", 30, gender::Male, 1234);

    /*
        6. Here we excplicitly convert Fred Employee to Fred Person.
    */
    PersonConversion MrFlintstone(Fred);    // conversion construction

    /*
        7. The type of object passed into doSomething is an Employee. The compiler now
        implicitely know the type declared a conversion constructor (see function
        declaration and a parameter passed there) which takes an Employee as a parameter
        and returns a Person. It works automaticaly when we call a function. Obviously
        it would not be meaningful to construct objects from totally diverse and desimilar
        objects. However where the objects are sufficiently similar this technique can be used.
    */
    doSomething(Fred);              // implicit conversion construction

    return 0;
}
