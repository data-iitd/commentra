#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MOD 1000000007
#define INF 999999999999999999

// Function to perform prime factorization
void prime_factorize(long long n, int *factors, int *count) {
    int index = 0;
    while (n % 2 == 0) {
        factors[index++] = 2;
        n /= 2;
    }
    for (long long f = 3; f * f <= n; f += 2) {
        while (n % f == 0) {
            factors[index++] = f;
            n /= f;
        }
    }
    if (n > 1) {
        factors[index++] = n;
    }
    *count = index;
}

int main() {
    long long n;
    scanf("%lld", &n);
    
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    int factors[100]; // Array to hold prime factors
    int count = 0;
    prime_factorize(n, factors, &count);

    // Count the occurrences of each prime factor
    int ans = 0;
    for (int i = 0; i < count; i++) {
        int x = 1; // Start with the first occurrence
        for (int j = 1; j <= INT_MAX; j++) {
            if (x <= count - i) {
                x += j;
                ans++;
            } else {
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
