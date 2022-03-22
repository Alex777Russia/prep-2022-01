#include "utils.h"
#include "print_1_to_n.h"
#include "is_prime.h"

#include <stdlib.h>

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)
#define ERR_POINTER_VAL (-3)
#define ERR_BAD_CONVERSION (-4)

#define TST_FIRST_CASE 1
#define TST_SECOND_CASE 2
#define TST_THIRD_CASE 3
#define TST_FOURTH_CASE 4


static long int convert_to_number(const char* str_num, long int* result) {
    if (str_num == NULL || result == NULL) {
        return ERR_BAD_CONVERSION;  // Здесь должно быть ERR_POINTER_VAL
    }

    char *end = NULL;
    *result = strtol(str_num, &end, 0);

    if (*end != '\0') {
        return ERR_BAD_CONVERSION;
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


    switch (test_case) {
        case TST_FIRST_CASE: {
            long int to = 0;

            if (convert_to_number(argv[2], &to) != 0) {
                return ERR_BAD_CONVERSION;
            }

            printf("%zu\n", timer_from(to));
            break;
        }

        case TST_SECOND_CASE: {
            if (argc == 4) {
                long int base = 0;

                if (convert_to_number(argv[2], &base) != 0) {
                    return ERR_BAD_CONVERSION;
                }

                long int pow = 0;

                if (convert_to_number(argv[3], &pow) != 0) {
                    return ERR_BAD_CONVERSION;
                }

                printf("%li\n", custom_pow(base, pow));
            } else {
                return ERR_ARGS_COUNT;
            }
            break;
        }

        case TST_THIRD_CASE: {
            long int num = 0;

            if (convert_to_number(argv[2], &num) != 0) {
                return ERR_BAD_CONVERSION;
            }

            printf("%d\n", is_prime(num));
            break;
        }

        case TST_FOURTH_CASE: {
            long int num = 0;

            if (convert_to_number(argv[2], &num) != 0) {
                return ERR_BAD_CONVERSION;
            }

            print_1_to_n(num);
            printf("\n");
            break;
        }

        default: {
            return ERR_WRONG_FLG;
        }
    }
}
