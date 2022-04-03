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

void transactionWrite(FILE *ofPtr, Data *transfer);

void masterWrite(FILE *ofPTR, Data *Client);

void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data *client_data, Data *transfer);

#endif  // PROJECT_INCLUDE_UTILS_H_
