#include "CarFuncPtr.h"

CarFuncPtr::CarFuncPtr(string mak, string modl, string col)
    :make{ mak }, model{ modl }, color{ col }
{
}

string CarFuncPtr::GetMake() const
{
    return make;
}

string CarFuncPtr::GetModel() const
{
    return model;
}

string CarFuncPtr::GetColor() const
{
    return color;
}
