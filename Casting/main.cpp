#include <iostream>

using namespace std;

class Person
{
public:
    void GrowOlder()            // modifier function
    {
        ++age;
    }
    int GetAge() const          // query function
    {
        return age;
    }
private:
    int age = 21;

};

void DoSomething(const Person* p)
{
    // do something with Person
    // p->GrowOlder();  // ERROR! p is a pointer to a const Person. Can't call modifier
    // functions on const object.

    // workaround
    Person* nonconst;
    nonconst = const_cast<Person*>(p);  // effectively removes the const attributes from
                                        // function paramter. Only then we can call modifier
                                        // functions.
    nonconst->GrowOlder();

    cout << "Value of p and nonconst pointers: " << hex << p << " " << nonconst << endl;
    // Both p and nonconst point to the same address (same object) p is const, nonconst in not.
    cout << p->GetAge() << endl;
}

/*
    1. Type conversion in C++. Type conversion is also called CASTing. C++ has three ways to
    perform type conversion.
*/
int main()
{
    // The first way - unsafe
    double d = 99.99;
    int x;

    x = d;                  // compiler warning, narrowing conversion, implicit cast
    x = (int)d;             // C cast supresses warning, excplicit cast


    // The second way - functional cast - unsafe
    double e = 99.99;
    int y;

    y = e;                  // compiler warning, narrowing conversion, implicit cast
    y = int(e);             // C++ cast supresses warning, excplicit cast

    int a = 123;
    double b = 99.99;
    int* pa = &a;           // pa points to a
    double* pb = &b;        // pb points to b

    /*
        2. The next line here - pa = (int*)a; - is using a C cast to convert our integer a
        into a pointer to an integer. This will make our pointer to an integer. This will make
        our pointer to an integer points the address 123. It is totally unsafe and should never
        be used.

        In a second example - pa = (int*)pb; - we have a pointer to a double which we casting
        into a pointer to an integer, which changing the type of a pointer. This does nothing
        to reformat the memory at the end of the pointer. It purely says: "The pointer to a
        double now a pointer to an integer". The disadvantage of this is that is the pointer to
        a double will point to 8 bytes of memory. A pointer to an integer will point to 4 bytes.
        Again, it is totally meaningless piece of code.
    */
    pa = (int*)a;           // convert a - 123 to a pointer to an int
    pa = (int*)pb;          // convert pb - pointer to a double to pointer to an int


    // The third way
    /*
        3. The third way of casting consists of 4 casting operators. These are:

            static_cast
            dynamic_cast
            reinterpret_cat
            const_cast

        static_cast is safer than C and C++ functional casting and it does time compile checks.

        dynamic_cast does a few time compile checks. It's primarily used in situations where
        you don't know the object type. This is usually when you use polymorphism and an inheritance
        hierarchy. Unlike static_cast, dynamic_cast does most of its' checking at runtime. If the cast
        does not make sence to a dynamic_cast operator at runtime, than a runtime error will result.

        reinterpret_cast is a special case. It does very little in checking at all. It is virtually
        equvivalent of C and C++ functional casting. It's inheritely unsafe and you should avoid
        it wherever posible. It only tends to be used for unsafe cast which are also used to be
        unportable. And in situations when you are dealing with low-level programming.
    */
    a = static_cast<int>(b);        // convert b - 99.99 to an int - OK
    pa = static_cast<int*>(pb);     // convert pb - pointer to a double to pointer to an int
                                    // ERROR!

    a = dynamic_cast<int>(b);       // convert b - 99.99 to an int - ERROR, must be a pointer
                                    // to a class or void pointer.
    pa = dynamic_cast<int*>(pb)     // convert pb - pointer to a double to pointer to an int
                                    // ERROR, must be a pointer to a class or void pointer


    /*
        4. To demonstate how const_cast works we create a class person and DioSomething
        function.

        Here we create a Person as a pointer and then call a function DoSomething with that
        pointer.
    */
    Person* pSomeone = new Person;
    DoSomething(pSomeone);






    return 0;
}
