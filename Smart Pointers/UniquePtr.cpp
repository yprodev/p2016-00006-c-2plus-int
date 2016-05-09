#include <iostream>
#include <memory>

using namespace std;


/*
    1. We've seen some of the problems assossiated with use of pointers. This project puts
    forward another possible solutions to some of these problems.

    Recent changes to C++ have reinvented the concept of scoped pointers. There now depracated
    ... ... has been replaced by the three new pointer types. These are previously availibale
    in the third party ... libraries. Three new pointer type have been added to the std or
    standard namespace. These are:

        unique_ptr
        shared_ptr
        weak_ptr

    In fact these types are not simple pointers. They are small template classes that will contain
    to manage a pointer.
*/
class Person
{
public:
    Person() { cout << "Person Constructor\n"; }
    ~Person() { cout << "Person Destructor\n"; }
    void UsePerson() { cout << "Using Person\n"; }
private:

};

void DoIt(const Person &)       // takes a reference to a Person as a parameter
{
    cout << "in DoIt\n";
}


void UniquePtr()
{
    /*
        2. Declaration of the unique_ptr variable. It's a template class so we have to tell what
        pointer it is going to contain. In our case it is a pointer to a Person class, so we tell
        it that it is going to contain a Person:

            p1(new Person);

        The unique pointer's name is p1. I've supplied a constructor to our p1 object and create
        it a new Person. At that point the person constructor should be called. If you note, we've
        no got any reference to any pointers to a Person in our project. All the pointers that
        contain within the p1 unique pointer object.

        We can then use our unique_ptr object as if it was a standard pointer. We check if p1 is
        valid and if it is, then we call UsePerson:

            {
                std::unique_ptr<Person> p2(std::move(p1));
                DoIt(*p2);
                p1 = std::move(p2);
                cout << "p2 going out of scope\n";
            }

        The block of code that follows is not part of this statement. This statement ends here:

            if (p1) p1->UsePerson();

        It is just a block of code to demonstrate another unique_ptr, p2 in this case, declared and
        initialised within block of code. We create the pointer p2 and we move the pointer within
        the p1 object - the Person we have created earlier, into pointer p2. p2 now owns the
        pointer to the Person was previously in p1.

        If we call DoIt(*p2); the Person which is in p2 is a Person create here:

            std::unique_ptr<Person> p1(new Person);

        That calls DoIt and it will cout << "In DoIt\n"; and we then move pointer that was in p2
        back into p1.

        When we reach the end of our block of code, p2 the unique pointer that we've declared
        here:

            std::unique_ptr<Person> p2(std::move(p1));

        goes out of scope. However, it does not own any pointers now. The pointer that it did own
        has been moved back into p1. Therefore no Person destructors will be called.
    */
    std::unique_ptr<Person> p1(new Person);         // p1 owns Person - calls Person constructor
    if (p1) p1->UsePerson();
    {
        std::unique_ptr<Person> p2(std::move(p1));  // now p2 owns Person previously in p1
        DoIt(*p2);
        p1 = std::move(p2);                         // ownership returns to p1
        cout << "p2 going out of scope\n";          // however, since p2 does not own a person no destructor
    }

    /*
        3. Since we have move own Person back into p1, we can now call UsePerson on p1. And when
        we reach end of our function the Person instance owned by p1 is automaticlly destroyed
        and p1 goes out of scope. We don't need to take care of deleting the Person ourselves.

    */
    if (p1) p1->UsePerson();

    // Person instance owned by p1 is automatically destroyed when p1 goes out of scope
}
