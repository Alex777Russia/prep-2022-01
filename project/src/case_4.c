#include "utils.h"

void recursive_printing(long int number) {
    if (number != 1) {
        if (number > 1) {
            recursive_printing(number - 1);
            printf(" ");
        } else {
            recursive_printing(number + 1);
            printf(" ");
        }
    }
    printf("%ld", number);
}
