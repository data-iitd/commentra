#include <stdio.h>

int main() {
    // Declare arrays
    // Two arrays, `train` and `bus`, are declared to store the values.
    int train[2];
    int bus[2];

    // Input values
    // The values for `train` and `bus` are taken from the user.
    scanf("%d %d", &train[0], &train[1]);
    scanf("%d %d", &bus[0], &bus[1]);

    // Calculate the sum
    // The code then calculates the sum of the minimum values from both arrays.
    int result = (train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]);
    
    // Output the result
    printf("%d\n", result);

    return 0;
}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
