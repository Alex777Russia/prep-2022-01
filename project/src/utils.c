#include "utils.h"

#include <stdio.h>

size_t timer_from(long int from) {
    if (from <= 0) {
        return 0;
    }

    for (long int i = from; i > 0; --i) {
        printf("%ld ", i);
    }

    printf("%d\n", 0);
    return from + 1;
}


long int custom_pow(long int base, unsigned long int power) {
    if (power == 0) {
        return 1;
    }
    if (base == 0) {
        return 0;
    }

    long int result = 1;

    while (power != 0) {
        if (power % 2 == 0) {
            power /= 2;
            base *= base;
        } else {
            --power;
            result *= base;
        }
    }
    return result;
}
