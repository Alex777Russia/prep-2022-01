#include "utils.h"

size_t timer_from(long int from) {
    size_t counter = 0;
    for (long int i = from; i >= 0; --i) {
        ++counter;
        if (i > 0) {
            printf("%ld ", i);
        } else {
            printf("%ld\n", i);
        }
    }
    return counter;
}

/*
int custom_pow(int base, int power) {
    return 0;
}
*/
