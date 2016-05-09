#include <iostream>
#include <memory>
using namespace std;

class Person
{
public:
    Person() { cout << "Person Constructor\n"; }
    ~Person() { cout << "Person Destructor\n"; }
    void UsePerson() { cout << "Using Person\n"; }
};

void WeakPtr()
{
    Person* p1 = new Person;
    Person* ref = p1;

    delete p1;
    // how can we tell that p1 is still a valid pointer?

    std::shared_ptr<Person> sp1(new Person);
    std::shared_ptr<Person> sp2;
    std::weak_ptr<Person> wp1;

    cout << "sp1 use count: " << sp1.use_count() << '\n';       // sp1.use_count = 1
    cout << "sp2 use count: " << sp2.use_count() << '\n';       // sp2.use_count = 0
    cout << "wp1 use count: " << wp1.use_count() << '\n';       // wp1.use_count = 0

                                                                // sharing group:
                                                                // --------------
    wp1 = sp1;                                                  // sp1, wp1

    cout << "sp1 use count: " << sp1.use_count() << '\n';       // sp1.use_count = 1
    cout << "sp2 use count: " << sp2.use_count() << '\n';       // sp2.use_count = 0
    cout << "wp1 use count: " << wp1.use_count() << '\n';       // wp1.use_count = 1

                                                                // if wp is valid return Person pointer
    sp2 = wp1.lock();                                           // sp1, wp1, sp2

    cout << "sp1 use count: " << sp1.use_count() << '\n';       // sp1.use_count = 2
    cout << "sp2 use count: " << sp2.use_count() << '\n';       // sp2.use_count = 2
    cout << "wp1 use count: " << wp1.use_count() << '\n';       // wp1.use_count = 2

                                                                // sp1 relinquish ...
    sp1.reset();                                                // wp1, sp2

    cout << "sp1 use count: " << sp1.use_count() << '\n';       // sp1.use_count = 0
    cout << "sp2 use count: " << sp2.use_count() << '\n';       // sp2.use_count = 1
    cout << "wp1 use count: " << wp1.use_count() << '\n';       // wp1.use_count = 1

                                                                // if wp1 is valid ..
    sp1 = wp1.lock();                                           // sp1, wp1, sp2

    cout << "sp1 use count: " << sp1.use_count() << '\n';       // sp1.use_count = 2
    cout << "sp2 use count: " << sp2.use_count() << '\n';       // sp2.use_count = 2
    cout << "wp1 use count: " << wp1.use_count() << '\n';       // wp1.use_count = 2

    sp1->UsePerson();
    sp2->UsePerson();
    // wp1->UsePerson();        // invalid with weak pointers. They are used purely for reference purposes

    sp1.reset();                // sp1 reset, but sp2 still holds a pointer to a Person
    if (wp1.expired())
    {
        cout << "wp1 is expired\n";
    }
    else
    {
        cout << "wp1 lives\n";  // therefore wp1 lives!
    }

    sp2.reset();                // sp2 reset, use_count = 0, Person object destroyed
    if (wp1.expired())
    {
        cout << "wp1 is expired\n";     // wp1 is expired!
    }
    else
    {
        cout << "wp1 lives\n";
    }

}

