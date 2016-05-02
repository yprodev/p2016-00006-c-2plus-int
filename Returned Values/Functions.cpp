#include <tuple>
using namespace std;
/*
int Sum(int n1, int n2)                     // return fundamental data type via return statement
{
    int temp = n1 + n2;
    return temp;
    // return n1 + n2
}

void Sum(int n1, int n2, int& total)        // return fundamental data type via reference parameter
{
    total = n1 + n2;
}
*/
struct SumAvgRet
{
    int sum;
    double avg;
};

SumAvgRet SumAvg(int n1, int n2)            // return complex data type (struct) via return statement
{
    SumAvgRet temp;
    temp.sum = n1 + n2;
    temp.avg = (n1 + n2) / 2.0;
    return temp;

    // Two another variants of this:
    // return SumAvgRet{ (n1 + n2), (n1 + n2) / 2.0 };
    // return { n1 + n2,(n1 + n2) / 2.0 };
}

/*
    1. Another way of returning values from a function without using a structure
    is to use a more modern feature called a tuple. In order to use a tuple you must
    #include <tuple> header file. Also add 'using namespace std;'.


*/

tuple<int, double>SumAvgTuple(int n1, int n2) // return std::tuple via return statement
{
    return make_tuple(n1 + n2, (n1 + n2) / 2.0);
}














