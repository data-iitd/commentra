#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int X;
    scanf("%d", &X);  // Take an integer input from the user and store it in X
    bool prime[100010];  // Initialize a list 'prime' with 100010 elements, all set to true
    for (int i = 0; i < 100010; i++) {
        prime[i] = true;
    }
    prime[0] = false;  // 0 is not a prime number
    prime[1] = false;  // 1 is not a prime number

    // Mark all even numbers (except 2) as not prime
    for (int i = 4; i < 100010; i += 2) {
        prime[i] = false;
    }

    // Use a while loop to mark non-prime numbers using the Sieve of Eratosthenes algorithm
    for (int i = 3; i * i <= 100008; i += 2) {
        if (prime[i]) {
            for (int j = i + i; j <= 100008; j += i) {
                prime[j] = false;
            }
        }
    }

    // Iterate through the range from X to 100008 and print the first prime number found
    for (int i = X; i <= 100008; i++) {
        if (prime[i]) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
