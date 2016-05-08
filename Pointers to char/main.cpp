#include <iostream>
#include <string>
using namespace std;
#include <string.h>

int main()
{

    char* mystring = new char[255];     // allocate 255 bytes for the string
    strcpy_s(mystring, 255, "Simon");   // copy "Simon\0" into mystring

                                        // the size of the memory at the mystring pointer
                                        // is 255 bytes, the size of the string is 5 bytes
                                        // + the null terminator.

    cout << mystring << endl;           // outputs up to null terminator

    char* tenchars = new char[10];
    char* sixchars = new char[6];
    char* bigchars = new char[255];

    /*
        1. More modern standards have introduced newer versions of the existing older routines.
        In our example the first routine is generally the older copy of the routine and the
        second example is a newer version of the routine.

        However you should note, that the newer versions of the routines are implemented in a
        part of the standards which is optional. These routines are specified in a NXK standards
        and NXK is totaly optional ... as compiler writers whether they ectually implement the
        routines.

        Microsoft ... and also other compiler writers may not. So the versiouns of the routines
        we are seeing here are the Microsoft versions of the enhanced routines. The _s at the
        end of the newer routines stands for 'safe' or 'secure'. And this generally referes to
        the fact that they taken an additional parameter over the existing routine, which is the
        length of the distination buffer. Any attempt to exceed the destination buffer in a newer
        routines we generate some sort of error.
    */
    // copy / concatenate strings
    strcpy(sixchars, "Simon");          // exactly fills six chars
    strcpy(sixchars, 6, "Simon");       // exactly fills siz chars

    strcpy(tenchars, "Simon");          // fills tenchars with 4 spare
    strcpy(tenchars, 6, "Simon");       // fills tenchars with 4 spare
                                        // now concatenate another 6 chars onto the end of
                                        // "Simon\0"
    strcat(tenchars, sixchars);         // no error, but overwriting memory over 1 char - the result is undefined
    strcat_s(tenchars, 10, sixchars)    // ERROR!


    // copy / concatenate n chars from one string to another
    strncpy(bigchars, sixchars, 3);             // copy 3 chars from sixchars to bigchars
    strncpy_s(bigchars, 255, sixchars, 3);      // copy 3 chars from sixchars to bigchars safely
                                                // concatenate n chars from one string to another
    strncat(bigchars, sixchars, 3);             // concatenate 3 chars
    strncat_s(bigchars, 255, sixchars, 3);      // concatenate 3 chars safely
                                                // string comparison
    int x = strcmp(sixchars, tenchars);         // compare whole string
    int y = strcasecmp(sixchars, tenchars, 3);  // compare its 3 chars of strings only
                                                // result comparison
                                                // -1       sixchars < tenchars
                                                // 0        sixchars == tenchars
                                                // 1        sixchars > tenchars

    //  get number of chars in a string - not including the null terminator
    int z = strlen(bigchars);                   // returns the length not including the null terminator

    /*
        2. std::string is a more modern string. Shortly speaking they are not completely
        compatible. However, the char* is the basis of the std::string behind the scenes.
        And in order to allow compatability the two types char* and std::string there is a data
        member of a std::string which returns the string stored within it in char* format.

        This is allowes us to use a std::string in out case a name with the existing string
        handling routines from the C library. Microsoft have chosen to deprecate or to implement
        the older versions of the routines.

        In order to use string handling routines you have to #include <string.h> header file.
        Because they ... can see they also working in C++. However, if performance and
        portability and compatability isn't an issue - you should use std::string data type
        insread of char* has it has all the functions built into it and in fact more. It also
        has an addit benefit being totally safe.
    */
    // std::string compatibility
    string name = "Simon";
    strcpy(bigchars, name.data());              // std:: string.data() returns const char*
    strcpy_s(bigchars, 255, name.data());       // std:: string.data() returns const char*
























    return 0;
}
