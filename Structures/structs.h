/*
    6a. Also note that structures could be created using 'typedef' keyword. The two variants of
    this syntax is OK. By why we need the this type of syntax using the keyword 'typedef'?

        typedef struct{
            int dd;
            int mm;
            int ccyy;
        }date;

    It is all about compatability of structures in C and C++. In C to create a structure
    you must use keyword 'struct'. To declare a variable of type that structure you must also
    again use keyword 'struct'.

    6d. The 'typedef' on this structure simply means that we do NOT have to use the keyword
    'struct' to declare a variable of type date in C. And purely that is for compatability
    and is only nesesseraly if you intense use your structures cross-laguage between C and C++.
*/
struct date{
    int dd;
    int mm;
    int ccyy;
};

struct employee {
    int employee_number;
    date dob;
    date start_date;
};

/*
    7a. This struct is named worker. It has 5 integers and 4 booleans. But about the size of a
    structure? The size of a structure is the sum of the sizes of all its' elements. For now it
    just says that it has 5 integers (5 * 4 = 20 bytes) and 4 boleans (4 * 1 = 4 bytes). 20 + 4 =
    = 24 bytes - the size in memory of this sturcture on this platform (REMEMBER: the size of
    a variable is platform depended, so that's why you should use fixed data types).
*/
struct worker {
    int startdate;
    int startmonth;
    int startyear;
    int numberOfDependants;
    int numberOfYearsDriving;
    bool married;
    bool driver;
    bool ownscar;
    bool wearsGlasses;
};


/*
    7b. We can make it a lot smaller very easiely. An int can store values in range +/-2000000000.
    The days of the month is in the range from 1 to the 31. So we can do it a lot smaller changing
    the structure to the next. Char can store values in the range 0 to the 255.

    The years is a little larger. We have specified 4-digit year. It does not fit to the char, but
    it will fit to the short. The size is (4 * 1) + (2 * 1) + (4 * 1) = 10 bytes in memory. So
    more than half memory allocation for the structure.
*/


/*
    7d. Our smallworker structure using small data types. Smallworker on some platforms
    may suffer the performance overhead because char data type is not as efficient as
    int data type.
*/
struct smallworker {
    char startdate;
    char startmonth;
    short startyear;
    char numberOfDependants;
    char numberOfYearsDriving;
    bool married;
    bool driver;
    bool ownscar;
    bool wearsGlasses;
};


/*
    7c. But we could go further. The 'tinyworker' structure uses the feature called
    'bits structures' where within the structure we could actually specify how many bits
    each individual field takes. So startday, for example, is 5 bits. 5 bits can store numbers
    in a range 0 to 32.

    The month is in the range of 1 to 12. We use 4 bits to store values in the range of 0 to 15.

    So we can minimize all our fields to the minimum size to store the data. There no data type
    associated with bit for you that all simply unsigned. And in fact you can only use integer
    type data in a bit structure.

    The 4 flags of the bottom of the structure (married, driver, ownscar, wearsGlasses) are all
    a single bit because store true or false value and can be represented by one bit.

    The size of this structure is: 5 + 4 + 11 + 5 + 7 + 1*4 = 36 BITS (not bytes). Nearly
    5 bytes. A bit structure must be a multiple of a bits. Our is not a the moment. The compiler
    will automaticly outpad it to make it multiple. So the size will become 40 bits = 5 bytes.

    However there is a cost of doing this.
*/

/*
    7e. Similarly with our tinyworker it is very inefficient to access individual bits or bytes.
    In this case the compiler has to create additional code to address bits. So the tinyworker
    is substantially LESS EFFICIENT than our smallworker.
*/
struct tinyworker {
    unsigned startday :5;
    unsigned startmonth :4;
    unsigned startyear :11;
    unsigned numberOfDependants :5;
    unsigned numberOfYearDriving :7;
    unsigned married :1;
    unsigned driver :1;
    unsigned ownscar :1;
    unsigned wearsGlasses :1;
};








