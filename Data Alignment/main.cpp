#include <iostream>

using namespace std;
#include "DataAlignment.h"

int main()
{
    /*
        7. So we now can run this code:
    */

    cout << endl;
    cout << "Size of readable Employee1 = " << sizeof(Employee1) << endl;
    cout << "Size of padded Employee2 = " << sizeof(Employee2) << endl;
    cout << "Size of less readable but packed Employee3 = " << sizeof(Employee3) << endl;
    cout << "Size of pragma packed Employee4 = " << sizeof(Employee4) << endl;
    cout << "Size of aligned Employee5 = " << sizeof(Employee5) << endl;
    cout << "Size of simulated alignas Employee6 = " << sizeof(Employee6) << endl;


    return 0;
}
