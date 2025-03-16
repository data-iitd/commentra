#include <stdio.h>

int main(){
    // Include necessary headers
    // The code starts by including necessary headers for input and output operations.
    // Headers for input and output operations are included.

    // Declare arrays
    // Two arrays, `train` and `bus`, are declared to store the values.
    int train[2];
    int bus[2];

    // Input values
    // The values for `train` and `bus` are taken from the user.
    scanf("%d %d",&train[0],&train[1]);
    scanf("%d %d",&bus[0],&bus[1]);

    // Calculate the sum
    // The code then calculates the sum of the minimum values from both arrays.
    printf("%d\n",(train[0]<train[1]?train[0]:train[1])+(bus[0]<bus[1]?bus[0]:bus[1]));

    // Output the result
    // Finally, the result is printed to the console.
    return 0;
}

