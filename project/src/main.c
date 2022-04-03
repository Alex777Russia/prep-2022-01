#include "utils.h"

int main(void) {
    int choice = 0;

    Data client_data, transfer;

    FILE *First_file, *Second_file, *Client_file;

    printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");

    while (scanf("%d", &choice) != -1) {
        switch (choice) {
            case 1: {
                First_file = fopen("record.dat", "r+");
                if (First_file == NULL) {
                    puts("Not access");
                } else {
                    writeMaster(First_file, &client_data);
                    fclose(First_file);
                }
                break;
            }
            case 2: {
                First_file = fopen("transaction.dat", "r+");
                if (First_file == NULL) {
                    puts("Not access");
                } else {
                    writeTransaction(First_file, &transfer);
                    fclose(First_file);
                }
                break;
            }
            case 3: {
                First_file = fopen("record.dat", "r");
                Second_file = fopen("transaction.dat", "r");
                Client_file = fopen("blackrecord.dat", "w");

                if (First_file == NULL || Second_file == NULL) {
                    puts("exit");
                } else {
                    new_data_client(First_file, Second_file, Client_file, &client_data, &transfer);
                    fclose(First_file);
                    fclose(Second_file);
                    fclose(Client_file);
                }
                break;
            }
            default: {
                puts("error");
                break;
            }
        }

        printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
    }
    return 0;
}
