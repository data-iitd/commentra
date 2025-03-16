#include <stdio.h>

int main() {
    int a, b;
    // Read two integer values from the standard input
    scanf("%d %d", &a, &b);

    // Calculate the product of "a" and "b" and store it in a new variable "product"
    int product = a * b;

    // Check if the product is even or odd using an if statement
    if (product % 2 == 0) {
        // If the product is even, print the message "Even" to the standard output
        printf("Even\n");
    } else {
        // If the product is odd, print the message "Odd" to the standard output
        printf("Odd\n");
    }

    return 0;
}
