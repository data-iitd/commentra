#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare arrays to hold the arrival times for train and bus
    int train[2];
    int bus[2];

    // Input the arrival times for the train
    scanf("%d %d", &train[0], &train[1]);
    // Input the arrival times for the bus
    scanf("%d %d", &bus[0], &bus[1]);

    // Calculate the minimum arrival time between the two times for train and bus,
    // and output the total minimum arrival time
    printf("%d\n", (train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]));

    return 0; // End of the program
}

