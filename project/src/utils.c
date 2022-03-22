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

    return counter;  // Исправить. Последнее действие - перевёл тип функции из int в bool.
}


long int custom_pow(long int base, unsigned long int power) {
    if (!power) {
        return 1;
    }

    long int result = 1;

    while (power) {
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
