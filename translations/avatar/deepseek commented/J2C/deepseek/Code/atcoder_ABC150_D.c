#include <stdio.h>
#include <stdlib.h>

// Function to compute the greatest common divisor (GCD) of two numbers
long long getGCD(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return getGCD(b, a % b);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];

    // Initialize array a with size n, where each element is half of the next input
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] /= 2;
    }

    long long lcd = 1;

    // Calculate the least common multiple (LCM) of the elements in array a
    for (int i = 0; i < n; i++) {
        long long gcd = getGCD(lcd, a[i]);
        lcd = lcd * a[i] / gcd;
        if (lcd > m) { // Check if LCM exceeds m
            printf("0\n");
            return 0;
        }
    }

    // Check if the LCM is even for any element in the array
    for (int i = 0; i < n; i++) {
        if ((lcd / a[i]) % 2 == 0) {
            printf("0\n");
            return 0;
        }
    }

    // Calculate and print the number of integers up to m that are divisible by the LCM
    printf("%lld\n", (m / lcd + 1) / 2);

    return 0;
}
