#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the greatest common divisor (gcd)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (lcm)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int gcd_value = gcd(n, m);

    char s[1001], t[1001];
    scanf("%s %s", s, t);

    // Check for mismatches in the characters of the two strings based on the gcd
    // If a mismatch is found, print -1; otherwise, print the lcm of n and m
    int mismatch = 0;
    for (int k = 0; k < gcd_value; k++) {
        if (s[k * n / gcd_value] != t[k * m / gcd_value]) {
            mismatch = -1;
            break;
        }
    }

    if (mismatch == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", lcm(n, m));
    }

    return 0;
}
