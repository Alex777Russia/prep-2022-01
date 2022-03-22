#include "utils.h"

void print_1_to_n(long int number) {
    if (number == 1) {
    } else if (number > 1) {
        print_1_to_n(number - 1);
        printf(" ");
    } else {
        print_1_to_n(number + 1);
        printf(" ");
    }

    printf("%ld", number);
}
