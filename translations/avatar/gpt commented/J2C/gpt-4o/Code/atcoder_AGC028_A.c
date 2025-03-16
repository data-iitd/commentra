#include <stdio.h>
#include <stdlib.h>

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
long long lcm(int a, int b, int gcd) {
    return (long long)a * (b / gcd);
}

int main() {
    // Read two integers n and m from input
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Calculate the greatest common divisor (gcd) of n and m
    int gcd_value = gcd(n, m);
    
    // Read two strings s and t from input
    char *s = (char *)malloc((n + 1) * sizeof(char));
    char *t = (char *)malloc((m + 1) * sizeof(char));
    scanf("%s %s", s, t);
    
    // Check for mismatches in the characters of the two strings based on the gcd
    int mismatch_found = 0;
    for (int k = 0; k < gcd_value; k++) {
        if (s[k * n / gcd_value] != t[k * m / gcd_value]) {
            mismatch_found = 1;
            break;
        }
    }
    
    // If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
    if (mismatch_found) {
        printf("-1\n");
    } else {
        printf("%lld\n", lcm(n, m, gcd_value));
    }
    
    // Free allocated memory
    free(s);
    free(t);
    
    return 0;
}

// <END-OF-CODE>
