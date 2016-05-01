// Reference Parameters
#include <iostream>

using namespace std;

// Declaration of a function
void SumAvgMinMax1 (int n1, int n2, int& sum, double& avg, int& min, int& max);

/*
    8b. Here we just added const keyword to prevent changing the data in n1 and n2.
*/
void SumAvgMinMax2 (const int& n1, const int& n2, int& sum, double& avg, int& min, int& max);

int main()
{
    int num1 = 22;
    int num2 = 33;
    int total;
    double average;
    int smaller;
    int larger;

    /*
        2. Reference value or reference parameter can be used to return values from functions.
    */
    SumAvgMinMax1(nu1, num2, total, average, smaller, larger);

    /*
        7. We are calling SumAvgMinMax2 function n1 is changed because n1 is a reference
        to an int the function that will affect the value num1 variale within main.

        After the call of SumAvgMinMax2 num1 will have a value of 999.
    */
    SumAvgMinMax2(nu1, num2, total, average, smaller, larger);

    /*
        8a. So, why do we have reference parameters. Well for the start off reference parameters
        stop coping.

        We are always pass or normally pass parameters which that are larger that built in
        data types by reference.

        And how we can prevent the function of modifying data on intentionaly? We use the 'const'
        keyword. So, declaring SumAvgMinMax2 we have add const reference to an int.
    */

    return 0;
}

void SumAvgMinMax1 (int n1, int n2, int& sum, double& avg, int& min, int& max)
{
    sum = n1 + n2;
    avg = (n1 + n2) / 2.0;
    min = (n1 < n2) ? n1 : n2;      // if n1 < n2 result is n1 else n2
    max = (n1 > n2) ? n1 : n2;

    /*
        3. Note there is no any return statement. All values is returned by using
        reference parameters.
    */

    /*
        4. Reference parameters are all very fine. But they do have some serious side effects.
        For example, within a function if we were allowed to pass n1 and n2 as reference parameters
        we could change the values of n1 and n2 within the function, and this would change the values
        in the program that cores SumAvgMinMax1.
    */


    /*
        5. If I were to attempt to change n1. It is quite exceptable. But the value of n1
        is only changed within SumAvgMinMax1 function.
    */
    // n1 = 99;
}

/*
    8c. And adding const keyword here
*/
void SumAvgMinMax2 (const int& n1, const int& n2, int& sum, double& avg, int& min, int& max)
{
    sum = n1 + n2;
    avg = (n1 + n2) / 2.0;
    min = (n1 < n2) ? n1 : n2;      // if n1 < n2 result is n1 else n2
    max = (n1 > n2) ? n1 : n2;

    /*
        6. If however we change the value of n1 within SumAvgMinMax2 function because n1
        is a reference. So, the same variable in the call of this function withing the main
        function.
    */

    /*
        8d. Here we can't now change n1 parameter. Therefore we built a rule for reference
        parameters.

        For input-only parameters such as 'int n1' and 'int n2' in our SumAvgMinMax1 function.
        The built-in types can be passed by value. The compiler knows how to pass these types
        effitiently and the space taken on by the coping is minimum.

        Anything larger then built-in data types, anything that needs a header file to implement
        - and that could include structures and classes should be passed by a reference.

        If you don't want the functions to modify the values within the data structure you should
        pass it by const reference.

        If you want to return value from a function this must be reference parameter and they can't be
        const reference.
    */
    n1 = 999;

}
