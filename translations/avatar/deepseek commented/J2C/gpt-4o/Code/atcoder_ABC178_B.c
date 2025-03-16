#include <stdio.h>

// Function to calculate x^y mod mod using efficient exponentiation by squaring
int modPower(int x, int y, int mod) {
    int res = 1;
    x %= mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

// Main function to read input, calculate the maximum product, and print the result
int main() {
    long a[4];
    for (int i = 0; i < 4; i++) {
        scanf("%ld", &a[i]);
    }
    long max_product = a[0] * a[2];
    max_product = (a[1] * a[3] > max_product) ? a[1] * a[3] : max_product;
    max_product = (a[0] * a[3] > max_product) ? a[0] * a[3] : max_product;
    max_product = (a[1] * a[2] > max_product) ? a[1] * a[2] : max_product;
    
    printf("%ld\n", max_product);
    return 0;
}

// <END-OF-CODE>
