#include <stdio.h>

int main() {
    int a, b;
    
    // Read two integers from the standard input
    scanf("%d %d", &a, &b);
    
    // Check if the product of a and b is even using the modulo operator (%)
    if ((a * b) % 2 == 0) {
        // If the condition is true, print the message "Even"
        printf("Even\n");
    } else {
        // If the condition is false, print the message "Odd"
        printf("Odd\n");
    }
    
    return 0;
}

