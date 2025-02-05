// Project Euler
// Problem 12: The first triangle number to have over five hundred divisors

#include <stdbool.h>
#include <stdio.h>

unsigned int divisors_counter(unsigned int num) {
    unsigned int factors = 0;
    for (unsigned int i = 1; i * i <= num; i++) {
        bool is_zero_remainder = num % i == 0;
        if (is_zero_remainder && (num / i) != i) factors += 2;
        else if (is_zero_remainder) factors += 1;
    }
    return factors;
}

unsigned int compute012(int divisors_limit) {
    unsigned int divisors = 0;
    unsigned int i = 1;
    unsigned int triangle_number = 0;

    while (divisors <= divisors_limit) {
        triangle_number += i;
        divisors = divisors_counter(triangle_number);
        i += 1;
    }
    return triangle_number;
}
