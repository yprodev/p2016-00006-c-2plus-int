#pragma once

enum class chainedcolor { Black, Red, Silver, White };

class CarChained
{
public:
    CarChained();
    CarChained(chainedcolor col);
    CarChained(chainedcolor col, int engsize);
    CarChained(chainedcolor col, int engsize, double cost);
private:
    chainedcolor primaryColor;
    int engineSize;
    double price;
};

