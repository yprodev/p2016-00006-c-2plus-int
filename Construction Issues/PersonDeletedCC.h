#pragma once
class PersonDeletedCC           // Person with deleted copy constructor
{
/*
    6. In previous projects we saw a keyword 'delete' which we could use to
    suppress the compiler generation of certain functions. For example, if we want
    to suppress the compiler generation of a default constructor, we could say
    '.. = delete' at the end of it (default constructor).

    In this case we supplied a copy constructor or at least a declaration of a copy
    constructor - but instead of actually coding it, we've said '.. = delete'.
    This will cause the compiler not to create this default copy constructor.


*/
public:
    PersonDeletedCC();                                      // default constructor
    PersonDeletedCC(char* name);                            // overloaded constructor
    PersonDeletedCC(const PersonDeletedCC& p) = delete;     // deleted copy constructor
    ~PersonDeletedCC();                                     // destructor
    char* GetName() const;                                  // query function
private:
    char* name;
};
