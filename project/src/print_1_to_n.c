#include "print_1_to_n.h"

#include <stdio.h>

void print_1_to_n(long int number) {
    if (number > 1) {
        print_1_to_n(number - 1);
        printf(" ");
    } else if (number < 1) {
        print_1_to_n(number + 1);
        printf(" ");
    }

    printf("%ld", number);
}
