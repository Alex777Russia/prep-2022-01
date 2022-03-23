#include "is_prime.h"

bool is_prime(long int number) {
    if (number < 2) {
        return false;
    }

    for (long int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
