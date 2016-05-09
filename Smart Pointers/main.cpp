#include <iostream>
using namespace std;

void UniquePtr();
void sharedPtr();
void WeakPtr();


int main()
{
    UniquePtr();

    sharedPtr();

    //int* pint = new int;
    //int* ref = pint;

    //*pint = 99;
    //*ref = 88;

    //delete pint;
    // how can we tell that ref is still a valid pointer?

    //cout << *ref << endl;

    WeakPtr();

    return 0;
}
