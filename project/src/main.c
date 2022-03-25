#include "is_prime.h"
#include "print_1_to_n.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)
#define ERR_POINTER_VAL (-3)
#define ERR_BAD_CONVERSION (-4)
#define ERR_EMPTY_ARGUMENTS (-5)

#define TST_TIMER_FROM_CASE 1
#define TST_CUSTOM_POW_CASE 2
#define TST_IS_PRIME_CASE 3
#define TST_PRINT_1_TO_N_CASE 4


static long int convert_to_number(const char* str_num, long int* result) {
    if (str_num == NULL || result == NULL) {
        return ERR_EMPTY_ARGUMENTS;
    }

    char *end = NULL;
    *result = strtol(str_num, &end, 0);

    if (*end != '\0') {
        return ERR_POINTER_VAL;
    }

    return 0;
}


int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    long int test_case = 0;
    if (convert_to_number(argv[1], &test_case) != 0) {
        return ERR_BAD_CONVERSION;
    }

    long int first_argument_for_case = 0;
    if (convert_to_number(argv[2], &first_argument_for_case) != 0) {
        return ERR_BAD_CONVERSION;
    }

    switch (test_case) {
        case TST_TIMER_FROM_CASE: {
            printf("%zu\n", timer_from(first_argument_for_case));
            break;
        }

        case TST_CUSTOM_POW_CASE: {
            if (argc != 4) {
                return ERR_ARGS_COUNT;
            }

            long int base = first_argument_for_case;
            long int pow = 0;

            if (convert_to_number(argv[3], &pow) != 0) {
                return ERR_BAD_CONVERSION;
            }

            printf("%li\n", custom_pow(base, pow));
            break;
        }

        case TST_IS_PRIME_CASE: {
            printf("%d\n", is_prime(first_argument_for_case));
            break;
        }

        case TST_PRINT_1_TO_N_CASE: {
            print_1_to_n(first_argument_for_case);
            printf("\n");
            break;
        }

        default: {
            return ERR_WRONG_FLG;
        }
    }
}
