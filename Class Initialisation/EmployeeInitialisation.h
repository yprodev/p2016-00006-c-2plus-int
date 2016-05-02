#pragma once
#include <string>
using namespace std;

class Employee
{
public:     // function
    /*
        3. We could use a series of functions. This is illustrates completely the problem of
        using this method.

        Firstly, the user of our class needs to know what the function is called. Also, and more
        importantly, the user of our class should remember to call this function in order of
        initialization.

            void Initialize();                                  // The first one with the 'z'
            void Initialise();                                  // Overloaded
            void Initialise(string name, int empno, int ext);   // Overloaded

    */


    /*
        4. In real life when a child is born that child is given a name. That also gives them other
        attributes like health service numbers. That enables that child to go through life.

        OO tell that all the object must be initialized. So the speacial function that initialise an
        object calls constructor function.

        If you don't provide your own constructor, the compiler will provide one for you. It's
        effectively defined by the compiler as inline function without any parameters and which has
        no body. However the function will be there and it will be called.

        Constructors have a special format. They have the same name as a class. They take no
        parameters as a default constructor and return a thing not even avoid.

        Constructors can also be overloaded.
    */
    Employee();                                 // Default constructor
    Employee(string nam, int empno, int ext);   // Overloaded constructor
    void SetName(string nam);
    void SetEmpNo(int empno);
    void SetExtension(int ext);
    string GetName() const;
    int GetEmpNo() const;
    int GetExtension() const;

private:    // data
    /*
        2. On modern compilers we could use in-place initialisation. However this is fixed. If some
        time later we decide the default extension number rather than being 0, for example 1, 2, 3, 4
        we know to change that we have to go to our class definition, change the default initialisation,
        recompile, rebuild and redistribute the application to all of our clients.

        The second alternative is sligthly different.
    */
    string name;
    // string name { "Unknown" };
    int employeeNo;
    int extention;
    // int extention{ 0 };
};
