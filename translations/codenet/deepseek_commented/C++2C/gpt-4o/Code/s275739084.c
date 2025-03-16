#include <stdio.h> // Include the stdio.h library for input and output operations.

int main() // The main function is the entry point of the program.
{
    int A, B; // Declare two integer variables A and B.
    scanf("%d %d", &A, &B); // Take input from the user for variables A and B.
    int C = A + B; // Calculate the sum of A and B and store it in variable C.
    
    if (A % 3 != 0 && B % 3 != 0 && C % 3 != 0) // Check if neither A, B, nor the sum C is divisible by 3.
    {
        printf("Impossible\n"); // If the condition is true, print "Impossible" to the console.
    }
    else
    {
        printf("Possible\n"); // Otherwise, print "Possible" to the console.
    }
    
    return 0; // Return 0 to indicate successful execution.
}

// <END-OF-CODE>
