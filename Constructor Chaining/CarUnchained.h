#pragma once
#pragma once

enum class unchainedcolor { Black, Red, Silver, White };

class CarUnchained
{
public:
    CarUnchained();
    CarUnchained(unchainedcolor col);
    CarUnchained(unchainedcolor col, int engsize);
    CarUnchained(unchainedcolor col, int engsize, double cost);
private:
    unchainedcolor primaryColor;
    int engineSize;
    double price;
};
