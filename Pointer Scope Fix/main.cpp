#include <iostream>

using namespace std;


class BigClass
{
public:
    BigClass()
    {
        pDouble = new double[1000];
    }
    void Tidy_Up()
    {
        /*
            3a2. Here we delete pDouble. That will delete one double. But we have allocated a
            1000 doubles. So, delete should be with square brackets.
        */
        delete [] pDouble;
    }
    // No destructor so automatic cleanup won't happen!
    /*
        3a. The first error was that the BigClass had no destructor.
    */
    ~BigClass()
    {
        /*
            3a1. In the destructor we want to delete the pDouble pointer. That was allocated above
            (in constructor). This ectually exposes another error.
        */
        /*
            3a3. .. as should the delete in our destructor.
        */
        delete[] pDouble;
    }
private:
    double* pDouble;

};

struct BigMem {
    int* pint;
    double darray[500];
};

void doit(BigClass bc)
{
    BigMem* pLocalBigMem;
    pLocalBigMem = new BigMem;
    pLocalBigMem->pint = new int[1000];
    /*
        3b1. First of all, error 1 in this function says that pLocalBigMem goes out of scope
        but memory is still allocated. Therefore we need to delete that memory:

            delete [] pLocalBigMem->pint;

        That is deleted the integers that are pointed to them (???).
    */
    delete [] pLocalBigMem->pint;

    /*
        3b2. Next we need to delete the structure. Those two deletes corresponds to the 2 new's
        that above.
    */
    delete pLocalBigMem;

    /*
        3c. As for the error 2 BigClass is called by value. Well, we've now implemented the
        destructor in our class. Therefore BigClass is memory correct and won't cause any
        problems.
    */

    // (1) pLocalBigMem goes out of scope but memory is still allocated
    // we've just lost (sizeof(double) * 500) + (sizeof(int) * 1000) bytes!
    // (2) BigClass is called by value (which in itself is a problem!). However,
    // in this case we are not even tidying up the memory for the copy - no destructor
}


int main()
{
    /*
        3d1. Dereferencing uninitialised pointer - there is no way we can tell it has been
        initialised or not. And let's we forcibly initialise that.

            int* pint{ nullptr };

        Now we initialised that.
    */
    int* pint{ nullptr };

    /*
        3d2. We can now add code around our dereference of the pointer to check whether the pointer
        was initialised. Now pint only be dereferenced if it is not null pointer.
    */
    if(*pint != null) {
        cout << *pint << endl;          // (3) dereferencing uninitialised pointer
    }

    pint = new int;

    /*
        3e1. The next problem we've deleted pint. The deleting a variable does not .. it's value (???).
        Therefore we should do everytime we delete a pointer is reinitialise it to nullptr.

            pint = nullptr;

    */
    delete pint;
    pint = nullptr;
    /*
        3e2. Then whenever we try to use it, we can check whether it is null pointer or not.
    */
    if(pint != nullptr)
    {
        cout << *pint << endl;          // (4) dereferencing deleted pointer - delete does not change the pointer value
    }

    BigMem* HugeMem[10];
    for (int x = 0; x < 10; ++x)
    {
        HugeMem[x] = new BigMem;
        HugeMem[x]->pint = new int[100];
    }

    for (int x = 0; x < 10; ++x)
    {
        /*
            3f. The next problem is here. We delete the structure HugeMem, but we don't delete the
            individual item pointed to within the structure. We don't delete the memory at pint.

            Again we have symetrical memory management for our HugeMem structure - HugeMem array.

            We have new the square brackets - delete the square brackets. New without square
            brackets - delete without square brackets. So our memory management is symetrical.

        */
        delete[] HugeMem[x]->pint;
        delete HugeMem[x];
        // (5) HugeMem struct deleted but not memory at pint pointer
    }

    /*
        3g. Finally, we have deleting pint again just to be sure. Whether this is a BAD practice.
        We now know how we can easially protect it.
    */
    // (6) Have we deleted pint??? Let's do it again to be sure.
    if (pint != nullptr) {
        delete pint;
        pint = nullptr;
    }







    return 0;
}
