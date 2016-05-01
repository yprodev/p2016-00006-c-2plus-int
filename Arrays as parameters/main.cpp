// Arrays as parameters
#include <iostream>

using namespace std;

void doSomething(int nums[])
{
    nums[7] = 9999;
}

int main()
{

    int numbers[] = { 1,2,3,4,5,6,7,8,9,10 };
//  int numbers[]{ 1,2,3,4,5,6,7,8,9,10 }; // Universal initialisation


    /*
        1. Here array 'numbers' passed to the function by value. So, the array location will
        change.
    */
    doSomething(numbers);
    cout << numbers[7] << endl;

    return 0;
}
