#include <string>
using namespace std;
class CarFuncPtr
{
public:
    CarFuncPtr(string make, string model, string color);
    string GetMake() const;
    string GetModel() const;
    string GetColor() const;
private:
    string make;
    string model;
    string color;
};
