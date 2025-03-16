#include <stdio.h>
#include <math.h>

int main() {
    int r, D, x;
    
    // Read three integers r, D, and x from input
    scanf("%d %d %d", &r, &D, &x);
    
    // Loop from 2 to 11 (inclusive)
    for (int i = 2; i <= 11; i++) {
        // Calculate the value using the given formula and print the integer result
        int result = (int)(pow(r, i - 1) * (x + (double)D / (1 - r)) - (double)D / (1 - r));
        printf("%d\n", result);
    }
    
    return 0;
}

// <END-OF-CODE>
