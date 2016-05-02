/*
    1. Function overloading - is a practice of having several functions over the same name
    but with different numbers and ... types of arguments. In fact the rules for overloading
    state that a function can be overloaded provided the number and all types of arguments
    differ.

    Not a rule:
        1. returned type
        2. another name of an argument
        3. switched parameters names - if we have two parameters, switch their places

    The advantage of function overloading is actually that you avoid unnecessary renaming
    functions or functions that do the same.

    What about the class constructors a constructor has a fixed format name. There actually no way
    you can actually call a constructor1 or constructor2.

    Behind the scenes the overloading works by decorating the names of the functions. The compiler
    uses the methodology called name decoration or sometimes called name ... . When the compiler
    encountered motive functions with the same name, it would decorate the name of the function
    with the dicti... .... count that represent the function name, the class of the function is the
    member of (if it is), the name space the function belongs to if it is declared with the name
    space, the type of the function parameters, the calling convention for the function and the
    return type for a function (or this is not used for overloading system).

    Unfortunately, the C++ language does not define the standard name decoration scheme. The way
    in which decorators differs from compilers to compilers.

*/
void Print();
// bool Print();                        // invalid cannot overload on returned type
void Print(int numberOfPages);
// void Print(int numberOfCopies);      // invalid - same as void Print(int numberOfPages);
void Print(int numberOfPages, int numberOfCopies);
// void Print(int numberOfCopies, int numberOfPages);      // invalid - same as void Print(int numberOfPages, int numberOfCopies);
void Print(int numberOfPages, char stationery[10]);

