#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Calculate the GCD of n and m
    int gcd_value = gcd(n, m);

    // Read input strings s and t
    char s[1000], t[1000];
    scanf("%s %s", s, t);

    // Perform the required calculation and print the result
    long result = 0;
    if (n * m / gcd_value > 1000) {
        for (int k = 0; k < gcd_value; k++) {
            if (s[k * n / gcd_value] != t[k * m / gcd_value]) {
                result = -1;
                break;
            }
        }
        if (result != -1) {
            result = (long)n * m / gcd_value;
        }
    } else {
        result = (long)n * m / gcd_value;
    }

    // Print the result
    printf("%ld\n", result);

    return 0;
}
