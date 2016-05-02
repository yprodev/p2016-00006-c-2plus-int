#include <tuple>
#include <iostream>

using namespace std;

tuple<int, double>SumAvgTuple(int n1, int n2);       // return std::tuple via return stmt - declaration

/*
    2a. Trailing Return - new feature of C++

        int Sum(int n1, int n2)
        {
            return n1 + n2;
        }

    We could use keyword 'auto' and the compiler will deduce the type of the function.

        auto Sum(int n1, int n2)
        {
            return n1 + n2;
        }

    And more common way of doing this is to use some ... trailing return, which is this:

        auto Sum(int n1, int n2) ->int
        {
            return n1 + n2;
        }
    This is excplicitly says that the return type is int. All these seems a little bit unnecessary.

    We can use also a decltype

        auto Sum(int n1, int n2) ->decltype(n1+n2)
        {
            return n1 + n2;
        }

    We can get the compiler to deduce the type of the some function based on an expression. It is
    also seems unnecessary to use this in common way.

    However we can use this in templates.
    If we turn our function Sum into a template function,

        template <typename T, typename U>
        auto Sum(T n1, U n2) ->decltype(n1+n2)
        {
            return n1 + n2;
        }

    Out function now has no types assossiated with it. Now it is a template function.

    In this case the auto is almost essential. If we were to replace this with an int and then
    somebody suppose to pass in doubles - the returned type would have to be a double
    and would be crash the compiler. However using this syntax (with templates) we can now
    call some with integers that stands at the moment, we can also call it with other data types.
    Or even with a char.
*/
template <typename T, typename U>
auto Sum(T n1, U n2) ->decltype(n1+n2)
{
    return n1 + n2;
}



int main()
{
    tuple<int, double>result;

    result = SumAvgTuple(10,15);
    cout << "Sum: " << get<0>(result) << ", " << "Average: " << get<1>(result) << endl;

    int num1 = 10;
    int num2 = 20;

    int w = Sum(num1, num2);
    cout << endl << w << endl;
    double x = Sum(10.75, 12.45);
    cout << endl << x << endl;
    int y = Sum('a', 1);
    cout << endl << y << endl;

    return 0;
}
