#include <stdio.h>

int main() {
    int windowSize, i, numFrames, frames[50];

    // Ask user for window size
    printf("Enter window size: ");
    scanf("%d", &windowSize);

    // Ask user for total number of frames to send
    printf("Enter number of frames to transmit: ");
    scanf("%d", &numFrames);

    // Get each frame number from user
    printf("Enter %d frame numbers: ", numFrames);
    for (i = 0; i < numFrames; i++) {
        scanf("%d", &frames[i]);
    }

    printf("\nTransmitting frames using Sliding Window Protocol (Go-Back-N)\n");
    printf("Sender sends %d frames at a time and waits for acknowledgement.\n\n", windowSize);

    // Send frames in groups of windowSize
    for (i = 0; i < numFrames; i++) {
        printf("%d ", frames[i]);

        // If window is full, simulate waiting for ACK
        if ((i + 1) % windowSize == 0) {
            printf("\nAcknowledgement received for above frames.\n\n");
        }
    }

    // If last group is incomplete, send ACK for remaining
    if (numFrames % windowSize != 0) {
        printf("\nAcknowledgement received for last few frames.\n");
    }

    return 0;
}


