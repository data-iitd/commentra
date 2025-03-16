#include <stdio.h>

int main() {
    // Declare variables for input
    int A, B;
    
    // Read first integer input A from user
    scanf("%d", &A);
    
    // Read second integer input B from user
    scanf("%d", &B);
    
    // Initialize variables for storing remainders and result
    int amari = 0;
    int result = 0;
    
    // Calculate the result by dividing B by A - 1 and storing the quotient
    result = (B - 1) / (A - 1);
    
    // Calculate the remainder of B divided by A - 1 and store it in amari
    amari = (B - 1) % (A - 1);
    
    // Check if the remainder is not zero
    if (amari != 0) {
        // If the remainder is not zero, increment the result by 1
        result += 1;
    }
    
    // Write the result to the standard output
    printf("%d\n", result);
    
    return 0; // End of the program
}

// <END-OF-CODE>
