#include <stdio.h>

int main()
{
    int A, B; // Declare two integer variables A and B
    scanf("%d %d", &A, &B); // Read the values of A and B from the standard input

    if(A < 13 && A >= 6) { // Check if A is within the range of 6 to 12 (inclusive)
        printf("%d\n", B / 2); // If true, divide B by 2 and print the result to the standard output
    }

    if(A < 6) { // Check if A is less than 6
        printf("0\n"); // If true, print 0 to the standard output
    }

    if(A >= 13) { // Check if A is greater than or equal to 13
        printf("%d\n", B); // If true, print B to the standard output
    }

    return 0;
}

// <END-OF-CODE>
