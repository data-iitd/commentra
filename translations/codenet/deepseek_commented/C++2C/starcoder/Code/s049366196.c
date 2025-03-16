#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int x) {
    for (int i = 2; i*i <= x; i++) // Iterates from 2 to the square root of x
        if (x % i == 0) return false; // Returns false if x is divisible by i
    return true; // Returns true if no divisors are found
}

int main() {
    int N;
    scanf("%d", &N); // Reads an integer N from standard input

    int ans = 1; // Initializes the answer variable to 1
    for (int i = 2; i <= N; i++) { // Iterates from 2 to N
        if (is_prime(i)) { // Checks if the current number i is prime
            int NN = N;
            int cnt = 0; // Initializes a counter to count the power of the prime
            while (NN) { // While loop to calculate the power of the prime in N
                cnt += NN/i; // Adds the quotient of NN divided by i to cnt
                NN /= i; // Divides NN by i
            }
            ans *= cnt+1; // Multiplies ans by cnt+1
            ans %= 1000000007; // Takes modulo 1000000007 to prevent overflow
        }
    }

    printf("%d\n", ans); // Prints the final answer
    return 0; // Indicates successful execution
}

