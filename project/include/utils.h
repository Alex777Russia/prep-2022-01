#ifndef PROJECT_INCLUDE_UTILS_H
#define PROJECT_INCLUDE_UTILS_H

#include <stdio.h>

void transactionWrite(FILE *ofPtr, Data transfer);

void masterWrite(FILE *ofPTR, Data Client);

void blackRecord(FILE *ofPTR, FILE *ofPTR_2, FILE *blackrecord, Data client_data, Data transfer);

#endif  // PROJECT_INCLUDE_UTILS_H
