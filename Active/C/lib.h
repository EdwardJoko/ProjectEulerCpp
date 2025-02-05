#ifndef LIB_H
#define LIB_H

#include <stdbool.h>
#include <string.h>
#include <math.h> // README! add " -lm" when compiling this file

// generate the maximum number of n digit. if digit is 3, then the maxNum is 999
unsigned long int max_num_generator(int digit) {
    unsigned long int max_num = 0;
    for (int i = 0; i < digit; i++) max_num += 9 * (unsigned long int)pow(10, i);
    return max_num;
}

// generate the minimum number of n digit. if digit is 3, then the maxNum is 100
unsigned long int min_num_generator(int digit) {
    unsigned long int min_num = (unsigned long int)pow(10, digit - 1);
    return min_num;
}

bool is_palindrome(unsigned long int num) {
    // convert the integer to string
    char str[256];
    sprintf(str, "%lu", num);

    // test if the string is palindrome
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        // the index that mirror i from the right side of the string
        int index = len - (i + 1);
        if (str[i] != str[index]) return false;
    }
    return true;
}

// to check if a number is a prime or not
bool is_prime(unsigned long int number) {
    if (number <= 1) return false;

    for (unsigned long int i = 2; (i * i) <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

// return an array with element from 0 to limit but replacing non-prime number
// with 0
void eratosthenes_sieve(unsigned long int limit, unsigned long int* arr) {
    if (limit <= 1) return ;

    // fill the array with element from 0 to limit
    for (unsigned long int i = 0; i <= limit; i++) arr[i] = i;
    // 1 is not prime
    arr[1] = 0;

    // the amount of non-zero numbers in array, or the amount of prime numbers
    unsigned long int nonZero = limit + 1; 
    // eliminate non-prime numbers from the array with Eratosthenes' sieve
    for (unsigned long int i = 0; i <= limit; i++) {
    // ^ we can do optimization by stopping the loop at i*i <= limit, but then
    // nonZero would have inaccurate value
        // skip already eliminated numbers
        if (arr[i] == 0) {
            nonZero -= 1;
            continue;
        }

        for (unsigned long int j = arr[i] * 2; j <= limit; j += arr[i])
            arr[j] = 0;
    }
}

#endif
