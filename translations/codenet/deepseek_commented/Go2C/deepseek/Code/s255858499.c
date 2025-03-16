#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    char buffer[256];

    // Reading the first integer input
    fgets(buffer, sizeof(buffer), stdin);
    a = atoi(buffer);

    // Reading the second integer input
    fgets(buffer, sizeof(buffer), stdin);
    b = atoi(buffer);

    // Checking if the product of a and b is odd or even and printing the result
    if ((a * b) % 2 != 0) {
        printf("Odd\n");
    } else {
        printf("Even\n");
    }

    return 0;
}
