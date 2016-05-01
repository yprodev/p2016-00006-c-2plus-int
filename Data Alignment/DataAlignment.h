#pragma once


/*
    1. This structure is very big in size - nearly 49 bytes. If we try to access a field of
    this structure we will have to have 49 bytes in memory, because the size of the structure
    is the sum of its' fields' sizes.

    However if we let the compiler tell us the size of this structure in memory, the figure
    that we will get is - 72 bytes. In other words 23 bytes difference.

    So where these 23 bytes has gone?

    The compiler tries to make the structure as efficient as possible in terms of CPU usage.
    And variables are far more efficient if they are aligned on certain boundaries. For example,
    an integer is usually aligned on the 4 bytes boundary. A double is usually aligned on the
    8 byte boundary.

    If the members of our structure follow one another directly in memory this would not be the
    case. So, the compiler inserts padding.
*/
struct Employee1 // Readable structure
{
    char employeeReference[10];
    double salary;
    int departmentCode;
    bool companyPension;
    double performanceBonus;
    bool condactSatisfactory;
    int daysAnnualLeave;
    bool companyCar;
    double carExpenseAllowance;
    int phoneExtension;

};

/*
    2. According to the simulation here (structure Employee2) of what compiler
    might do pad this structure.

    The employeeReference is still 10 bytes. The double salary must go on the 8 byte boundary.
    The nearest 8 byte boundary is 16 byte. So, we see inserted padding of 6 bytes (10 + 6 = 16).

*/
struct Employee2 // Compiler inserts padding for alignment
{
    char employeeReference[10];
    char padding1[6];
    double salary;
    int departmentCode;
    bool companyPension;
    char padding2[3];
    double performanceBonus;
    bool condactSatisfactory;
    char padding3[3];
    int daysAnnualLeave;
    bool companyCar;
    char padding4[7];
    double carExpenseAllowance;
    int phoneExtension;
    char padding5[4];

};


/*
    3. So what can we do about this?

    If we group variables this way - largest variables first, followed by smaller, followed by
    smallest variables that will reduce the size of our structure considerably.

    In fact in this case the compiler would have to insert very little packing. The only packing it will
    have to insert is the variant of the structure the padding that will round the number of bytes.

    One disadvantage of this - this struct is less readable now.
*/
struct Employee3 // less readable by tighter packing
{

    double salary;
    double performanceBonus;
    double carExpenseAllowance;
    int departmentCode;
    int daysAnnualLeave;
    int phoneExtension;
    char employeeReference[10];
    bool companyPension;
    bool condactSatisfactory;
    bool companyCar;

};

/*
    4. Here we use a seriese of compiler directives, pre-process directives to control how
    the compiler packs this structure.

    #pragma pack (push) - stores the current packing onto the internal stack.
    #pragma pack(1) - modifies the default packing to 1 byte boundaries.
    #pragma pack (pop) - restores the value it was pushed on line where #pragma pack (push).

    In the body of this structure the packing would be won by a bound. Therefore salary would
    admittedly followed the employee reference.

    If we would to take the size of this structure, the size of this structure would be 49 bytes.

    Now this structure is readable, well packed but non-portable.
*/

#pragma pack (push)
#pragma pack(1)

struct Employee4    // Readable but packed (non-portable structure)
{
    char employeeReference[10];
    double salary;
    int departmentCode;
    bool companyPension;
    double performanceBonus;
    bool condactSatisfactory;
    int daysAnnualLeave;
    bool companyCar;
    double carExpenseAllowance;
    int phoneExtension;
};
#pragma pack (pop)


/*
    5. More recent compilers are allowed to specify the alignments of variables using the
    'alignas' keyword. Here we specify alignment 128. That does not affect the individual
    members of a structure.

    It simply means that Employee5 will be aligned on the 128 byte boundary. To affect individual
    members you have to declare each member with an alignas statement.
*/
struct alignas(128) Employee5    // Aligned structure
{
    char employeeReference[10];
    double salary;
    int departmentCode;
    bool companyPension;
    double performanceBonus;
    bool condactSatisfactory;
    int daysAnnualLeave;
    bool companyCar;
    double carExpenseAllowance;
    int phoneExtension;
};


/*
    6. The effect of using alignis is effectively this:
*/
struct Employee6    // effect of alignas(128)
{
    char employeeReference[10];
    double salary;
    int departmentCode;
    bool companyPension;
    double performanceBonus;
    bool condactSatisfactory;
    int daysAnnualLeave;
    bool companyCar;
    double carExpenseAllowance;
    int phoneExtension;
    char padding[56];
};









