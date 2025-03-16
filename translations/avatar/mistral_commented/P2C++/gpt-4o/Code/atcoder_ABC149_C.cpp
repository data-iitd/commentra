#include <iostream>
#include <vector>

int main() {
    int X;
    std::cin >> X;

    // Initialize a vector 'prime' of boolean values with all elements as true
    std::vector<bool> prime(100010, true);

    // Set the first two elements of the vector as false, as 0 and 1 are not prime numbers
    prime[0] = false;
    prime[1] = false;

    // Sieve of Eratosthenes algorithm to find prime numbers up to 100008
    for (int i = 4; i < 100010; i += 2) {
        // If the number 'i' is prime
        if (prime[i]) {
            // Mark all multiples of 'i' as composite (non-prime)
            for (int j = i + i; j < 100010; j += i) {
                prime[j] = false;
            }
        }
    }

    // Find the prime number 'X' and print it
    int i = X;
    while (i < 100010) {
        // If the number 'i' is prime
        if (prime[i]) {
            std::cout << i << std::endl;
            // Exit the loop as we have found the prime number 'X'
            break;
        }
        i++;
    }

    return 0;
}

// <END-OF-CODE>
