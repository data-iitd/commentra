#include <stdio.h>

int main() {
    int a, b;
    
    // Reading the first integer input from the user
    scanf("%d", &a);
    // Reading the second integer input from the user
    scanf("%d", &b);
    
    // Checking if the first number is positive
    if (a > 0) {
        printf("Positive\n"); // Printing "Positive" if the first number is greater than 0
    } 
    // Checking if the first number is zero or the second number is non-negative
    else if (b >= 0) {
        printf("Zero\n"); // Printing "Zero" if the second number is non-negative
    } 
    // Checking if the difference between b and a plus one is even
    else if ((b - a + 1) % 2 == 0) {
        printf("Positive\n"); // Printing "Positive" if the difference is even
    } 
    else {
        printf("Negative\n"); // Printing "Negative" if none of the above conditions are met
    }
    
    return 0;
}
