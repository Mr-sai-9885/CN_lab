#include <stdio.h>      // This is a standard input/output header for printf and scanf
#include <stdlib.h>     // This is used for the rand() function

int main()
{
    int or; // variable to store output rate (not used in logic here)
    printf("Enter Output Rate : ");
    scanf("%d", &or); // get output rate from user

    int bs; // variable to store bucket size (capacity)
    printf("Enter Bucket Size : ");
    scanf("%d", &bs); // get bucket size from user

    int op; // variable to store number of operations (number of packets to simulate)
    printf("Enter no of Operations : ");
    scanf("%d", &op); // get number of operations

    // simulate each packet one by one
    for (int i = 0; i < op; i++)
    {
        int n = rand() % 10; // randomly generate packet size between 0 to 9

        // check if packet size exceeds bucket capacity
        if (n > bs)
        {
            printf("Incoming Packet size %d is greater than capacity %d\n", n, bs);
        }
        else
        {
            // packet is accepted, show details
            printf("----------------------------------------\n");
            printf("Incoming Packet is : %d\n", n);
            printf("Transmission left : %d\n", n); // since output logic not used, just show the full size as left
            printf("----------------------------------------\n");

            int temp = rand() % 10; // simulate time in seconds until next packet

            printf("Next Packet will come at %d seconds\n", temp);

            // bytes remaining after output (but here no output is reduced, so temp - temp = 0)
            printf("Bytes Remaining : %d\n\n\n\n", temp - temp);
        }
    }
    // return 0 means program ended successfully
    return 0;
}
