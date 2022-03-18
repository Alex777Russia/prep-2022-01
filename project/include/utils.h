#include <stdio.h>
#include <stdlib.h>
#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_


size_t timer_from(long int from);

long int conversion_to_number(const char* str_num);

int custom_pow(int base, int power);

int number_is_simple(long int number);

void recursive_printing(long int number);

#endif      // PROJECT_INCLUDE_UTILS_H_
