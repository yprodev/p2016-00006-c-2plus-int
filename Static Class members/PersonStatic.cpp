#include "PersonStatic.h"

int PersonStatic::numpeople;    // static variable

PersonStatic::PersonStatic()
{
    ++numpeople;
}

PersonStatic::~PersonStatic()
{
    --numpeople;
}

int PersonStatic::GetNumPeople()
{
    return numpeople;
}
