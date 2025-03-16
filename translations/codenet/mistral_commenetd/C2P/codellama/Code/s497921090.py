#include<stdio.h> # Include the standard input/output library

int main() # Start of the main function
{
    unsigned long long int n,a,b=0 # Declare variables n, a, and b of type unsigned long long int and initialize b to zero
    int i,j # Declare variables i and j of type int

    scanf("%llu",&n) # Read an unsigned long long integer value from the standard input and store it in the variable n

    b=(n*(n-1))/2 # Calculate the sum of numbers from 1 to n-1 and store the result in the variable b

    printf("%llu\n",b) # Print the value of b to the standard output

    return 0 # End of the main function with a return value of 0 indicating successful execution
}

