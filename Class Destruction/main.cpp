#include <iostream>

using namespace std;

#include "PersonDestructor.h"

/*
    1. Here we want to discuss what happens with the object life cycle when object is destroyed.
    An object can reach the end of it's lifetime in various different ways (the first varian is
    below).
*/
void DoSomethingWithPerson(PersonDestructor p)
{
    p.UsePerson();
    // p goes out of scope and gets destroyed here
}

void CreateAndUsePerson()
{
    PersonDestructor p2;
    p2.UsePerson();
    // p2 goes out of scope and gets destroyed here
}

int main()
{
    PersonDestructor* p3 = new PersonDestructor;
    p3->UsePerson();

    delete p3; // p3 goes out of scope and gets destroyed here

    return 0;
}

/*
    2. These can cause problems.
*/
