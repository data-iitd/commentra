#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 999999999999999999
#define MOD 1000000007

void log_debug(const char *msg) {
    fprintf(stderr, "DEBUG: %s\n", msg);
}

long long prime_factorize(int n, int *factors) {
    int count = 0;
    while (n % 2 == 0) {
        factors[count++] = 2;
        n /= 2;
    }
    for (int f = 3; f * f <= n; f += 2) {
        while (n % f == 0) {
            factors[count++] = f;
            n /= f;
        }
    }
    if (n > 1) {
        factors[count++] = n;
    }
    return count;  // Return the number of factors found
}

int main() {
    int n;
    scanf("%d", &n);  // Read the integer n
    if (n == 1) {
        printf("0\n");  // If n is 1, print 0 and exit
        return 0;
    }

    int factors[100];  // Array to hold prime factors (size can be adjusted)
    int count = prime_factorize(n, factors);  // Get the prime factorization of n

    int ans = 0;
    int *occurrences = (int *)calloc(100, sizeof(int));  // Array to count occurrences of each prime factor

    for (int i = 0; i < count; i++) {
        occurrences[factors[i]]++;  // Count occurrences
    }

    for (int i = 0; i < 100; i++) {
        if (occurrences[i] > 0) {
            int x = occurrences[i];
            for (int j = 1; j < 99999999; j++) {
                if (x >= j) {
                    x -= j;
                    ans++;
                } else {
                    break;
                }
            }
        }
    }

    printf("%d\n", ans);  // Print the final answer
    free(occurrences);  // Free allocated memory
    return 0;
}
