#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Read an integer `n` from the user
    int n = atoi(argv[1]);
    // Initialize a variable `t` to zero
    int t = 0;
    // Iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++)
    {
        // Check if the index i is odd
        if (i + 1 & 1)
        {
            // If it is odd, increment the variable t by 1
            t += 1;
        }
    }
    // Print the result t/n as the output
    printf("%f\n", t / n);
    return EXIT_SUCCESS;
}
