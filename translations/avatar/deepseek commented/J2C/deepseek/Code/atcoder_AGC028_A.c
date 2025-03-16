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

    // Read the strings
    char s[1000], t[1000];
    scanf("%s %s", s, t);

    // Filter the range of the GCD and check character mismatches
    int result = -1;
    for (int k = 0; k < gcd_value; k++) {
        if (s[k * n / gcd_value] != t[k * m / gcd_value]) {
            result = -1;
            break;
        }
    }

    if (result != -1) {
        // Calculate the result using the formula
        int lcm = (n * m) / gcd_value;
        printf("%d\n", lcm);
    } else {
        printf("%d\n", lcm);
    }

    return 0;
}
