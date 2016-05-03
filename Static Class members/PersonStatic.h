#pragma once

class PersonStatic
{
public:
    PersonStatic();
    ~PersonStatic();
    // other class member function here
    static int GetNumPeople();      // Static Function can ONLY access static data within the class
private:
    // class member data here
    static int numpeople;
};
