struct Date {
    int dd;
    int mm;
    int ccyy;
};

bool isInvalid(Date* pDate)     // We are passing in a pointer to a Date structure
{
    const int monthdays[]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    bool valid;
    valid = (pDate->mm > 0) && (pDate->mm < 12) && (pDate->dd > 0) &&
            (pDate->dd <= monthdays[pDate->mm - 1]);
    pDate->dd = 10;
    pDate = new Date{ 1,1,2000 };
    return valid;
}

/*
    1. pDate is now pointer to the const Date.

    When pDate becomes a const, we can no longer modify members of the pDate structure:
        pDate->dd = 10; - like this.

    But we can modify the pointer itselft:
        pDate = new Date{ 1,1,2000 }; - like this.
    The pointer itself is not const.

*/
bool isInvalid(const Date* pDate)     // We are passing in a pointer to a Date structure
{
    const int monthdays[]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    bool valid;
    valid = (pDate->mm > 0) && (pDate->mm < 12) && (pDate->dd > 0) &&
            (pDate->dd <= monthdays[pDate->mm - 1]);
    pDate->dd = 10;
    pDate = new Date{ 1,1,2000 };
    return valid;
}

/*
    2. Now pDate is a const pointer to a const Date.
    The pointer itself - const pDate, and the structure it points to - const Date are both
    and no modifications allowed at all shown here:
        pDate->dd = 10;
        pDate = new Date{ 1,1,2000 };

*/
bool isInvalid(const Date* const pDate)     // We are passing in a pointer to a Date structure
{
    const int monthdays[]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
    bool valid;
    valid = (pDate->mm > 0) && (pDate->mm < 12) && (pDate->dd > 0) &&
            (pDate->dd <= monthdays[pDate->mm - 1]);
    pDate->dd = 10;
    pDate = new Date{ 1,1,2000 };
    return valid;
}










