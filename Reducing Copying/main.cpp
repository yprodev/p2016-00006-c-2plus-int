#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <string.h>

using namespace std;


/*
    1. We are going to look when copying occurs and how to minimize copying.
    To illuctrate this we have created a very basic class called 'Copy', which
    contains a default constructor, a destructor and a copy constructor.
*/
class Copy
{
public:
    Copy()                                      // default constructor
    {
        // cout << "Default constructor called - Allocating largeMemBlock" << endl;
        largeMemBlock = new int[1000000];       // 4000000 bytes
        memBlockSize = 1000000;
    }

    ~Copy()                                     // destructor
    {
        // cout << "Destructor called" << endl;
        if (largeMemBlock != nullptr) {
            // cout << "Deallocationg largeMemBlock" << endl;
            delete[] largeMemBlock;
        }
    }

    Copy(const Copy& clone)                     // copy constructor
    {
        /*
            2. Our copy constructor takes a new memory area copies a large memory
            block from the original object into a new memory block for the current
            object. memspy is a C standard library routine (<cstdlib>) which copies
            memory. And we are also move across the block size.

            In other words if we take the copy of our object what we actually end up
            with is one object (the source object) with formally n-bytes with integers
            allocated and a copy of an object with another formally n-bytes
            allocated.
        */
        // copy constructor
        cout << "Copy constructor called - Copying largeMemBlock" << endl;
        largeMemBlock = new int[clone.memBlockSize];
        memcpy(largeMemBlock, clone.largeMemBlock, clone.memBlockSize * 4);
        memBlockSize = clone.memBlockSize;
    }


    /*
        11. Recent modifications to the C++ language have introduced a new feature
        which helps to reduce copying. Move semantics.

        In some situations when we are taking copies we could actually move the item rather
        than copy it. For example, in our vector, queue and list we create a remporary copy
        within the parentacies - '{}' that copy is never used again. As soon as we exit
        statement of pushing that copy is destroyed. Therefore it makes no sence to copy the
        memory within that object and then immidiately delete it. It would make far more sence
        to simply move the memory or in other words take a copy of the pointer. That is what the
        move constructor does.
    */
    Copy(Copy&& clone)          // move constructor
    {
        // move constructor
        cout << "Move constructor called - Moving largeMemBlock" << endl;
        largeMemBlock = clone.largeMemBlock;
        clone.largeMemBlock = nullptr;
        memBlockSize = clone.memBlockSize;
    }
private:
    int* largeMemBlock;
    int memBlockSize;
};

/*
    3. Let's look how we use this object and where copying occurs.
*/
/*
    10b. So we could make this a reference to a 'c'.

        Copy& c
        or
        Copy* c
*/
void Doit1(Copy c)                              // copy (by value) parameter
{
    /*
        7b. So, one assignment Doit1(); the local 'Copy c' will have another 1m
        integers allocated. Once we leave the Doit1 function the destructor for 'c'
        would be called as it goes out of scope and it's memory would be deallocated.

    */
}

Copy Doit2()
{
    Copy x;
    return x;   // copy return
}

int main()
{
    /*
        4. First object will allocate 4m bytes or 1m integers.
    */
    Copy one;                   // default constructor

    /*
        5. This object will allocate another 4m bytes, copy the memory from one
        into two.
    */
    Copy two(one);              // copy construction

    /*
        6. The same is for the three, as with the previous one.
    */
    Copy three = two;           // copy construction by assignment


    /*
        7a. Here we passing an object by value. Passing by value causes a copy to take
        place in order to do that copy, the compiler will call the copy constructor.
    */
    Doit1(one);                 // copy parameter

    /*
        8. Doit2 has no parameters. But it does return a local copy 'x'. Because
        when we reach this line 'x' goes out of scope and we cannot return x
        directly, it cannot return x as a reference therefore it has to take a copy
        of x and return that.

        As it returns a new temporary copy of x will be taken it will allocate 1m
        integers that will get returned by Doit2(); This line (Doit2();) does not
        actually make any use of the returned value, so it will go out of scope
        and be destroyed. But the copies is definetely taken.
    */
    Doit2();                    // copy return

    /*
        9. Here we have used three standard library objects.

        When we are pushing we have used an universal initialization because the type
        of the vector is type Copy. The compiler can actually deduce what we are
        actually pushing is a default Copy.
    */

    /*
        10a. So how he can reduce copying? One way is to pass parameters into our functions
        via reference or via a pointer.

    */
    vector<Copy> v;
    v.push_back({});            // Pushing - it is like pushing a new copy of something
                                // Here it will create a new verison of Copy and push
                                // it onto the back of the vector.

    queue<Copy> q;
    q.push({});                 // the same copying is here

    list<Copy> l;               // the same copying is here
    l.push_back({});

    return 0;

}
