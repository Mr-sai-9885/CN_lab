// Simple Caesar Cipher Encryption/Decryption for Beginners
#include <stdio.h>

int main() {
    char ch;
    int key;

    // Ask for a single lowercase character
    printf("Enter a lowercase letter: ");
    scanf(" %c", &ch);

    // Ask for key (number of positions to shift)
    printf("Enter the key (shift value): ");
    scanf("%d", &key);

    // Encrypt the character
    char encrypted = ((ch - 'a' + key) % 26) + 'a';
    printf("Encrypted character: %c\n", encrypted);

    // Decrypt the character back
    char decrypted = ((encrypted - 'a' - key + 26) % 26) + 'a';
    printf("Decrypted character: %c\n", decrypted);

    return 0;
}
