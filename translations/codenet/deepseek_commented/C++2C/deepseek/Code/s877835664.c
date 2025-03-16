#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

// Function to calculate the least common multiple (LCM)
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// Function to get the prime factors of a number
int getPrimeFactor(int n, int *factors, int *counts, int *size) {
    *size = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors[*size] = i;
            counts[*size] = 0;
            while (n % i == 0) {
                counts[*size]++;
                n /= i;
            }
            (*size)++;
        }
    }
    if (n != 1) {
        factors[*size] = n;
        counts[*size] = 1;
        (*size)++;
    }
    return 0;
}

// Function to check if a number is a prime number
bool IsPrimeNumber(int num) {
    if (num <= 2) return true;
    else if (num % 2 == 0) return false;

    int sqrtNum = (int)sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to calculate the modular inverse of a number
int modinv(int a, int m) {
    int b = m, u = 1, v = 0;
    while (b) {
        int t = a / b;
        a -= t * b;
        int temp = a; a = b; b = temp;
        u -= t * v;
        temp = u; u = v; v = temp;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// Macro for looping from s to e
#define rep(i, s, e) for(int i = s; i < e; i++)

// Macro for looping from s to e inclusive
#define repeq(i, s, e) for(int i = s; i <= e; i++)

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    // Array to store N+1 integers
    int A[N + 1];
    repeq(i, 1, N) {
        scanf("%d", &A[i]);
    }

    // Variables to track the current position and the dictionary
    int cur = 1;
    int dic[N + 1];
    memset(dic, -1, sizeof(dic));
    bool flg = false;
    repeq(i, 1, K) {
        if (dic[cur] < 0 || flg) {
            dic[cur] = i;
            cur = A[cur];
        } else if (!flg) {
            int tmp = K - (dic[cur] - 1);
            tmp %= i - dic[cur];
            i = K - tmp;
            flg = true;
        }
    }

    // Output the final position
    printf("%d\n", cur);
    return 0;
}
