#include <stdio.h> // Including standard input-output library

int main() {
    // Declaring two integer variables
    int a, b;
    
    // Reading two integer values from the user
    scanf("%d %d", &a, &b);
    
    // Checking if the first integer 'a' is positive
    if (a > 0) {
        printf("Positive\n"); // Output "Positive" if 'a' is greater than 0
    } 
    // Checking if the second integer 'b' is non-negative (zero or positive)
    else if (b >= 0) {
        printf("Zero\n"); // Output "Zero" if 'b' is greater than or equal to 0
    } 
    // Checking if the difference between 'b' and 'a' plus 1 is even
    else if ((b - a + 1) % 2 == 0) {
        printf("Positive\n"); // Output "Positive" if the result is even
    } 
    // If none of the above conditions are met, it means the result is negative
    else {
        printf("Negative\n"); // Output "Negative" for all other cases
    }
    
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
