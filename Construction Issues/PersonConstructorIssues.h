#pragma once

/*
    1. The most important thing here is that we have in private section a data member
    in this class and it is a pointer. We also need to know that this pointer is dynamicly
    allocated withing the class.

*/
class PersonConstructionIssues
{
public:
    PersonConstructionIssues();                 // default constructor
    PersonConstructionIssues(char* name);       // overloaded constructor
    ~PersonConstructionIssues();                // destructor
    char* GetName() const;                      // query function
private:
    char* name;
};
