#include "utils.h"
#include "recursive_printing.h"
#include "is_number_prime.h"

#include <stdlib.h>

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-0)

#define TST_FOO_FIX 1
#define TST_FOO_IMPL 2
#define TST_MOD_IMPL 3
#define TST_REC_IMPL 4


static long int convert_to_number(const char* str_num);


int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    long int Test_case = convert_to_number(argv[1]);

    switch (Test_case) {
        case TST_FOO_FIX: {
            long int to = convert_to_number(argv[2]);
            printf("%zu\n", timer_from(to));
            break;
        }

        case TST_FOO_IMPL: {
            if (argc == 4) {
                long base = convert_to_number(argv[2]);
                long pow =  convert_to_number(argv[3]);
                long res = custom_pow(base, pow);

                printf("%li\n", res);
            } else {
                return ERR_ARGS_COUNT;
            }
            break;
        }

        case TST_MOD_IMPL: {
            long int num = convert_to_number(argv[2]);
            printf("%d\n", is_number_prime(num));
            break;
        }

        case TST_REC_IMPL: {
            long int num = convert_to_number(argv[2]);
            recursive_printing(num);
            printf("\n");
            break;
        }

        default: {
            return ERR_WRONG_FLG;
        }
    }
}


static long int convert_to_number(const char* str_num) {
    if (str_num == NULL) {
        return ERR_WRONG_FLG;
    }
    if (*str_num == '\0') {
        return ERR_WRONG_FLG;
    }

    char* end = NULL;
    long int result = strtol(str_num, &end, 0);
    if (*end != '\0') {
        return ERR_WRONG_FLG;
    }
    return result;
}
