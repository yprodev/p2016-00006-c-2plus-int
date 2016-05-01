void References()
{

    /*
        1. We have already seen passing parameters by value and how it works by coping
        the parameters. But what if the parameter being passed is a large structure or
        object?

        This data would still be copied. This has several drawbacks.

        Firstly the ... being copied would be placed on the stack. The stack is a finite
        resource and it's very easy to exhaust it. We could increase the size of a stack
        however it is not generaly good practise.

        Secondly, as the time taken to perform the copy in the first place there has to be
        a solution. As a general rule of thum it is OK to pass built-in primitive data types
        by value. This aparently small and trivial to copy and for the complex data type are
        not.

        The solution lies in references. References are similar to pointers.

        The reference does not use any memory as a seperate variable because it is just
        a reference. A pointer on the other hand is a variable that needs some memory.
    */
    int x;
    int& refx = x;      // Reference MUST be initialised by assignment on declaration
//  int& refx{ x }      // or using universal initialisation on declaration
                        // a reference can NOT be changed

    x = 10;
    refx = 10;          // refx - a reference to x is an alias to x

    int y;
    int* pint;          // pint is a pointer to an int - does not require initialisation
    pint = &x;          // pint can point to any int - x
    pitn = &y;          // or y

    y = 20;
    *pint = 20;         // pointers must be dereferenced for their value to be used
}
