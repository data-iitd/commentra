
#include <stdio.h>

int main() {
    int a, b, hole = 1, i = 0, check = 1;

    // Get two integers from user input, separated by a space
    scanf("%d %d", &a, &b);

    // Loop until the condition is not met
    while (check) {
        // Check if the value of 'hole' is greater than or equal to 'b'
        if (hole >= b) {
            // If the condition is met, set 'check' to 0 to terminate the loop
            check = 0;
        } else {
            // If the condition is not met, update the value of 'hole'
            hole = a * (i + 1) - i;
            // Increment the value of 'i' by 1
            i++;
        }
    }

    // Once the loop terminates, print out the value of 'i' as the result
    printf("%d", i);

    return 0;
}
