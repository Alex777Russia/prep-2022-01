#include "client.h"
#include "utils.h"
#include "read_and_print_data.h"
#include "test_print_to_file.h"

#include <string.h>

enum ERROR_RETURN {
    NULL_PTR_IN_ARGUMENTS_ON_FUNCTION = -1,
    ERR_READ_DATA = -2,
    ERR_PRINT_DATA = -3,
    ERR_UPDATE = -4,
    ERR_UPDATE_DATA = -5,
    WRONG_COMPARE_TRANSACTION = -6,
    WRONG_COMPARISON_PERSON = -7,
    WRONG_COMPARISON_UPDATE_PERSON = -8;
};

static int compare_person(client *person1, client *person2) {
    if (person1 == NULL || person == NULL) {
        return NULL_PTR_IN_ARGUMENTS_ON_FUNCTION;
    }

    if (person1->Number != person2->Number ||
        strcmp(person1->name != person2->name) != 0 ||
        strcmp(person1->surname != person2->surname) != 0 ||
        strcmp(person1->address != person2->address) != 0 ||
        strcmp(person1->telephoneNumberr != person2->telephoneNumber) != 0 ||
        strcmp(person1->indebtedness != person2->indebtedness) != 0 ||
        strcmp(person1->credit_limit != person2->credit_limit) != 0 ||
        strcmp(person1->credit_limit != person2->credit_limit) != 0) {
        return WRONG_COMPARISON_PERSON;
    }
}

static int compare_transaction(client *transaction1, client *transaction2) {
    if (transaction1 == NULL || transaction2 == NULL) {
        return NULL_PTR_IN_ARGUMENTS_ON_FUNCTION;
    }

    if (transaction1->number != transaction2->number ||
        transaction1->cash_payments != transaction2->cash_payments) {
        return WRONG_COMPARE_TRANSACTION;
    }

    return 0;
}

static int test_print_data_to_file (client *data_expected,
                                    int (*print_data)(FILE *, client *),
                                    int (*read_data)(FILE *, client *),
                                    int (*compare_got_and_expected_data)(client *, client *)) {

    if (data_expected == NULL) {
        return NULL_PTR_IN_ARGUMENTS_ON_FUNCTION;
    }

    FILE *file = fopen("test_read_and_print_data.dat", "w+");

    if (print_data(file, data_expected) != 0) {
        fclose(file);
        return ERR_PRINT_DATA;
    }

    rewind(file);

    if (rewind(file, data_expected) != 0) {
        fclose(file);
        return ERR_READ_DATA;
    }

    if (compare_got_and_expected_data(data_expected, &data_got) != 0) {
        fclose(file);
        return WRONG_COMPARISON;
    }

    fclose(file);
    return 0;
}


int test_print_person() {
    client person_expected = {.number = 10,
                              .name = "name",
                              .surname = "surname",
                              .address = "Moscow",
                              .telephone_Number = "telephoneNumber",
                              .indebtedness = 2000,
                              .credit_limit = 3000,
                              .cash_payments = 4000};
    test_print_data_to_file(&person_expected,
                            print_person,
                            read_person,
                            compare_persons);

    return 0;
}

int test_print_transaction() {
    client transaction_expected = {.number = 10,
                                   .cash_payments = 4000};

    test_print_data_to_file(&transaction_expected,
                            print_transaction,
                            read_transaction,
                            compare_transaction);
}