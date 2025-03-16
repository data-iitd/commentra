#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Read two integers n and m from input
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Calculate the greatest common divisor (gcd) of n and m
    int gcd = (int)gcd((long)n, (long)m);
    
    // Read two strings s and t from input
    char s[100], t[100];
    scanf("%s %s", s, t);
    
    // Check for mismatches in the characters of the two strings based on the gcd
    // If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
    int i, j;
    for (i = 0; i < gcd; i++) {
        if (s[i * n / gcd] != t[i * m / gcd]) {
            printf("%d\n", -1);
            return 0;
        }
    }
    printf("%ld\n", (long)n * (long)m / gcd);
    
    return 0;
}

int gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

