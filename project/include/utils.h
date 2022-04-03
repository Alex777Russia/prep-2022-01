#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <stdio.h>

typedef struct masterRecord {
    int Number;
    char Name[20];
    char Surname[20];
    char address[30];
    char TelephoneNumber[15];
    double indebtedness;
    double credit_limit;
    double cash_payments;
} Data;

void writeTransaction(FILE *file, Data *transfer);

void writeMaster(FILE *file, Data *Client);

void new_data_client(FILE *first_file, FILE *second_file, FILE *client_file,
                 Data *client_data, Data *transfer);

#endif  // PROJECT_INCLUDE_UTILS_H_
