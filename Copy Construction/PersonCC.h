class PersonCC
{
public:
    PersonCC();                     // default constructor
    PersonCC(char* nam);            // overloaded constructor
    /*
        2. So initialy we know that that is a constructor or constructors must have
        the same name as a class. We know it takes parameters. We also know it can
        takes a parameters of an object. The object is if type class name - the same
        class. However we have still issues with this.

        At the moment

            PersonCC(PersonCC p);

        passed by value. By value causes copying.
        This is the copy constuctor. We don't want copying to take place as we call
        the copy constructor that can lead to other problems.

        How do we stop copying? We start reference:

            PersonCC(PersonCC& p);

        Finally, if we are taking a copy of an object in this case me2, we would not
        expect me2 to be changed by the process of copying. In this case it is clone2
        that will be modified, me2 must not be modified.

        How do we prevent modification? We pass a const reference:

            PersonCC(const PersonCC& p);

        That is a completely correct definition of a copy constructor. It has class
        name and passes the const parameter that is called 'p'.
    */
    PersonCC(const PersonCC& p);    // copy constructor
    char* GetName() const;          // query function
private:
    char* name;
};
