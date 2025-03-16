
#include <stdio.h>

// Define a constant for the modulo operation
#define MOD 1000000007

// Function to compute n raised to the power of k under modulo
int pow(int n, int k) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 1) {
        return pow(n, k - 1) * n % MOD;
    } else {
        int t = pow(n, k / 2);
        return t * t % MOD;
    }
}

// Function to add two integers under modulo
int add(int a, int b) {
    return (a + b) % MOD;
}

// Function to subtract two integers under modulo
int sub(int a, int b) {
    return (a + MOD - b) % MOD;
}

// Function to multiply two integers under modulo
int mul(int a, int b) {
    return a % MOD * b % MOD % MOD;
}

// Function to divide two integers under modulo using modular multiplicative inverse
int div(int a, int b) {
    return mul(a, pow(b, MOD - 2));
}

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Initialize a slice to store the input numbers and a map to store the maximum prime factors
    int as[n];
    int ps[100001] = {0};

    // Read each number and perform prime factorization
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);

        // Get the prime factors of the current number
        int ns[100001] = {0};
        int x = as[i];
        for (int j = 2; j * j <= x; j++) {
            while (x % j == 0) {
                ns[j]++;
                x /= j;
            }
        }
        if (x!= 1) {
            ns[x]++;
        }

        // Update the maximum count of each prime factor found
        for (int j = 2; j <= 100000; j++) {
            ps[j] = ps[j] > ns[j]? ps[j] : ns[j];
        }
    }

    // Calculate the product of the maximum prime factors raised to their respective powers
    int x = 1;
    for (int j = 2; j <= 100000; j++) {
        for (int k = 1; k <= ps[j]; k++) {
            x = mul(x, j);
        }
    }

    // Calculate the final answer by summing the results of x divided by each input number
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div(x, as[i]));
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

// Translate the above C code to Java and end with comment "