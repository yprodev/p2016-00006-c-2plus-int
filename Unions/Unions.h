#pragma once
#include <cstdint>


/*
    1. A union is very similar to a structure.
    Each data member of a structure will occupy some area of a memory. So the size of our
    structure Employee will be 4 bytes for an employee_number and 4 bytes for a float
    salary (REMEMBER: that could be platform depended).
*/
struct Employee {
    int employee_number;    // 4 bytes
    float salary;           // 4 bytes
};


/*
    2. In a union the members share the same area of memory. So, the size of any given union
    is a size of it's largest member.
*/
union Memory {
    int int_number;
    float float_number;
};


/*
    3. More valid use of a union.
*/
union Bitfields {

    unsigned char wholebyte;    // 8 bit character - 1 byte
    struct individualbits {
        unsigned bit0 : 1;
        unsigned bit1 : 1;
        unsigned bit2 : 1;
        unsigned bit3 : 1;
        unsigned bit4 : 1;
        unsigned bit5 : 1;
        unsigned bit6 : 1;
        unsigned bit7 : 1;
    }bits;

};






