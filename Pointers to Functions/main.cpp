#include "CarFuncPtr.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<CarFuncPtr*> SelectBlueCars(vector<CarFuncPtr*> pool)
{   // function to select all blue cars with hard coded color
    vector<CarFuncPtr*> selected;
    for (unsigned int x = 0; x < pool.size(); ++x)
    {
        if(pool[x]->GetColor() == "Blue")
        {
            selected.push_back(pool[x]);
        }
    }
    return selected;
}

vector<CarFuncPtr*> SelectFords(vector<CarFuncPtr*> pool)
{   // function to select all Ford cars with hard coded make
    vector<CarFuncPtr*> selected;
    for (unsigned int x = 0; x < pool.size(); ++x)
    {
        if(pool[x]->GetMake() == "Ford")
        {
            selected.push_back(pool[x]);
        }
    }
    return selected;
}

//vector<CarFuncPtr*> SelectAny(vector<CarFuncPtr*> pool, string SelStmt)
//{   // This would be great, but we can't interpret a string as code
//    vector<CarFuncPtr*> selected;
//    for (unsigned int x = 0; x < pool.size(); ++x)
//    {
//        /*
//            2b. ..then simply test this code expecting it to be treated as a piece of code.
//            That approach will not work.
//        */
//        if (SelStmt)
//        {
//            selected.push_back(pool[x]);
//        }
//    }
//    return selected;
//}

/*
    3a. We can however rather than passing a string create a function that which ... containes
    the single line - GetColor() == "Blue", GetColor() == "Ford", etc. Then we could write a
    generic select function and we could pass it a pointer to one of those functions.
*/
bool SelBlue(CarFuncPtr* c)
{
    return (c->GetColor() == "Blue");
}

bool SelFord(CarFuncPtr* m)
{
    return (m->GetMake() == "Ford");
}

/*
    3b. A function like just anything else lives in memory each code. It has an address. So, if
    we can take the address of that function, pass that address into select function
    and then call that function to do our selection we can pass litaraly any function, which
    does a selection into this SelectAny.

    Making SelectAny - a totally generic function - this is exactly what we are doing here. Our
    function prototype our pointer to function (*anySelect) reads as:

        "This is a pointer (*anySelect) to a function which takes one parameter '(CarFuncPtr*)'
        and returns a bolean (bool)".

    We can therefore pass any function which matches that signature into that select function.
    And if we look at our two select functions they both take CarFuncPtr parameter and then
    both return boleans.

    My function pointer is called anySelect. We call anySelect pass it each individual Car
    returned from our pool.

*/
vector<CarFuncPtr*> SelectAny(vector<CarFuncPtr*> pool, bool(*anySelect)(CarFuncPtr*))
{
    vector<CarFuncPtr*> selected;
    for (unsigned int x = 0; x < pool.size(); ++x)
    {
        /*
            3c. It returns a boolean depending on which when we call it may return true / false
            depending on wheather the color is Blue or whether the make is Frod. This
            code will not change regardless on how many functions we use are passing to select.
        */
        if (anySelect(pool[x]))
        {
            selected.push_back(pool[x]);
        }
    }
    return selected;
}

int main()
{

    vector<CarFuncPtr*> carpool;    // vector of pointers to the car objects
    vector<CarFuncPtr*> selected;

    carpool.push_back(new CarFuncPtr("Ford", "Fiesta", "Blue"));
    carpool.push_back(new CarFuncPtr("Vauxhall", "Corsa", "Red"));
    carpool.push_back(new CarFuncPtr("Ford", "Fiesta", "Green"));
    carpool.push_back(new CarFuncPtr("Rolls Royce", "Phantom", "Silver"));
    carpool.push_back(new CarFuncPtr("Vauxhall", "Insignia", "Black"));
    carpool.push_back(new CarFuncPtr("Ford", "Focus", "Black"));
    carpool.push_back(new CarFuncPtr("Renault", "Clio", "Blue"));
    carpool.push_back(new CarFuncPtr("BMW", "Z4 Roadster", "Orange"));
    carpool.push_back(new CarFuncPtr("Ford", "Fiesta", "Yellow"));
    carpool.push_back(new CarFuncPtr("Vauxhall", "Corsa", "Black"));
    carpool.push_back(new CarFuncPtr("BMW", "4 Series Convertible", "White"));
    carpool.push_back(new CarFuncPtr("Ford", "Galaxy", "Green"));

    /*
        1. Now we want to do a couple of selections. We could do this by creating functions
        which iterate through our carpool vector, placing the selected items into a new vector
        - selected.
    */

    selected.clear();
    selected = SelectBlueCars(carpool);             // function to select all Blue cars
    cout << "Select blue cars using select function: " << endl;
    for (unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() << " "
             << selected[x]->GetColor() << endl;
    }

    selected.clear();
    selected = SelectFords(carpool);                  // function to select all Ford cars
    cout << endl << "Select Fords using select function: " << endl;
    for (unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() << " "
             << selected[x]->GetColor() << endl;
    }

    /*
        2a. We simply can not pass a string containing a piece of code, and ...
    */
    //SelectAny(carpool, "GetColor() == Blue");       // Can't interpret string as code!

    selected.clear();
    // Call a generic select function passing the select critiria as a pointer to a function
    // to perform the test.
    selected = SelectAny(carpool, SelBlue);
    cout << endl << "SelectAny blue cars using function pointer: " << endl;
    for (unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() << " "
             << selected[x]->GetColor() << endl;
    }

    selected.clear();
    // Call a generic select function passing the select critiria as a pointer to a function
    // to perform the test.
    selected = SelectAny(carpool, SelFord);
    cout << endl << "SelectAny Fords using function pointer: " << endl;
    for (unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() << " "
             << selected[x]->GetColor() << endl;
    }



    return 0;
}
