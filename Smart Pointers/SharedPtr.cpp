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
/*
    4. The shared pointer allowes sharing.

    WE HAVE STOPPED COMMENTING HERE IN THIS PROJECT
*/
void sharedPtr()
{
    std::shared_ptr<Person> p1;                             // uninitialised shared_ptr
    cout << "p1 use_count: " << p1.use_count() << '\n';     // p1.use_count =
    std::shared_ptr<Person> p2(nullptr);                    // shared_ptr excplicitely initialised to nullptr
    cout << "p2 use_count: " << p2.use_count() << '\n';     // p2.use_count =
    std::shared_ptr<Person> p3(new Person);                 // shared_ptr initialised with a Person
    cout << "p3 use_count: " << p3.use_count() << '\n';     // p3.use_count = 1
    std::shared_ptr<Person> p4(p3);                         // shared_ptr as a copy of p3
    cout << "p3 use_count: " << p3.use_count() << '\n';     // p3.use_count = 2
    cout << "p4 use_count: " << p4.use_count() << '\n';     // p4.use_count = 2
    p3->UsePerson();                                        // UsePerson via p3
    p4->UsePerson();                                        // UsePerson via p4
    std::shared_ptr<Person> p5(std::move(p4));              // shared_ptr initialised by moving p4. p4 ...
    cout << "p3 use_count: " << p3.use_count() << '\n';     // p3.use_count = 2
    cout << "p4 use_count: " << p4.use_count() << '\n';     // p4.use_count = 0
    cout << "p5 use_count: " << p5.use_count() << '\n';     // p5.use_count = 2
    p3.reset();                                             // remove Person from p3
    cout << "p3 use_count: " << p3.use_count() << '\n';     // p3.use_count = 0
    cout << "p4 use_count: " << p4.use_count() << '\n';     // p4.use_count = 0
    cout << "p5 use_count: " << p5.use_count() << '\n';     // p5.use_count = 1
    p5.reset();
    cout << "p3 use_count: " << p3.use_count() << '\n';     // p3.use_count = 0
    cout << "p4 use_count: " << p4.use_count() << '\n';     // p4.use_count = 0
    cout << "p5 use_count: " << p5.use_count() << '\n';     // p5.use_count = 0
}
