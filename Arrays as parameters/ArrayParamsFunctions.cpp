/*
    2. The first two functions are not practical, because we will have to override
    the function depending on the size of an array we are using at the moment.

int Sum(int nums[5]) {      // Sum function with sized array[5]
    int total = 0;
    for (int x = 0; x < 5; ++x) {
        total += nums[x];
    }
    return total;
}

int Sum(int nums[10]) {      // Sum function with sized array[10]
    int total = 0;           // This is not allowed as you can not overload on array size
    for (int x = 0; x < 10; ++x) {
        total += nums[x];
    }
    return total;
}
*/


/*
    3. We don't know what is the size of our array is? And how we can set a correct number
    of iterations?

int Sum(int nums[]) {      // Sum function with unsized sized array
    int total = 0;
    for (int x = 0; x < ?; ++x) {       // How many iterations?
        total += nums[x];
    }
    return total;
}
*/


int Sum(int nums[], int size) {      // Sum function with unsized array & size parameter
    int total = 0;
    for (int x = 0; x < size; ++x) {
        total += nums[x];
    }
    return total;
}

int Sum(int nums[], int begin, int end) {      // Sum function with unsized array & begin / end parameters
    int total = 0;
    for (int x = begin; x <= end; ++x) {
        total += nums[x];
    }
    return total;
}













