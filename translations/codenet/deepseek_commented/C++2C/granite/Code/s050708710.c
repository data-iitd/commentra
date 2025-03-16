
#include <stdio.h> // Include the standard input/output library for input and output operations.
#include <stdlib.h> // Include the standard library library for general utilities like dynamic memory allocation, conversion functions, etc.

int main() // Define the main function which is the entry point of the program.
{
    int r, g, b, n; // Declare four integer variables to store input values.
    scanf("%d %d %d %d", &r, &g, &b, &n); // Read four integers from the standard input.
    int ans = 0; // Initialize a variable 'ans' to 0 to store the count of valid combinations.

    // Start a nested loop to iterate through possible values of 'i' and 'j' that represent the number of times 'r' and 'g' are used, respectively.
    for (int i = 0; i <= n / r; ++i)
    {
        for (int j = 0; j <= n / g; ++j)
        {
            int num = n - r * i - g * j; // Calculate the remaining value after using 'r * i' and 'g * j'.
            if (num >= 0 && num % b == 0) // Check if 'num' is non-negative and divisible by 'b'.
            {
                ++ans; // Increment 'ans' if the conditions are met.
            }
        }
    }

    printf("%d\n", ans); // Print the value of 'ans' which represents the count of valid combinations.
    return 0; // Return 0 to indicate successful execution of the program.
}


