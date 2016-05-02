void Print();
void Print(int numberOfPages);
void Print(int numberOfPages, int numberOfCopies);

/*
    2. Function overloading and default parameters concepts can conflict with each other.
*/

// Can call Print:
//
// Print();         - OK!
// Print(10);       - Is this Print(int numberOfPages) or Print(int numberOfPages, int numberOfCopies)
// Print(15, 2);    - OK!

void Function1(int parameter1 = 0, int parameter2 = 1, int parameter3 = 2);

// Can call Function1:
//
// Function1(1, 2, 3);
// Function1(1, 2);
// Function1(1);
// Function1();
//


// This is invalid
// Function( , , 3);
// C++ has no concept of missing parameters!
