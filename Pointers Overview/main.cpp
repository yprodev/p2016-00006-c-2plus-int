#include <iostream>
using namespace std;
#include <memory.h>

struct Data {
    int dd;
    int mm;
    int ccyy;
};

int main()
{
    int* pint;      // The type of pint is: the pint is a pointer to an int

    // Pointers are initialised in one of several ways :

    pint = 0;                   // old method of initialisation
    pint = nullptr              // newer method of initialisation

    int* pint2{ nullptr };      // creation and universal initialisation
    int x = 999;
    pint = &x;                  // initialised with the address of x


    /*
        1. Operator 'new' finds some memory in this case 4 bytes of an integer returns the
        address of the dynamicly allocated memory and assigns that address to pint.
    */
    pint = new int;             // initialised with the address of a dynamiclly allocated integer


    /*
        2. Pointers can be access by dereferencing the pointer using the asterisk operator.
        The asterisk operator is used to simple data types or the arrow operator for complex
        types.
    */
    pint = new int;             // initialised with the address of a dynamiclly allocated integer
    Date* pDate = new Date;     // pointer to Date initialised with dynamic date

    *pint = 99;                 // dereference pint & set the value at pint to 99
    cout << *pint << endl;      // dereference pint & retrieve it's value

    pDate->dd = 21;             // dereference pDate & set it's dd to 21
    cout << pDate->dd << endl;  // dereference pDate & retrieve it's dd member


    /*
        3. C++ uses strongly type pointers. Conversion between pointer types is rare and is
        usually restricted to inheritance hierarchy where conversion takes place we have up or
        down within a hierarchy.

        C++ can do anything that C can do and more. C uses the concept of void pointers or
        void asterisk. In C++ the use of void pointers in usually ... to casts to and from the
        void pointer. The void pointer is usually only used in very low-level programming.
    */
    //              'C'
    pint = (int*)malloc(sizeof(int));           // pint = new int;
    free(pint);                                 // delte pint;

    pint = (int*)malloc(sizeof(int) * 10);      // pint = new int[10];
    free(pint);                                 // delete [ ] pint;


    return 0;
}
