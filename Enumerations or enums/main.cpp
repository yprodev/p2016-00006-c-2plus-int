#include <iostream>

using namespace std;

/*
    3. enum in this situation declares 7 numeric constants.
    There no values this constants displayed. But compiler will assign
    the value of '0' to the first element of this enum (Sunday = 0).
*/
enum Weekdays {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
// In this case Error value will be previous element + 1
enum status {OK = 0, Warning = 5, Error, Fatal = 999};


/*
    6. Let's add a few more enums.
*/
//enum color {Red, Yellow, Blue, Green};
//enum mood {Happy, Green, Excited, indifferent};


/*
    8a. To solve the problem from the previous step we need to include 'class'
    keyword to the each enum we need.
*/
enum class color {Red, Yellow, Blue, Green};
enum class mood {Happy, Green, Excited, indifferent};

int main()
{
    /*
        1. How to resolve the next problem?

        We have:
            int today = 3;

        Variable 'today' could be any day of the week Thursday or Wednesday.
        The other problem is in different countries we could start counting
        days from Sunday or Monday.

        So, to avoid ambiguity in this situation we will use constants.
    */

    // const int Sunday = 0;
    // const int Monday = 1;

    int today = Monday;

    /*
        5. Enum based on an integer data type.
        So, when we assigning a value from the enum Weekdays to our variable
        'today' it is converting into integer data type, because enum is based
        on an integer data type. But if we create variable with name of declared
        enum used like our data type and will assign to it an integer, we will
        get an error:

        Weekdays tomorrow;
        tomorrow = 4;
    */

    Weekdays tomorrow;
    tomorrow = Tuesday;

    /*
        2. But another way is we could declare enum.
    */


    /*
        4. So, if we comment out our constant variables at the step number 1,
        there will be no any error with variable 'today', because of our
        enum Weekdays.
    */


    /*
        7. Creating variables using enums from the previous step.
        And when we try to compile this code, we will get an error because we
        declared Green in two enums at one time. enums and enums' members are
        global in scope.
    */
    //color myFavourite = Red;
    //mood howIFeel = Green;


    /*
        8b. To solve this problem with variables we need to
        Now we have to say which enum particular member comes from. And we do this
        with '::' scope resolution operator.
    */

    // At this time it is NOT working properly with compiler I'm using now
    color myFavourite = color::Red;
    mood howIFeel = mood::Green;

    /*
        9. The next thing is not allowed:
            color royal = mood::Green;
    */


    return 0;
}
