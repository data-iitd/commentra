#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// Function to compute the least common multiple (LCM) of two numbers
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// Function to get the prime factorization of a number
int* getPrimeFactor(int n, int* size) {
    int* res = (int*)malloc(100 * sizeof(int)); // Allocate memory for the result
    *size = 0; // Initialize the size of the result
    // Iterate from 2 to the square root of n
    for (int i = 2; i * i <= n; ++i) {
        // While i divides n, store i in the result array
        while (n % i == 0) {
            res[(*size)++] = i;
            n /= i;
        }
    }
    // If n is still greater than 1, it is a prime factor
    if (n != 1) res[(*size)++] = n;
    return res;
}

// Function to check if a number is prime
int IsPrimeNumber(int num) {
    if (num <= 2) return 1; // 0, 1, and 2 are considered prime
    else if (num % 2 == 0) return 0; // Exclude even numbers

    int sqrtNum = (int)sqrt(num);
    // Check for factors from 3 to the square root of num
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return 0; // Found a factor, not prime
        }
    }

    return 1; // No factors found, num is prime
}

// Function to compute modular inverse using the Extended Euclidean Algorithm
int modinv(int a, int m) {
    int b = m, u = 1, v = 0;
    // Loop until b becomes zero
    while (b) {
        int t = a / b;
        a -= t * b; u -= t * v; // Update a and u
        int temp = a; a = b; b = temp; // Swap a and b
        temp = u; u = v; v = temp; // Swap u and v
    }
    u %= m; // Ensure u is within the modulo
    if (u < 0) u += m; // Adjust if u is negative
    return u; // Return the modular inverse
}

// Macro definitions for loop iterations
#define rep(i,s,e) for(int i=s;i<e;i++)
#define repeq(i,s,e) for(int i=s;i<=e;i++)

int main() {
    int N, K;
    // Input the number of elements and the value of K
    scanf("%d %d", &N, &K);

    int A[N + 1];
    // Input the elements into the array A
    repeq(i, 1, N) {
        scanf("%d", &A[i]);
    }

    int cur = 1; // Initialize current position
    int dic[N + 1]; // Dictionary to store the first occurrence of each index
    memset(dic, -1, sizeof(dic)); // Initialize the dictionary
    int flg = 0; // Flag to indicate if we have entered a cycle

    // Process the sequence based on the value of K
    repeq(i, 1, K) {
        // If current index has not been seen before or we are in a cycle
        if (dic[cur] < 0 || flg) {
            dic[cur] = i; // Record the current index
            cur = A[cur]; // Move to the next index
        }
        // If we have seen this index before and are not in a cycle
        else if (!flg) {
            int tmp = K - (dic[cur] - 1); // Calculate remaining steps
            tmp %= i - dic[cur]; // Adjust steps based on the cycle length
            i = K - tmp; // Update i to skip to the end of the cycle
            flg = 1; // Set the flag indicating we are in a cycle
        }
    }

    // Output the final position after K steps
    printf("%d\n", cur);
    return 0; // End of the program
}
