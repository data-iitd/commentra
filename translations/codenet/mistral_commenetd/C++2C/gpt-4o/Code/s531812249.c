#include <stdio.h>

int main(void) // Main function
{
    int n, m; // Declare variables n and m of type int

    scanf("%d %d", &n, &m); // Read input values of n and m from standard input

    int ans = 0; // Initialize answer variable ans to 0

    // Calculate the sum of pairs for n
    ans += n * (n - 1) / 2; // Calculate the sum of numbers from 1 to n-1 and add it to the answer

    // Calculate the sum of pairs for m
    ans += m * (m - 1) / 2; // Calculate the sum of numbers from 1 to m-1 and add it to the answer

    printf("%d\n", ans); // Print the answer to the standard output

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
