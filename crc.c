#include <stdio.h>

int data[20], gen[20], temp[20];
int data_len, gen_len;

int main() {
    int i, j, choice;

    // Step 1: Choose operation
    printf("1. Generate CRC\n2. Check CRC\nEnter choice: ");
    scanf("%d", &choice);

    // Step 2: Input data
    printf("Enter length of data: ");
    scanf("%d", &data_len);
    printf("Enter data bits: ");
    for (i = 0; i < data_len; i++)
        scanf("%d", &data[i]);

    // Step 3: Input generator
    printf("Enter length of generator: ");
    scanf("%d", &gen_len);
    printf("Enter generator bits: ");
    for (i = 0; i < gen_len; i++)
        scanf("%d", &gen[i]);

    // Step 4: Copy data and append 0s for division
    for (i = 0; i < data_len; i++)
        temp[i] = data[i];
    for (i = data_len; i < data_len + gen_len - 1; i++)
        temp[i] = 0;

    // Step 5: Perform division
    for (i = 0; i < data_len; i++) {
        if (temp[i] == 1) {
            for (j = 0; j < gen_len; j++)
                temp[i + j] = temp[i + j] ^ gen[j];
        }
    }

    // Step 6: Output result
    if (choice == 1) {
        printf("CRC codeword: ");
        for (i = 0; i < data_len; i++)
            printf("%d", data[i]);
        for (i = data_len; i < data_len + gen_len - 1; i++)
            printf("%d", temp[i]);
    } else {
        int error = 0;
        for (i = data_len; i < data_len + gen_len - 1; i++) {
            if (temp[i] != 0)
                error = 1;
        }
        if (error)
            printf("Data has error.\n");
        else
            printf("Data is correct.\n");
    }

    printf("\n");
    return 0;
}

