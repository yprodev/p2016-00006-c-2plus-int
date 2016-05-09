#pragma once
#include <string>
using namespace std;


/*
    1. We've already seen how pointers to functions can meet more generic and smaller
    code. We use the same pointers' functions example we've used before to demonstrate
    lambda expressions.
*/
class CarLambda
{
public:
    CarLambda(string make, string model, string color);
    string GetMake() const;
    string GetModel() const;
    string GetColor() const;
private:
    string make;
    string model;
    string color;
};
