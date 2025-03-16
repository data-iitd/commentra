
#include <stdio.h> // Include the standard input/output library

int main() {
    int a, b; // Declare two integer variables a and b
    
    scanf("%d %d", &a, &b); // Read two integer inputs from the user using the scanf function
    
    // Checking if the first number is positive
    if (a > 0) {
        printf("Positive\n"); // Print "Positive" if the first number is greater than 0
    } 
    // Checking if the first number is zero or the second number is non-negative
    else if (b >= 0) {
        printf("Zero\n"); // Print "Zero" if the second number is non-negative
    } 
    // Checking if the difference between b and a plus one is even
    else if ((b - a + 1) % 2 == 0) {
        printf("Positive\n"); // Print "Positive" if the difference is even
    } 
    else {
        printf("Negative\n"); // Print "Negative" if none of the above conditions are met
    }
    
    return 0; // Return 0 to indicate successful execution of the program
}
// END-OF-CODE