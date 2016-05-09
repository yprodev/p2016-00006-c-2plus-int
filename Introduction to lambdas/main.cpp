#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "CarLambda.h"


vector<CarLambda*> SelectAny(vector<CarLambda*> pool, bool(*anySelect)(CarLambda*))
{
    vector<CarLambda*> selected;
    for (unsigned int x = 0; x < pool.size(); ++x)
    {
        if (anySelect(pool[x]))
        {
            selected.push_back(pool[x]);
        }
    }
    return selected;
}

bool SelBlue(CarLambda* c)
{
    return (c->GetColor() == "Blue");
}

bool SelFord(CarLambda* m)
{
    return (m->GetColor() == "Ford");
}


int main()
{

    vector<CarLambda*> carpool;    // vector of pointers to the car objects
    vector<CarLambda*> selected;

    carpool.push_back(new CarLambda("Ford", "Fiesta", "Blue"));
    carpool.push_back(new CarLambda("Vauxhall", "Corsa", "Red"));
    carpool.push_back(new CarLambda("Ford", "Fiesta", "Green"));
    carpool.push_back(new CarLambda("Rolls Royce", "Phantom", "Silver"));
    carpool.push_back(new CarLambda("Vauxhall", "Insignia", "Black"));
    carpool.push_back(new CarLambda("Ford", "Focus", "Black"));
    carpool.push_back(new CarLambda("Renault", "Clio", "Blue"));
    carpool.push_back(new CarLambda("BMW", "Z4 Roadster", "Orange"));
    carpool.push_back(new CarLambda("Ford", "Fiesta", "Yellow"));
    carpool.push_back(new CarLambda("Vauxhall", "Corsa", "Black"));
    carpool.push_back(new CarLambda("BMW", "4 Series Convertible", "White"));
    carpool.push_back(new CarLambda("Ford", "Galaxy", "Green"));


    selected.clear();
    selected = SelectAny(carpool, SelBlue);
    cout << endl << "SelectAny blue cars using function pointer:" << endl;
    for (unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() << " " <<
             selected[x]->GetColor() << endl;
    }


    selected.clear();
    selected = SelectAny(carpool, SelFord);
    cout << endl << "SelectAny fords using function pointer:" << endl;
    for (unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() << " " <<
             selected[x]->GetColor() << endl;
    }

    /*
        2. Now we look at LAMBDAS looks very similar to the code for pointers to
        functions.

        Rather than calling a function as a second parameter we called .. .. instead
        pass it a lambda expression. A SelectAny function does not change anyway
        what so ever. This suggests that the lambda is actually behind the scenes
        a pointer to a function.

        In particular we have the next expression:

            [](CarLambda* c) { return c->GetColor() == "Blue"; }

        This looks like a function anyway, because it has a body and a parameter.
        However unlike our function it has no return type (return type is placed before
        the name of a function). In this expression square brackets at the start indicate
        that this is a lambda expression. The compiler can deduce return type of the
        lambda expression by looking at it and evaluating it.

        Because we are returning the result of a comparison the compiler can deduce that
        we are returning a boolean. Therefore we don't need to put the keyword 'bool'
        anyway in this lambda expression.

        When we call SelectAny this lambda expression actually get to convert it into a
        pointer to a function. It's an anonymous function rather than a name function
        in a previous examples.
    */
    selected.clear();
    selected = SelectAny(carpool, [](CarLambda* c) { return c->GetColor() == "Blue"; });
    cout << endl << "SelectAny blue cars using Lambda:" << endl;
    for (unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() << " " <<
             selected[x]->GetColor() << endl;
    }

    selected.clear();
    selected = SelectAny(carpool, [](CarLambda* m) { return m->GetMake() == "Ford"; });
    cout << endl << "SelectAny Fords using Lambda:" << endl;
    for (unsigned int x = 0; x < selected.size(); ++x)
    {
        cout << selected[x]->GetMake() << " " << selected[x]->GetModel() << " " <<
             selected[x]->GetColor() << endl;
    }


    /*
        3. This time rather than calling SelectAny we've used an algorithm in a standard
        namespace called for_each. This algorithm take us a container in this case our
        carpool. We are passing it a begin and end interator to our container, telling
        for_each algorithm where to start and finish. And than we pass it a lambda:

            [](CarLambda* c)
            {
                if (c->GetColor == "Blue")
                {
                    cout << c->GetMake() << " " << c->GetModel() << " " << c->GetColor() << endl;
                }
            }

        This lambda expression is not quite the same as the last lambda expression. The
        last lambda expression returned boolean. In this case we are doing away with
        our selected vector completely and instead cout'ing all the members of the pool
        that match the criteria.

        This is a very basic introduction to lambdas. Lambdas themselves can take a lots
        more useful features. However it is quite advanced feature.

    */
    cout << endl << "Select blue cars using Lambda and for_each:" << endl;
    for_each(carpool.begin(), carpool.end(), [](CarLambda* c)
    {
        if (c->GetColor() == "Blue")
        {
            cout << c->GetMake() << " " << c->GetModel() << " " << c->GetColor() << endl;
        }
    }); // BE CAREFUL HERE!

    cout << endl << "Select Ford cars using Lambda and for_each:" << endl;
    for_each(carpool.begin(), carpool.end(), [](CarLambda* c)
    {
        if (c->GetMake() == "Ford")
        {
            cout << c->GetMake() << " " << c->GetModel() << " " << c->GetColor() << endl;
        }
    });










    return 0;
}
