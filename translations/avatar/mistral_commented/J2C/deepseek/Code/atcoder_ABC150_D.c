#include <stdio.h>
#include <stdlib.h>

// Function to find the greatest common divisor of two numbers
long getGCD(long a, long b) {
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

    // Initializing the array a with input values
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] /= 2;
    }

    long gcd;
    long lcd = 1;

    // Finding the least common multiple of all array elements
    for (int i = 0; i < n; i++) {
        gcd = getGCD(lcd, a[i]);
        lcd = lcd * a[i] / gcd;

        // Checking if lcm is greater than m
        if (lcd > m) {
            printf("0\n");
            return 0;
        }
    }

    // Checking if any array element is a factor of lcm
    for (int i = 0; i < n; i++) {
        if ((lcd / a[i]) % 2 == 0) {
            printf("0\n");
            return 0;
        }
    }

    // Printing the result
    printf("%ld\n", (m / lcd + 1) / 2);

    return 0;
}

