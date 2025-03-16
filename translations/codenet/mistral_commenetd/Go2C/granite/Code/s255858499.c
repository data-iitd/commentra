

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the first two integers from stdin and store them in variables a and b
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    // Check if the product of a and b is odd or even
    if (a * b % 2!= 0) {
        // If the product is odd, print "Odd" to stdout
        printf("Odd\n");
    } else {
        // If the product is even, print "Even" to stdout
        printf("Even\n");
    }

    return 0;
}
