#include "PersonDestructor.h"
#include <string.h>

/*
    3. A default constructor allocates some memory at the name pointer and copies in the name
    "Anonymous" into that pointer.
*/

PersonDestructor::PersonDestructor()
{
    name = new char[10];
    strcpy_s(name, 10, "Anonymous");
}

/*
    4. The overloaded constructor takes the name into that class, into the constructor, works
    out ... memory that requires allocation memory for it and then copies than copies the name
    passed in into that memory.
*/
PersonDestructor::PersonDestructor(char* nam)
{
    name = new char[strlen(nam) + 1];
    strcpy_s(name, strlen(nam) + 1, nam);
}
/*
    5. The UsePerson object just do anything in our class. So what happens at the end of the
    object's lifetime? Well, we have allocated memory in the heap in the constructor. There is
    NO corresponding deallocation. Our class therefore LEAKS memory.

    In order to prevent this in fact whenever you have any reasource that must be deallocated
    as a part of a class we can take advantage of DESTRUCTORS. Just like constructors, destructors
    our guarantee to be called.
*/

/*
    6b. Because we declared a destructor, now we should implement it. And our destructor must
    delete any resource that is allocated in the constructor, in our case the name (pointer in
    private section).
*/
PersonDestructor::~PersonDestructor()
{
    delete[] name;
}
/*
    7. Now the reasource is allocated in the constructor and any resources within the class
    that's are held entirely within the class are deleted in the destructor and our class in
    memory safe.

    Destructors are typically used for this type of memory deallocation. They can also be used
    for releasing other types of resorces such as database handles. Generaly if you allocate any
    resource in the constructor then you will need to code a destructor.
*/

void PersonDestructor::UsePerson()
{
    // Use PersonDesturctor Object
}

