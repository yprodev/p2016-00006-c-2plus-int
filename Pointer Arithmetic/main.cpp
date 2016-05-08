#include <iostream>

using namespace std;

int main()
{
    // Simple arithmetic examples
    int* pint = new int[1000];

    int* temp;
    int* temp2;

    temp = pint + 5;
    temp = pint - 2;
    temp = pint * 2;    // Error Expression must have arithmetic or unscoped enum type
    temp = pint / 2;    // Error Expression must have arithmetic or unscoped enum type
    temp = pint % 2;    // Error Expression must have arithmetic or unscoped enum type

    ++temp;
    temp++;
    temp2 = ++temp;
    temp2 = temp++;

    // Arrays and pointer arithmetic
    int numbers[]{ 0,1,2,3,4,5,6,7,8,9 };
    int* pnumbers;

    pnumbers = &numbers[0];
    cout << *pnumbers << endl;      // numbers[0]   (0)
    pnumbers++;
    cout << *pnumbers << endl;      // numbers[1]   (1)
    pnumbers += 5;
    cout << *pnumbers << endl;      // numbers[6]   (6)

    // Pointers as array iterators
    /*
        1. A name of the array in the C++ is actually pointer to it's first element.
    */
    pnumbers = numbers;             // set pnumbers to start of the array

    while (pnumbers <= (numbers + 9))
    {
        cout << *pnumbers << '\t';
        ++pnumbers;                 // increment pnumbers
    }

    cout << endl;












    return 0;
}
