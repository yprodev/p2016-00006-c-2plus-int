#include <cstdint>
#include <iostream>

using namespace std;

int main()
{
    // integer data types
    short number1;              // 2 bytes
    unsigned short number2;     // 2 bytes
    int number3;                // 4 bytes
    unsigned int number4;       // 4 bytes
    long number5;               // 4 bytes
    unsigned long number6;      // 4 bytes
    long long number7;          // 8 bytes
    unsigned long long number8; // 8 bytes

    // floating point data types
    float fpnumber1;            // 4 bytes
    double fpnumber2;           // 8 bytes
    long double fpnumber3;      // 8 bytes

    // other data types
    char charvar;               // 1 byte
    bool boolvar;               // 1 byte
    wchar_t wcahrvar;           // 2 bytes

    // fixed size integer data types
    int8_t fixedint1;           // 1 byte fixed
    uint8_t fixedint2;          // 1 byte fixed
    int16_t fixedint3;          // 2 bytes fixed
    uint16_t fixedint4;         // 2 bytes fixed
    int32_t fixedint5;          // 4 bytes fixed
    uint32_t fixedint6;         // 4 bytes fixed
    int64_t fixedint7;          // 8 bytes fixed
    uint64_t fixedint8;         // 8 bytes fixed

    int_fast8_t fixedint9;      // at least 1 byte fastest
    uint_fast8_t fixedint10;    // at least 1 byte fastest
    int_fast16_t fixedint11;    // at least 2 bytes fastest
    uint_fast16_t fixedint12;   // at least 2 bytes fastest
    int_fast32_t fixedint13;    // at least 4 bytes fastest
    uint_fast32_t fixedint14;   // at least 4 bytes fastest
    int_fast64_t fixedint15;    // at least 8 bytes fastest
    uint_fast64_t fixedint16;   // at least 8 bytes fastest
    int_least8_t fixedint17;    // at least 1 byte
    uint_least8_t fixedint18;   // at least 1 byte
    int_least16_t fixedint19;   // at least 2 bytes
    uint_least16_t fixedint20;  // at least 2 bytes
    int_least32_t fixedint21;   // at least 4 bytes
    uint_least32_t fixedint22;  // at least 4 bytes
    int_least64_t fixedint23;   // at least 8 bytes
    uint_least64_t fixedint24;  // at least 8 bytes

    // other fixed size data types
    char16_t UTF16char;         // 2 bytes fixed
    char32_t UTF32char;         // 4 bytes fixed


    cout << "short is " << sizeof(short) << " bytes" << endl;
    cout << "unsigned short is " << sizeof(unsigned short) << " bytes" << endl;
    cout << "int is " << sizeof(int) << " bytes" << endl;
    cout << "unsigned int is " << sizeof(unsigned int) << " bytes" << endl;

    cout << "long is " << sizeof(long) << " bytes" << endl;
    cout << "unsigned long is " << sizeof(unsigned long) << " bytes" << endl;
    cout << "long long is " << sizeof(long long) << " bytes" << endl;
    cout << "unsigned long long is " << sizeof(unsigned long long) << " bytes" << endl;

    cout << "float is " << sizeof(float) << " bytes" << endl;
    cout << "double is " << sizeof(double) << " bytes" << endl;
    cout << "long double is " << sizeof(long double) << " bytes" << endl;

    cout << "char is " << sizeof(char) << " bytes" << endl;
    cout << "bool is " << sizeof(bool) << " bytes" << endl;
    cout << "wchar_t is " << sizeof(wchar_t) << " bytes" << endl;

    cout << "int8_t is " << sizeof(int8_t) << " bytes" << endl;
    cout << "uint8_t is " << sizeof(uint8_t) << " bytes" << endl;
    cout << "int16_t is " << sizeof(int16_t) << " bytes" << endl;
    cout << "uint16_t is " << sizeof(uint16_t) << " bytes" << endl;
    cout << "int32_t is " << sizeof(int32_t) << " bytes" << endl;
    cout << "uint32_t is " << sizeof(uint32_t) << " bytes" << endl;
    cout << "int64_t is " << sizeof(int64_t) << " bytes" << endl;
    cout << "uint64_t is " << sizeof(uint64_t) << " bytes" << endl;

    cout << "int_fast8_t is " << sizeof(int_fast8_t) << " bytes" << endl;
    cout << "uint_fast8_t is " << sizeof(uint_fast8_t) << " bytes" << endl;
    cout << "int_fast16_t is " << sizeof(int_fast16_t) << " bytes" << endl;
    cout << "uint_fast16_t is " << sizeof(uint_fast16_t) << " bytes" << endl;
    cout << "int_fast32_t is " << sizeof(int_fast32_t) << " bytes" << endl;
    cout << "uint_fast32_t is " << sizeof(uint_fast32_t) << " bytes" << endl;
    cout << "int_fast64_t is " << sizeof(int_fast64_t) << " bytes" << endl;
    cout << "uint_fast64_t is " << sizeof(uint_fast64_t) << " bytes" << endl;

    cout << "int_least8_t is " << sizeof(int_least8_t) << " bytes" << endl;
    cout << "uint_least8_t is " << sizeof(uint_least8_t) << " bytes" << endl;
    cout << "int_least16_t is " << sizeof(int_least16_t) << " bytes" << endl;
    cout << "uint_least16_t is " << sizeof(uint_least16_t) << " bytes" << endl;
    cout << "int_least32_t is " << sizeof(int_least32_t) << " bytes" << endl;
    cout << "uint_least32_t is " << sizeof(uint_least32_t) << " bytes" << endl;
    cout << "int_least64_t is " << sizeof(int_least64_t) << " bytes" << endl;
    cout << "uint_least64_t is " << sizeof(uint_least64_t) << " bytes" << endl;

    cout << "char16_t is " << sizeof(char16_t) << " bytes" << endl;
    cout << "char32_t is " << sizeof(char32_t) << " bytes" << endl;

    return 0;
}
