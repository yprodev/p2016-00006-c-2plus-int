#include <iostream>

using namespace std;

int main()
{
    /*
        1. If we use struct date from the file structs.h we can create a new date. That
        declaration of a day is a structure called VEDaty. It uses universal
        initialization.
    */
    // It's not currently working properly
    // date VEDay{ 8,5,1945 };


    /*
        2. If I want to access any of the members of my VEDay date structure I can do it
        using the dot notation.
    */
    // It's not currently working properly
    // VEDay.dd = 10;
    // cout << VEDay.ccyy << endl;


    /*
        3. If we want to access our employee structure we can do it like this:
    */
    employee me;
    me.employee_number = 12346;


    /*
        4. To access date of birth we use two dots. dd is an integer data type in
        the date struct. And date struct is data type for dob in our employee
        struct.
    */
    me.dob.dd = 22;


    /*
        5a. The employee structure could be very large. In our example it is small, but in real
        life it could be huge. So, declaring it on stack is not a good practice, because the
        stack is a finite resource.
    */
    employee* pyou;
    pyou = new employee;

    /*
        5b. To declare the structure on a heap you use distance apps. And to use it we need to create
        some memory. When that is done we can use the members of pyou.

        Note, that this time we are not using a dot notation. We using arrow notation - pyou is a
        pointer to an employee. An in fact the arrow looks just like a pointer.
    */
    pyou->employee_number;


    /*
        5c. If I want to access the dob member of pyou we will use the next syntax. And because
        dob is not a pointer, we have to use dot notation.
    */
    pyou->dob.dd = 10;


    /*
        6b. So in our code to declare a date we have to say it in C.

            struct date today1;
    */



    /*
        6c. In C++ we can say only:
    */
    date today2;

    /*
        7f. Using workers structures
        There is no difference between these structures. Another draw of backoff of bit structures
        is you can NOT use the address of operator to get the address of any member of that
        structure. We can do this only with Me and you (worker and smallworker) but we can't with
        bit oriented structure him (tinyworker).
    */

    worker Me;
    Me.driver = true;

    smallworker you;
    you.ownscar = true;

    tinyworker him;
    him.startday = 10;























    return 0;
}
