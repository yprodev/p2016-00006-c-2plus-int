#include "CarUnchained.h"

CarUnchained::CarUnchained()
    // Here we initialize data members of the class - variables in the private section, not parameters
    :primaryColor{ unchainedcolor::Red }, engineSize{ 20000 }, price{ 20000 }
{
    //primaryColor = Red;
    //engineSize = 2000;
    //price = 20000;
}

CarUnchained::CarUnchained(unchainedcolor col)
    :primaryColor{ col }, engineSize{ 20000 }, price{ 20000 }
{
    //primaryColor = col;
    //engineSize = 2000;
    //price = 20000;
}

CarUnchained::CarUnchained(unchainedcolor col, int engsize)
    :primaryColor{ col }, engineSize{ engsize }, price{ 20000 }
{
    //primaryColor = col;
    //engineSize = engsize;
    //price = 20000;
}

CarUnchained::CarUnchained(unchainedcolor col, int engsize, double cost)
    :primaryColor{ col }, engineSize{ engsize }, price{ cost }
{
    //primaryColor = col;
    //engineSize = engsize;
    //price = cost;
}
