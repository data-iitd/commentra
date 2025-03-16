#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

// Function to calculate the greatest common divisor (GCD)
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// Function to calculate the least common multiple (LCM)
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Function to get the prime factors of a number
void getPrimeFactor(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            printf("%lld ", i);
            n /= i;
        }
    }
    if (n != 1) printf("%lld ", n);
}

// Function to check if a number is a prime number
int IsPrimeNumber(ll num) {
    if (num <= 2) return 1;
    else if (num % 2 == 0) return 0;

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to calculate the modular inverse of a number
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; 
        long long temp = a; a = b; b = temp;
        u -= t * v; 
        temp = u; u = v; v = temp;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    ll N, K;
    scanf("%lld %lld", &N, &K);

    // Array to store N+1 integers
    ll *A = (ll *)malloc((N + 1) * sizeof(ll));
    for (ll i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

    // Variables to track the current position and the dictionary
    ll cur = 1;
    ll *dic = (ll *)malloc((N + 1) * sizeof(ll));
    for (ll i = 0; i <= N; i++) {
        dic[i] = -1;
    }
    int flg = 0;
    for (ll i = 1; i <= K; i++) {
        if (dic[cur] < 0 || flg) {
            dic[cur] = i;
            cur = A[cur];
        } else if (!flg) {
            ll tmp = K - (dic[cur] - 1);
            tmp %= i - dic[cur];
            i = K - tmp;
            flg = 1;
        }
    }

    // Output the final position
    printf("%lld\n", cur);

    // Free allocated memory
    free(A);
    free(dic);
    
    return 0;
}

// <END-OF-CODE>
