#include<stdio.h>

int main()
{
    // Declare an integer variable to hold the input value
    int n;

    // Read an integer value from standard input
    scanf("%d", &n);

    // Check if n is a multiple of 1000
    if(n % 1000 == 0) 
        // If true, print 0 since no additional amount is needed to reach the next multiple of 1000
        printf("%d\n", 0);
    else 
        // If false, calculate and print the difference to the next multiple of 1000
        printf("%d\n", (n / 1000 + 1) * 1000 - n);
}

