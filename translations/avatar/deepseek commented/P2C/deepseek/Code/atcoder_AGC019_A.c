#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 1e9
#define MOD 1000000007

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int q, h, s, d, n;
    scanf("%d %d %d %d %d", &q, &h, &s, &d, &n);

    // Calculate the best price for single liters
    int best1L = q < h ? (q < s ? q : s) : (h < s ? h : s);
    best1L = best1L < (s / 2) ? best1L : (s / 2);

    // Calculate the best price for double liters
    int best2L = d < (best1L * 2) ? d : (best1L * 2);

    // Check if the quantity n is even or odd and print the total cost accordingly
    if (n % 2 == 0) {
        printf("%d\n", (n / 2) * best2L);
    } else {
        printf("%d\n", (n / 2) * best2L + best1L);
    }

    return 0;
}
