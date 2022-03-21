#include "utils.h"
#include "recursive_printing.h"
#include "is_prime.h"

#include <stdlib.h>

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)
#define ERR_POINTER_VAL (-3)
#define ERR_CONVERSION (-4)
#define ERR_INCORRECT_POW (-5)

#define TST_FOO_FIX 1
#define TST_FOO_IMPL 2
#define TST_MOD_IMPL 3
#define TST_REC_IMPL 4


static long int convert_to_number(const char* str_num, long int* result) {
    if (str_num == NULL || result == NULL) {
        return ERR_POINTER_VAL;
    }

    char *end = NULL;
    *result = strtol(str_num, &end, 0);

    if (*end != '\0') {
        return ERR_CONVERSION;
    }

    return 0;
}


int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    long int test_case = 0;
    int convert_test_case = convert_to_number(argv[1], &test_case);
    if (convert_test_case == ERR_POINTER_VAL) {
        return ERR_POINTER_VAL;
    } else if (convert_test_case == ERR_CONVERSION) {
        return ERR_CONVERSION;
    }


    switch (test_case) {
        case TST_FOO_FIX: {
            long int to = 0;
            int convert_to_to = convert_to_number(argv[2], &to);
            if (convert_to_to == ERR_POINTER_VAL) {
                return ERR_POINTER_VAL;
            } else if (convert_to_to == ERR_CONVERSION) {
                return ERR_CONVERSION;
            }

            printf("%zu\n", timer_from(to));
            break;
        }

        case TST_FOO_IMPL: {
            if (argc == 4) {
                long int base = 0;
                int convert_to_base = convert_to_number(argv[2], &base);
                if (convert_to_base == ERR_POINTER_VAL) {
                    return ERR_POINTER_VAL;
                } else if (convert_to_base == ERR_CONVERSION) {
                    return ERR_CONVERSION;
                }

                long int pow = 0;
                int convert_to_pow = (convert_to_number(argv[3], &pow));
                if (convert_to_pow == ERR_POINTER_VAL) {
                    return ERR_POINTER_VAL;
                } else if (convert_to_pow == ERR_CONVERSION) {
                    return ERR_CONVERSION;
                }

                long int result = 0;
                if (custom_pow(base, pow, &result) == ERR_INCORRECT_POW) {
                    return ERR_INCORRECT_POW;
                }

                printf("%li\n", result);
            } else {
                return ERR_ARGS_COUNT;
            }
            break;
        }

        case TST_MOD_IMPL: {
            long int num = 0;
            int convert_to_num = convert_to_number(argv[2], &num);
            if (convert_to_num == ERR_POINTER_VAL) {
                return ERR_POINTER_VAL;
            } else if (convert_to_num == ERR_CONVERSION) {
                return ERR_CONVERSION;
            }

            printf("%d\n", is_prime(num));
            break;
        }

        case TST_REC_IMPL: {
            long int num = 0;
            int convert_to_num = convert_to_number(argv[2], &num);
            if (convert_to_num == ERR_POINTER_VAL) {
                return ERR_POINTER_VAL;
            } else if (convert_to_num == ERR_CONVERSION) {
                return ERR_CONVERSION;
            }

            recursive_printing(num);
            printf("\n");
            break;
        }

        default: {
            return ERR_WRONG_FLG;
        }
    }
}
