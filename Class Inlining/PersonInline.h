#pragma once
#include <string>

using namespace std;

class PersonInline
{
public:
    PersonInline();
    ~PersonInline();

    /*
        5a. Here we have used two different technics to inline functions. The first (the function
        void ImplicitInlineUsePerson().. ) function declared and coded within the class header
        file. When functions are coded within the header file in this way they are implicitly
        inline.
    */
    void ImplicitInlineUsePerson()
    {
        // Do Something
    }

    /*
        5b. The function (void inline ExplicitInlineUsePerson() .. ) is explicitely declared
        as inline using the inline modifier. It is also being coded within the header file.
    */
    void inline ExplicitInlineUsePerson()
    {
        // Do Something
    }

    /*
        5c. The function (the function ExcplicitInlineUsePersonAgain().. ) we have
        declared using inline modifier, but the function is coded in a .cpp file again
        using the inline modifier.
    */
    void inline ExcplicitInlineUsePersonAgain();
private:
    string name{ "Anonymous" };

};
