
// Leaky Bucket Algorithm - Simple Version with Explanatory Comments
#include <stdio.h>
#include <stdlib.h> // for rand() and sleep()
#include <unistd.h> // for sleep()

int main() {
    int bucketSize, outputRate, packets[5], i;
    int remaining = 0, incoming, waitTime;

    // Generate random packet sizes between 1 and 9
    for (i = 0; i < 5; i++) {
        packets[i] = rand() % 9 + 1;
    }

    // Get output rate and bucket capacity from user
    printf("Enter output rate: ");
    scanf("%d", &outputRate);

    printf("Enter bucket size: ");
    scanf("%d", &bucketSize);

    // Process each packet
    for (i = 0; i < 5; i++) {
        incoming = packets[i];

        // Check if incoming packet plus remaining exceeds bucket size
        if ((incoming + remaining) > bucketSize) {
            printf("\nPacket %d size = %d dropped (Bucket overflow)\n", i + 1, incoming);
            continue;
        }

        // Add packet to bucket
        remaining += incoming;
        printf("\nPacket %d size = %d added\n", i + 1, incoming);
        printf("Current bucket load: %d\n", remaining);

        // Random wait time until next packet
        waitTime = rand() % 5 + 1;
        printf("Next packet arrives in %d seconds\n", waitTime);

        // Simulate output during wait time
        while (waitTime-- && remaining > 0) {
            sleep(1);
            int toSend = (remaining > outputRate) ? outputRate : remaining;
            remaining -= toSend;
            printf("Sent %d bytes, Remaining = %d\n", toSend, remaining);
        }
    }

    // Send any remaining data after all packets
    while (remaining > 0) {
        sleep(1);
        int toSend = (remaining > outputRate) ? outputRate : remaining;
        remaining -= toSend;
        printf("Sent %d bytes, Remaining = %d\n", toSend, remaining);
    }

    return 0;
}
