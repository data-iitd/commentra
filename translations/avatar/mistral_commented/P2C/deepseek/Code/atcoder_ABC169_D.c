#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 9999999999999999999
#define MOD 1000000007

// Function to prime factorize a number
void prime_factorize(int n, int *factors, int *size) {
    int i;
    *size = 0;
    while (n % 2 == 0) {
        factors[*size++] = 2;
        n /= 2;
    }
    for (i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors[*size++] = i;
            n /= i;
        }
    }
    if (n > 1) {
        factors[*size++] = n;
    }
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    int factors[100000];
    int size;
    prime_factorize(n, factors, &size);

    int fac[100000] = {0};
    for (int i = 0; i < size; i++) {
        fac[factors[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < 100000; i++) {
        if (fac[i] > 0) {
            int x = fac[i];
            for (int j = 1; j <= 1000000; j++) {
                if (x >= j) {
                    x -= j;
                    ans++;
                } else {
                    break;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
