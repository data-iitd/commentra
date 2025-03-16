#include <stdio.h>

int main(){
    // Declare two arrays to store the number of passengers in each train and bus
    int train[2];
    int bus[2];

    // Read the number of passengers in each train from the user
    scanf("%d %d", &train[0], &train[1]);

    // Read the number of passengers in each bus from the user
    scanf("%d %d", &bus[0], &bus[1]);

    // Calculate the total number of passengers
    printf("%d\n", (train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]));

    return 0;
}

