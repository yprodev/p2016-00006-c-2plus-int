#include <iostream>

using namespace std;


/*
    1. Pointers are one of the common causes for failure in C++. When use correctly - they are
    powerful programming tool. However, if use carelessly or improperly they can lead to memory
    leaks, corruption and program failure.
*/
class BigClass
{
public:
    BigClass()
    {
        pDouble = new double[1000];
    }

    /*
        2a. First of all we have no destructor here.
    */
    void Tidy_Up()
    {
        delete pDouble;
    }
    // No destructor so automatic cleanup won't happen!
private:
    double* pDouble;

};

struct BigMem {
    int* pint;
    double darray[500];
};

void doit(BigClass bc)
{
    /*
        2b. In our doit function our BigMem structure goes out of scope. We knew it, but we don't
        delete it. There is far as operating system is concerned, we still have within our BigMem
        500 doubles and our 1000 integers. This is ... case in use, however, because we have lost
        the pointer to the BigMem because it is gonna has to scope (???), we can no longer access
        it. This is turned into a memory leakage.

        As also .. .... .. but this doit function BigClass is passed into our function by value.
        Passing by value is not itself a problem. It will cause copying - we have not rather copy
        constructor declared and so on. However, in this case we are not even calling a Tidy_Up
        routine for the copy. So, no destructor is declared. So, when the copy of 'bc' goes out of
        scope no .. will be done (???). We will end up with more memory leakage.
    */
    BigMem* pLocalBigMem;
    pLocalBigMem = new BigMem;
    pLocalBigMem->pint = new int[1000];
    // (1) pLocalBigMem goes out of scope but memory is still allocated
    // we've just lost (sizeof(double) * 500) + (sizeof(int) * 1000) bytes!
    // (2) BigClass is called by value (which in itself is a problem!). However,
    // in this case we are not even tidying up the memory for the copy - no destructor
}


int main()
{
    int* pint;

    /*
        2f. Here we will got a warning that we are using pointer before initialise it.
        In other words we potentially got all these memory errors in our program, but the compiler
        is NOT picking up in ANY OF THEM. A lot is of maintain very silly (???). So how he can fix
        them? SEE Pointer Scope Fix project.
    */
    cout << *pint << endl;          // (3) dereferencing uninitialised pointer

    pint = new int;
    delete pint;

    /*
        2c. *pint will still contain the same address as it was allocated to.
    */
    cout << *pint << endl;          // (4) dereferencing deleted pointer - delete does not change the pointer value

    BigMem* HugeMem[10];
    for (int x = 0; x < 10; ++x)
    {
        HugeMem[x] = new BigMem;
        HugeMem[x]->pint = new int[100];
    }

    for (int x = 0; x < 10; ++x)
    {
        /*
            2d. We delete HugeMem structure. However, the structure contained the 100 integers. We
            have not deleted that memory. Deleting a structure will not delete all the memory it
            contains. It would delete the structure itself. But as far as ... .. concerned we still
            have 100 integers allocated. All we have done we lost that pointer to those 100
            integers. Again we are leaking 400 bytes of memory.
        */
        delete HugeMem[x];
        // (5) HugeMem struct deleted but not memory at pint pointer
    }

    /*
        2e. We are deleting pint. pint was deleted previously:

            pint = new int;
            delete pint;
            cout << *pint << endl;

        Deleting a piece of memory twice has undefined results. This is going to cause an error.
    */
    // (6) Have we deleted pint??? Let's do it again to be sure.
    delete pint;






    return 0;
}
