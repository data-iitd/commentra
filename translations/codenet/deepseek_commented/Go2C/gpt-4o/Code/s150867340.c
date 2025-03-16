#include <stdio.h> // Including the standard input-output library

int main() {
    int a, b; // Declaring two integer variables `a` and `b`
    scanf("%d %d", &a, &b); // Reading two integers from the standard input
    int product = a * b; // Calculating the product
    if (product % 2 == 0) { // Checking if the product is even
        printf("Even\n"); // Printing "Even" if the product is even
    } else {
        printf("Odd\n"); // Printing "Odd" if the product is odd
    }
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
