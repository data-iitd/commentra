#include <stdio.h>

int main(){
    // Declare arrays
    int train[2];
    int bus[2];

    // Input values
    scanf("%d %d", &train[0], &train[1]);
    scanf("%d %d", &bus[0], &bus[1]);

    // Calculate the sum
    int sum = (train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]);

    // Output the result
    printf("%d\n", sum);

    return 0;
}
