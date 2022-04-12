#include  "utils.h"

void new_data_client(FILE *first_file, FILE *second_file, FILE *client_file,
                 Data *client_data, Data *transfer) {
    while (fscanf(first_file, "%d%19s%19s%29s%14s%lf%lf%lf",
                  &client_data->Number,
                  client_data->Name,
                  client_data->Surname,
                  client_data->address,
                  client_data->telephoneNumber,
                  &client_data->indebtedness,
                  &client_data->credit_limit,
                  &client_data->cash_payments) != -1) {
        while (fscanf(second_file, "%d %lf",
                      &transfer->Number,
                      &transfer->cash_payments) != -1) {
            if (client_data->Number == transfer->Number && transfer->cash_payments != 0) {
                client_data->credit_limit += transfer->cash_payments;
            }
        }

        fprintf(client_file, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                client_data->Number,
                client_data->Name,
                client_data->Surname,
                client_data->address,
                client_data->telephoneNumber,
                client_data->indebtedness,
                client_data->credit_limit,
                client_data->cash_payments);
        rewind(second_file);
    }
}


void writeTransaction(FILE *file, Data *transfer) {
    printf("%s\n%s\n",
           "1 Number account: ",
           "2 Client cash payments: ");
    while (scanf("%d %lf",
                 &transfer->Number,
                 &transfer->cash_payments) != -1) {
        fprintf(file, "%-3d%-6.2f\n",
                transfer->Number,
                transfer->cash_payments);
        printf("%s\n%s\n",
               "1 Number account: ",
               "2 Client cash payments: ");
    }
}


void writeMaster(FILE *file, Data *Client) {
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
           "1 Number account: ",
           "2 Client name: ",
           "3 Surname: ",
           "4 Address client: ",
           "5 Client Telephone number: ",
           "6 Client indebtedness: ",
           "7 Client credit limit: ",
           "8 Client cash payments: ");

    while (scanf("%d%19s%19s%29s%14s%lf%lf%lf",
                 &Client->Number,
                 Client->Name,
                 Client->Surname,
                 Client->address,
                 Client->telephoneNumber,
                 &Client->indebtedness,
                 &Client->credit_limit,
                 &Client->cash_payments) != -1) {
        fprintf(file, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                Client->Number,
                Client->Name,
                Client->Surname,
                Client->address,
                Client->telephoneNumber,
                Client->indebtedness,
                Client->credit_limit,
                Client->cash_payments);
        printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
               "1 Number account: ",
               "2 Client name: ",
               "3 Surname: ",
               "4 Address client: ",
               "5 Client Telephone number: ",
               "6 Client indebtedness: ",
               "7 Client credit limit: ",
               "8 Client cash payments: ");
    }
}
