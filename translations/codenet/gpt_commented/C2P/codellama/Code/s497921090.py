#include<stdio.h>

int main()
{
    // Declare variables
    unsigned long long int n, a, b = 0, i, j;

    // Read an unsigned long long integer from user input
    scanf("%llu", &n);

    // Calculate the number of ways to choose 2 items from n items
    // This is done using the formula: b = n * (n - 1) / 2
    b = (n * (n - 1)) / 2;

    // Print the result
    printf("%llu\n", b);

    // Return 0 to indicate successful execution
    return 0;
}

