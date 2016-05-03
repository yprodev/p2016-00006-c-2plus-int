// Class inlining
#include <iostream>

using namespace std;


/*
    1. This lesson we look at inlining and the pros and cons of using various technics.

    The first type of inline we will look at is a historic type of inline in which generaly
    should not be used in C++ even if it does work.

    We have defined a macro. It is the hash defined macro which uses a preprocessor.
*/
#define Add2(x,y) x+y      // C preprocessor should NOT be used


/*
    3. In this function I've declared a function as inline. It's a function that has two int.
    We've used 'inline' modifier to request the compiler to inline this function.
*/
int inline Add2Int(int n1, int n2)
{
    return n1 + n2;
}

int main()
{

    int num1 = 100;
    int num2 = 200;
    double num3 = 333.33;
    double num4 = 111.11;


    /*
        2. Calling Add2 macro there is no type assosiated with that macro. Macro coded with a
        #defined are not type safe.
    */
    // The following 3 lines use the Add2 #defined macro expanded inline
    cout << Add2(10, 20) << endl;
    cout << Add2(num1, num2) << endl;
    cout << Add2(num3, num4) << endl;

    /*
        4. This function is used. This is a direct equivalent of the hash defined macro. Except
        that in this case the macro is totaly type safe, because the inlined function has
        specific types on the two parameters.

        There is one further form of inlining - that is inlining of class members.
    */
    // The following 3 lines cause Add2Int to be expanded in place like a macro
    cout << Add2Int(10, 20) << endl;
    cout << Add2Int(30, 40) << endl;
    cout << Add2Int(num1, num2) << endl;

    return 0;
}
