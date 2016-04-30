#include <iostream>

using namespace std;

#include "Unions.h"

int main()
{
    Memory space;

    cout << endl;
    cout << "Size of Employee struct = " << sizeof(Employee) << endl;
    cout << "Size of Memory union = " << sizeof(Memory) << endl << endl;

    // use space.int_number
    space.int_number = 99;
    cout << "Value of int_number in Memory union = " << space.int_number << endl;
    // use space.float_number
    space.float_number = 33.3333f;
    cout << "Value of float_number in Memory union = " << space.float_number << endl;


    /*
        4. This invalid use of space.int_number means that any member of a union
        can only be used in the isolation. You can't start use one member, suddenly
        switch to another member and then back to the original member interchangibly,
        expecting data to held over from one member to another.
    */
    // invalid use of space.int_number
    cout << space.int_number << endl << endl;

    // practical use of unions in bits manipulation
    Bitfields byte;
    byte.wholebyte = 0;
    byte.bits.bit0 = 1;
    byte.bits.bit3 = 1;
    cout << "Value of wholebyte in Bitfields union " << (int)byte.wholebyte << endl;














    return 0;
}
