#include "CarLambda.h"

CarLambda::CarLambda(string mak, string modl, string col)
    : make{ mak }, model{ modl }, color{ col }
{

}

string CarLambda::GetMake() const
{
    return make;
}

string CarLambda::GetModel() const
{
    return model;
}

string CarLambda::GetColor() const
{
    return color;
}
