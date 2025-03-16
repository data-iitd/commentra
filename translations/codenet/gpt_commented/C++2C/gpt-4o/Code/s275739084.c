#include <stdio.h>

int main()
{
    // Declare two integer variables A and B
    int A, B;

    // Read input values for A and B from the user
    scanf("%d %d", &A, &B);

    // Calculate the sum of A and B and store it in variable C
    int C = A + B;

    // Check if A, B, and C are all not divisible by 3
    if (A % 3 != 0 && B % 3 != 0 && C % 3 != 0)
    {
        // If the condition is true, output "Impossible"
        printf("Impossible\n");
    }
    else
    {
        // If the condition is false, output "Possible"
        printf("Possible\n");
    }

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
