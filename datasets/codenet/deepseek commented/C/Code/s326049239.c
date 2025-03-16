#include <stdio.h>
#include <stdlib.h>

// Main function to execute the program
int main()
{
    int a, c, k, b; // Declare variables to store input, counters, and temporary values

    // Start a while loop to read input
    while (~scanf("%d", &a)) // Read an integer 'a' from the input
    {
        c = 0, k = 0; // Initialize counters 'c' and 'k' to 0

        if (a < 3) // Check if 'a' is less than 3
        {
            printf("0\n"); // Print 0 if 'a' is less than 3
        }
        else
        {
            b = a; // Store the initial value of 'a' in 'b' for later use
            while (a--) // Decrement 'a' until it becomes 0
            {
                b--; // Decrement 'b' in each iteration
                c++; // Increment 'c' in each iteration
                if (c == 3) // Check if 'c' equals 3
                {
                    k++; // Increment 'k'
                    c = 0; // Reset 'c' to 0
                }
            }
            printf("%d\n", k); // Print the number of times 'c' reset to 0
        }
    }
}
