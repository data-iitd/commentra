#include <stdio.h>

int main(void)
{
    // Declare variables to hold the range (a, b) and the number (c)
    int a, b, c, i, count;

    // Read three integers from user input: a, b, and c
    scanf("%d%d%d", &a, &b, &c);

    // Initialize count to zero to keep track of how many numbers in the range divide c
    count = 0;

    // Loop through each integer i from a to b (inclusive)
    for (i = a; i <= b; i++) {
        // Check if c is divisible by i
        if (c % i == 0)
            // If divisible, increment the count
            count++;
    }

    // Print the total count of numbers that divide c
    printf("%d\n", count);
    
    // Return 0 to indicate successful completion of the program
    return 0;
}
