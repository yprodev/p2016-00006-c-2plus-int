#include "CarChained.h"

/*
    1. If we call the default constructor rather than initialising all the data members
    withing the default constructor we simply call the next constructor in the chain
    and pass it the default of Red.
*/
CarChained::CarChained()
    : CarChained(chainedcolor::Red) {  }

/*
    2. That intern cause the next constructor in the chain passing it the Red that is passed in
    and a default of 2000 of the engine size and so on down the line.
*/
CarChained::CarChained(chainedcolor col)
    : CarChained(col, 2000) {  }

CarChained::CarChained(chainedcolor col, int engsize)
    : CarChained(col, engsize, 20000) {  }


/*
    3. Actual initialisation of the data members only takes place in the final constructor. This
    is a big change. The responsibility for actually doing the initialisation is delegated down
    the train so define the constructor.

    And no matter where you've entered the train, any parameters that you supply are automaticly
    passed on the chain along with any defaults to the next constructor in the chain.

    Potentially this make this short code more maintanable as an initialisation takes place
    only in one point. It looks more sensible and a little hard to follow.

    However, there other performance inplications. Instead of calling a single constructor as
    in the previous example (CarUnchained.h and CarUnchained.cpp) in this example you now
    can call one of 4 constructors in the chain. You may use this when you need quite a fast
    performance.
*/
CarChained::CarChained(chainedcolor col, int engsize, double cost)
    : primaryColor{ col }, engineSize{ engsize }, price{ cost }
{
    //primaryColor = col;
    //engineSize = engsize;
    //price = cost;
}
