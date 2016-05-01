#include <iostream>

using namespace std;

int add(int number1, int number2);

int main()
{
    /*
        1. Functions overview
    */
    int x = 10;
    int y = 20;
    int answer;

    /*
        2. When this function is wrong:
            answer = add(x, y);
        the values of x and y are copied into two local variables num1 and num2 within
        the function. This has several side effects.

        First, the coping this will take a fraction of a time. Well, of the case built-in
        data types the time is taken to copy them is minimum, it is also uses space on the
        stack as all parameters are normaly passed on the stack.

        When the result is returned the value returned is also copied back to the original
        program. This is quite reasonable because the moment we need the add function the
        values are stored in num1 and num2 (localt ot add function) and result (which is
        also local) are all destroyed.

        So value must be copied back to be assigned to answer.
    */

    answer = add(x, y);


    return 0;
}

int add(int num1, int num2) {
    int result;
    result = num1 + num2;
    return result;
}
