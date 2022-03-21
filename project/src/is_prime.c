#include "is_prime.h"

int is_prime(long int number) {
    if (number < 2) {
        return 0;
    }
    for (long int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}
