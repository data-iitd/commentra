#include <stdio.h>

int main()
{
    int n, i;

    // Read an integer input from the user
    scanf("%d", &n);

    // Iterate from n down to 1
    for (i = n; i >= 1; i--)
    {
        // Check if i is a divisor of n
        if (n % i == 0)
        {
            // Update n to the current divisor i
            n = i;
            // Print the divisor followed by a space
            printf("%d ", i);
        }
    }

    // End of code
    printf("\n