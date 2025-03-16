
#include <stdio.h>

int main() {
    // Declare and initialize two integer variables "a" and "b"
    // by reading input values from the standard input using the "scanf" function
    int a, b;
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

    // End of code
    return 0;
}

// End of code