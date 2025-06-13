#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a frame
struct frame {
    int fno;           // Frame number
    int finfo;         // Frame data (only one value, not array)
} f[30];               // Array of 30 frames

int n; // Global variable for number of frames

// Function to sort frames based on frame number using Bubble Sort
void sort() {
    int i, j;
    struct frame temp;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(f[j].fno > f[j + 1].fno) {
                temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    // Taking input
    for(i = 0; i < n; i++) {
        f[i].fno = rand() % 50; // Assigning random frame number
        printf("Enter the frame data for frame number %d: ", f[i].fno);
        scanf("%d", &f[i].finfo);  // Note: finfo is an int, not array
    }

    // Sort frames based on frame number
    sort();

    // Displaying sorted frames
    printf("\nFrames\tSequence:\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\n", f[i].fno, f[i].finfo);
    }

    return 0;
}
