#include "PersonConversion.h"

PersonConversion::PersonConversion(char* nam, int a, char sx)
    :name{ nam }, age{ a }, sex{ sx } {  }

PersonConversion::PersonConversion(const EmployeeConversion& e)
{
    // name = e.name;      // won't work because Person does not have to a private data
    // members of Employee. Could use friend classes, but this is frowned upon & breaks
    // encapsulation.

    /*
        4. REMARK: Friend classes are allowed direct access to private data members of classes
        where friendship is being established. However, this totaly breaks the encapsulation
        rules of OO.
    */


    name = e.GetName();
    age = e.GetAge();
    switch (e.GetSex()) {
        case gender::Male:
        {
            sex = 'M';
            break;
        }
        case gender::Female:
        {
            sex = 'F';
            break;
        }
        default:
        {
            sex = '?';
            break;
        }
    }
}
