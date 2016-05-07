#include <iostream>

using namespace std;

#include "EmployeeExcplicit.h"
#include "PersonExcplicit.h"


void DoSomething(PersonExcplicit p)
{
    // do something
}

int main()
{

    EmployeeExcplicit Fred("Fred Flinstone", 30, gender::Male, 1234);
    PersonExcplicit MrFlintstone(Fred);     // conversion construction

    /*
        1a. This code is from previous project about Conversion Construction.

        Conversion using conversion constructors is usually implicit. In this example we are
        converting implicitelly Fred Employee to Fred Person within the parameter of the
        DoSomething function.

        Any code that requires the conversion, as in this example, will automaticaly
        actioned by a compiler. However in some situations you may want to disallow implicit
        conversion and only allow EXCPLICIT conversion through a cast.

        If that is the case you still have to implement the conversion constructor, but now
        you have to mark the conversion constructor as only being allowable in excplicit
        conversions.
    */
    /*
        1c. ...the compiler will give you an ERROR here on the conversion at the implicit
        conversion.

            DoSomething(Fred);                      // implicit conversion construction

        It suggesting no suitable conversion constructor exists. If we force this
        conversion to an excplicit conversion using a cast like that:

            DoSomething((PersonExcplicit)Fred);     // excplicit conversion construction

        the compiler now realises that we really want to do the conversion. We've excplicetelly
        said that we want the conversion to be performed. Because the conversion constructor
        exists they can perform the conversion and everything is OK again.
    */
    DoSomething(Fred);                      // excplicit conversion construction


    return 0;
}
