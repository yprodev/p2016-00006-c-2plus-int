// Optional / default parameters
#include <iostream>

using namespace std;


/*
    1. The default parameter only goes on function declaration, but not in function call.
*/
void Print(int numberOfPages, int numberOfCopies = 1);      // Declaration of Print function

int main()
{
    Print(10);          // Calling function without second parameter
    Print(5, 2);
    Print(1, 1);
    Print(11, 1);
    Print(15, 1);

    return 0;
}
