#include <stdio.h>

int main() {
    int a, b;
    
    // Read the first integer
    scanf("%d", &a);
    // Read the second integer
    scanf("%d", &b);

    // Check if the product is odd or even
    if ((a * b) % 2 != 0) {
        printf("Odd\n");
    } else {
        printf("Even\n");
    }

    return 0;
}

// <END-OF-CODE>
