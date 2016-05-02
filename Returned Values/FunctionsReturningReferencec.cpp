/*
int& Sum(int n1, int n2)            // return reference via return stmt
{
    int temp = n1 + n2;
    return temp;                    // NOT ALLOWED to return reference to a temp a local variable
}

int& Increment(int n1)              // return reference via return statement
{
    return ++n1;                    // NOT ALLOWED because n1 is passed by value, and is, therefore
                                    // a local or temp variable
}

int& Increment(int& n1)             // return refernce via return stmt
{
    return ++n1;                    // OK, n1 is reference, not a local variable
}

int& Increment(const int& n1)       // return reference via return stmt
{
    return ++n1;                    // Will not compile because we are trying to modify a const
}
*/
