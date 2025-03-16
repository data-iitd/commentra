#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function to compute the greatest common divisor (GCD) of two numbers
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

// Function to compute the least common multiple (LCM) of two numbers
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

// Function to get the prime factorization of a number
map<long long, long long> getPrimeFactor(long long n) {
    map<long long, long long> res;
    // Iterate from 2 to the square root of n
    for (long long i = 2; i * i <= n; ++i) {
        // While i divides n, store i in the result map
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    // If n is still greater than 1, it is a prime factor
    if (n != 1) res[n] = 1;
    return res;
}

// Function to check if a number is prime
bool IsPrimeNumber(long long num) {
    if (num <= 2) return true; // 0, 1, and 2 are considered prime
    else if (num % 2 == 0) return false; // Exclude even numbers

    double sqrtNum = sqrt(num);
    // Check for factors from 3 to the square root of num
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false; // Found a factor, not prime
        }
    }

    return true; // No factors found, num is prime
}

// Function to compute modular inverse using the Extended Euclidean Algorithm
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    // Loop until b becomes zero
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b); // Swap a and b
        u -= t * v; swap(u, v); // Update u and v
    }
    u %= m; // Ensure u is within the modulo
    if (u < 0) u += m; // Adjust if u is negative
    return u; // Return the modular inverse
}

// Macro definitions for loop iterations
#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)

int main() {
    ll N, K;
    // Input the number of elements and the value of K
    scanf("%lld %lld", &N, &K);

    ll *A = (ll *)malloc((N + 1) * sizeof(ll));
    // Input the elements into the vector A
    repeq(i, 1, N) {
        scanf("%lld", &A[i]);
    }

    ll cur = 1; // Initialize current position
    ll *dic = (ll *)malloc((N + 1) * sizeof(ll));
    // Dictionary to store the first occurrence of each index
    repeq(i, 1, N) {
        dic[i] = -1;
    }
    bool flg = false; // Flag to indicate if we have entered a cycle

    // Process the sequence based on the value of K
    repeq(i, 1, K) {
        // If current index has not been seen before or we are in a cycle
        if (dic[cur] < 0 || flg) {
            dic[cur] = i; // Record the current index
            cur = A[cur]; // Move to the next index
        }
        // If we have seen this index before and are not in a cycle
        else if (!flg) {
            ll tmp = K - (dic[cur] - 1); // Calculate remaining steps
            tmp %= i - dic[cur]; // Adjust steps based on the cycle length
            i = K - tmp; // Update i to skip to the end of the cycle
            flg = true; // Set the flag indicating we are in a cycle
        }
    }

    // Output the final position after K steps
    printf("%lld\n", cur);
    return 0; // End of the program
}

