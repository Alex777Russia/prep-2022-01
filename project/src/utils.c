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


long int custom_pow(long int base, long int power) {
    long int result = 1;

    while (power != 0) {
        result *= base;
        power -= 1;
    }

    return result;
}
