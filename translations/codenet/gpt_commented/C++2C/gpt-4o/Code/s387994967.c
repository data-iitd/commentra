#include <stdio.h>

int main()
{
    // Declare two integer variables A and B
    int A, B;

    // Read input values for A and B from the user
    scanf("%d %d", &A, &B);

    // Check if A is between 6 (inclusive) and 13 (exclusive)
    if (A < 13 && A >= 6) {
        // If true, output half of B
        printf("%d\n", B / 2);
    }

    // Check if A is less than 6
    if (A < 6) {
        // If true, output 0
        printf("0\n");
    }

    // Check if A is greater than or equal to 13
    if (A >= 13) {
        // If true, output the value of B
        printf("%d\n", B);        
    }

    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
