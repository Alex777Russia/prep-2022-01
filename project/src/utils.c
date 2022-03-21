#define ERR_INCORRECT_POW (-5)

#include "utils.h"

size_t timer_from(long int from) {
    long int counter = 0;

    if (from > 0) {
        for (long int i = from; i > 0; --i) {
            printf("%ld ", i);
            ++counter;
        }
        ++counter;
        printf("%d\n", 0);
    }

    return counter;
}


long int custom_pow(long int base, long int power, long int *result) {
    if (!power) {
        *result = 1;
        return 1;
    } else if (power < 0) {
        return ERR_INCORRECT_POW;
    }

    *result = 1;

    while (power) {
        if (power % 2 == 0) {
            power /= 2;
            base *= base;
        } else {
            --power;
            *result *= base;
        }
    }
    return 1;
}
