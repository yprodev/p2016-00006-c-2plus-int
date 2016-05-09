#include <iostream>

using namespace std;

int main()
{

    /*
        1. A pointer can point to any item in memory. A pointer is itself a variably memory.
    */
    int x = 99;             // integer x
    int* pint = &x;         // pointer to an integer
    int** ppint = &pint;    // pointer to a pointer to an integer

    cout << x << endl;
    cout << *pint << endl;
    cout << **ppint << endl;

    cout << "Address of x = " << hex << &x << endl;
    cout << "Contents of pint = " << hex << pint << endl;
    cout << "Address of pint = " << hex << &pint << endl;
    cout << "Contents of ppint = " << hex << ppint << endl;

    int* pnumbers[10];      // array of pointers to integers

    /*
        2a. Here we initialise the array. We allocate new integer on every pointer within the
        array. We then initialise the address pointer to our pointer (???) to the x, which is used
        in the for loop.

        We should there end up with the array of ten pointers to integers, each one pointing to an
        integer which contains a value 0, 1, 2, .., 9.

        We already know that array is itself a pointer. If we declare a pointer to a pointer to an
        int - ppnumbers, we can initialise that with the name of the array. Remember our array
        is an array of pointers to integers. pnumbers therefore is a pointer to pointer to an
        integers. It is a pointer to a first item in the array.
    */
    for (int x = 0; x < 10; ++x)
    {
        pnumbers[x] = new int;          // allocate memory for each pointer
        *pnumbers[x] = x;               // initialise memory at pointer
    }

    int** ppnumbers;

    /*
        2b. Here we are initialising ppnumbers to pointer to the first item of the array. We are
        looping and until we reach the end of the array and iterating through the array with
        ppnumbers. Everytime we increment ppnumbers we will be adding one pointer to ppnumbers
        in other words it will be iterating along the array one pointer at the time.

        Our cout therefore should print the first location in the array - 0, then the second
        location, dereferencing the poiters as it goes along.

        We should get the value zero - '0' through .. printed with a tab between them.
    */
    for (ppnumbers = pnumbers; ppnumbers <= &pnumbers[9]; ++ppnumbers)
    {
        cout << **ppnumbers << '\t';
    }

    cout << endl;

















    return 0;
}
