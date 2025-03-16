#include<stdio.h>  # Include the standard input/output library
int main()        # Define the main function
{
    unsigned long long int n, a, b = 0, i, j;  # Declare variables to store the input number and the result
    scanf("%llu", &n);  # Read the input number
    b = (n * (n - 1)) / 2;  # Calculate the result using the given formula
    printf("%llu\n", b);  # Print the result
    return 0;  # Indicate that the program ended successfully
}
