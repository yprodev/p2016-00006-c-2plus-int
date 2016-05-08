#include <iostream>

using namespace std;

class Car
{
public:
    Car(string mk, string mdl, string regmark)
        :make{ mk }, model{ mdl }, regno{ regmark }
    {
        /*
            2. This is a pointer to a current object. Therefore which is a value to the
            address to the current object.
        */
        cout << "Constructing Car" << mk << " " << mdl << " " << regmark << " at address "
             << hex << this << endl;
    }

    /*
        3. We don't actually need a destructor for the object since the object contains
        no dynamic pointers.
    */
    /*
        5b. The destructor says to set the make, model and registration number back to empty.
        In other words it reinitialises the Car to empty. This effectivelly leaves a hole in
        out pool.
    */
    ~Car()
    {
        cout << "Deleting Car " << make << " " << model << " " << regno << " at address "
             << hex << this << endl;
        make = "";
        model = "";
        regno = "";
    }
private:
    string make;
    string model;
    string regno;

};

int main()
{
    /*
        1. The new operator is usually used to allocate a piece of memory from the free store
        on a heap. The piece of memory is allocated at the arbitrary address decided upon by
        the operating system and that address is returned to you as a result of using 'new'.

        Here we are going to look at a version of a 'new' operator, which allows you to specify
        a particular address to allocating objects. First of all we've created a class Car.
    */

    /*
        6. You should note that there is a placement new. However there is no real placement
        to delete. The only way we could actually delete Cars from our pool is to call a
        destructor, shown below:

            poolcar->~Car();

        So, how it works? You have a pool of memory, you allocate object within that pool. You
        have to keep track of the objects within that pool. To delete the object from that
        pool you don't call the 'delete' operator - you call the destructor.

        But why you might to use it?

        At first sight it looks like a lot of hard work. You've got to manage everything yourself
        within the pool. One adventage of using this methodology is that its memory safe. If you are
        using a compiler provided the 'new' operator just to create objects and delete them with
        destructors elsewhere, you can get memory allocation errors. Using this methodology the
        memory is allocated upfront, you know you've got enough memory, so you won't get any such
        errors. It's also much faster. Memory allocation of individual objects is fairly slow.
        Memory allocation in this way is simply formatting preexisting piece of memory to a Car
        and calling it's constructor. Another use of 'placement new' is in the area of memory map
        hardware, but this is beyond the scope in this case.

    */

    // allocate pool memory
    // Car* poolptr = new Car[10] is NOT correct, as it will simply create 10 cars.
    // since my Car has no default constructor defined the compiler will give an error.
    // We want not to create objects - we just want to allocate raw memory. 'new' operator
    // will create objects.
    Car* poolptr = (Car*)malloc(sizeof(Car) * 10);

    Car* poolcar;               // pointer to a Car used for temporary pointers

    /*
        4. Normally 'new' doesn't take any parameters - just say new Car. However, in this case
        we've passed it to a pointer as a parameter. The parameter is the address we wish to
        allocate the Car at.

        The first car we create will be allocated at the address of poolptr. In other words
        right to the start of our pool memory. The second Car we allocate at the address of
        pool pointer + 1.

    */
                                // add three cars to the pool
    new(poolptr) Car("Fiat", "Punto", "IT4L14N");               // create first car
    new(poolptr + 1) Car("BMW", "M6 Convertible", "G3RM4N");    // create second car following first
    new(poolptr + 2) Car("Renault", "Twizy", "FR3NCH");         // create third car following second

                                // locate second car
    poolcar = poolptr + 1;
    /*
        5a. The next line is a little bit strange and should never normally be used. However in
        this situation it's quite exceptable. We have called the destructor of a Car pointer
        two by poolcar. In other words, we've called the BMW's destructor.
    */
    // call it's destructor to "delete" it (initialises but doesn't delete memory)
    poolcar->~Car();

    // replace previously deleted Car
    new(poolptr + 1) Car("Dodge", "Viper", "4M3R1C4N");

    // Add another Car
    poolcar = new(poolptr + 3) Car("Rolls Royce", "Wraith", "BR1715H");

    // call destructor for all cars
    for (int i = 0; i < 4; ++x)
    {
        (poolptr + i)->~Car();
    }

    // free pool memory
    free(poolptr);





    return 0;
}
