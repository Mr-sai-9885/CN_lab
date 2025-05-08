#include <stdio.h>
#include <string.h>

int main() {
    char input[20], output[100], insertChar;
    int i = 0, j = 0, len, pos;

    // Step 1: Get the input string
    printf("Enter a string: ");
    scanf("%s", input);

    // Step 2: Find its length
    len = strlen(input);

    // Step 3: Get the position to insert at
    printf("Enter position to insert (1 to %d): ", len);
    scanf("%d", &pos);

    // Check for valid position
    if (pos < 1 || pos > len) {
        printf("Invalid position. Exiting.\n");
        return 0;
    }

    // Step 4: Get the character to insert
    printf("Enter a character to stuff: ");
    scanf(" %c", &insertChar); // note space before %c to clear buffer

    // Step 5: Add starting flag to output: dlestx
    output[j++] = 'd';
    output[j++] = 'l';
    output[j++] = 'e';
    output[j++] = 's';
    output[j++] = 't';
    output[j++] = 'x';

    // Step 6: Loop through input string
    while (i < len) {
        // If this is the position to insert
        if (i == pos - 1) {
            // Add stuffing: dle + insertChar + dle
            output[j++] = 'd';
            output[j++] = 'l';
            output[j++] = 'e';
            output[j++] = insertChar;
            output[j++] = 'd';
            output[j++] = 'l';
            output[j++] = 'e';
        }

        // Copy current character from input to output
        output[j++] = input[i++];
    }

    // Step 7: Add ending flag: dleetx
    output[j++] = 'd';
    output[j++] = 'l';
    output[j++] = 'e';
    output[j++] = 'e';
    output[j++] = 't';
    output[j++] = 'x';

    // Terminate output string
    output[j] = '\0';

    // Step 8: Show the result
    printf("Frame after stuffing: %s\n", output);

    return 0;
}
