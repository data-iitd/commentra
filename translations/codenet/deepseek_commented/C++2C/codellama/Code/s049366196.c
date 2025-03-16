#include <stdio.h> // For input and output operations
#include <stdlib.h> // For standard input and output operations
#include <stdbool.h> // For boolean values
#include <string.h> // To use the string class
#include <math.h> // For mathematical operations
#include <limits.h> // For the maximum value of an integer
#define ll long long // Defines 'll' as an alias for 'long long'
#define mod 1e9+7 // Defines a constant for modulo operation
#define inf 1e9 // Defines a constant for infinity
#define ALL(v) (v).begin(), (v).end() // Defines a macro to get the begin and end of a container

// Function to check if a number is prime
bool is_prime(ll x) {
    for (ll i = 2; i*i <= x; i++) // Iterates from 2 to the square root of x
        if (x % i == 0) return false; // Returns false if x is divisible by i
    return true; // Returns true if no divisors are found
}

int main() {
    int N;
    scanf("%d", &N); // Reads an integer N from standard input

    ll ans = 1; // Initializes the answer variable to 1
    for (int i = 2; i <= N; i++) { // Iterates from 2 to N
        if (is_prime((ll)i)) { // Checks if the current number i is prime
            int NN = N;
            int cnt = 0; // Initializes a counter to count the power of the prime
            while (NN) { // While loop to calculate the power of the prime in N
                cnt += NN/i; // Adds the quotient of NN divided by i to cnt
                NN /= i; // Divides NN by i
            }
            ans *= cnt+1; // Multiplies ans by cnt+1
            ans %= mod; // Takes modulo mod to prevent overflow
        }
    }

    printf("%lld\n", ans); // Prints the final answer
    return 0; // Indicates successful execution
}

