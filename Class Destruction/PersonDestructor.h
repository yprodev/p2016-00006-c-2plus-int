#pragma once

class PersonDestructor
{
public:
    PersonDestructor();
    PersonDestructor(char* name);

    /*
        6a. Let's declare destructor in our class.

        Destructor just like the constructor has no return type. It's name has a tilda - '~'
        character in the beggining followed by the class name and an empty parameter list.

        Unlike constructors, destructors can not be overloaded.
    */

    ~PersonDestructor();

    void UsePerson();
private:
    char* name;
};
