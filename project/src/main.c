#include "utils.h"

#define ERR_ARGS_COUNT (-1)
#define ERR_WRONG_FLG (-2)

#define TST_FOO_FIX     1
#define TST_FOO_IMPL    2
#define TST_MOD_IMPL    3
#define TST_REC_IMPL    4

long int conversion_to_number(const char* str_num) {
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

int main(int argc, const char** argv) {
    if (argc < 3) {
        return ERR_ARGS_COUNT;
    }

    long int Test_case = conversion_to_number(argv[1]);
    const char* data;
    data = argv[2];

    switch (Test_case) {
        case TST_FOO_FIX: {
            long int to = conversion_to_number(data);
            printf("%zu\n", timer_from(to));
            break;
        }
        case TST_FOO_IMPL: {
            if (argc == 4) {
                int base = conversion_to_number(data);
                int pow =  conversion_to_number(argv[3]);
                int res = custom_pow(base, pow);

                printf("%i\n", res);
            } else {
                return ERR_ARGS_COUNT;
            }
            break;
        }
        case TST_MOD_IMPL: {
            long int num = conversion_to_number(data);
            printf("%d", number_is_simple(num));
            break;
        }
        case TST_REC_IMPL: {
            long int num = conversion_to_number(data);
            recursive_printing(num);
            break;
        }
        default: {
            return ERR_WRONG_FLG;
        }
    }
}
