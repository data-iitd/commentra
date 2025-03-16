#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the integer n, which represents the number of elements
    int n;
    scanf("%d", &n);
    
    // Read the next line of input and split it into an array of strings
    char *line = (char *)malloc(sizeof(char) * 1000);
    scanf("%s", line);
    char *sa[n];
    for (int i = 0; i < n; i++) {
        sa[i] = (char *)malloc(sizeof(char) * 1000);
        sa[i] = line;
        line = strchr(line,'');
        if (line) {
            *line = '\0';
            line++;
        }
    }
    
    // Initialize an integer array to hold the parsed values
    int a[n];
    
    // Parse the string array into an integer array
    for (int i = 0; i < n; i++) {
        a[i] = atoi(sa[i]);
    }
    
    // Define a modulus value for calculations to prevent overflow
    int mod = 1000000007;
    
    // Initialize a variable to hold the factorial product
    long p = 1;
    
    // Calculate the factorial of n modulo mod
    for (int i = 2; i <= n; i++) {
        p = p * i % mod;
    }
    
    // Initialize an array to hold cumulative sums of modular inverses
    long q[n];
    q[0] = 1; // Base case for the first element
    
    // Calculate the cumulative sum of modular inverses
    for (int i = 1; i < n; i++) {
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod;
    }
    
    // Initialize a variable to hold the final answer
    long ans = 0;
    
    // Calculate the final answer using the cumulative sums and input array
    for (int i = 0; i < n; i++) {
        long val = q[i] + q[n - i - 1] - 1; // Combine values from the q array
        val *= a[i]; // Multiply by the corresponding element in a
        val %= mod; // Take modulo
        val *= p; // Multiply by the factorial product
        val %= mod; // Take modulo again
        ans += val; // Add to the final answer
        ans %= mod; // Take modulo to keep the answer manageable
    }
    
    // Print the final result
    printf("%ld\n", ans);
    
    // Free the memory allocated for the string array
    for (int i = 0; i < n; i++) {
        free(sa[i]);
    }
    
    // Free the memory allocated for the line
    free(line);
    
    return 0;
}

// Function to compute the modular inverse using the Extended Euclidean Algorithm
long modinv(long a, int m) {
    long b = m;
    long u = 1;
    long v = 0;
    long tmp = 0;
    
    // Apply the Extended Euclidean Algorithm
    while (b > 0) {
        long t = a / b;
        a -= t * b;
        tmp = a;
        a = b;
        b = tmp;
        u -= t * v;
        tmp = u;
        u = v;
        v = tmp;
    }
    
    // Ensure u is positive and within the modulus
    u %= m;
    if (u < 0) u += m;
    
    // Return the modular inverse
    return u;
}

