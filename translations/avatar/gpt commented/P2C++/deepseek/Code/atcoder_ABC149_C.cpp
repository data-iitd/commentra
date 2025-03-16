#include <iostream>
#include <vector>
using namespace std;

int main() {
    int X;
    cin >> X;

    // Initialize a vector to track prime numbers up to 100010
    // Start by assuming all numbers are prime (true)
    vector<bool> prime(100010, true);

    // Set 0 and 1 as non-prime (false)
    prime[0] = false;
    prime[1] = false;

    // Eliminate all even numbers greater than 2 from the list of primes
    for (int i = 4; i < 100010; i += 2) {
        prime[i] = false;
    }

    // Start checking for prime numbers from 3 onwards
    for (int i = 3; i * i <= 100008; i += 2) {
        // If 'i' is still marked as prime
        if (prime[i]) {
            // Mark all multiples of 'i' as non-prime
            for (int j = i + i; j <= 100008; j += i) {
                prime[j] = false;
            }
        }
    }

    // Find and print the first prime number greater than or equal to X
    for (int i = X; i <= 100008; ++i) {
        if (prime[i]) {
            cout << i << endl; // Print the prime number found
            break; // Exit the loop after finding the first prime
        }
    }

    return 0;
}
