#include <iostream>
#include <vector>

int main() {
    // Define the maximum value for the sieve
    const int MAX_V = 999999;
    // Vector to store prime status of numbers from 0 to MAX_V
    std::vector<int> prime(MAX_V + 1, 1);
    
    // Sieve of Eratosthenes to find prime numbers
    for (int i = 2; i * i <= MAX_V; i++) {
        if (prime[i]) {
            // If i is a prime, mark its multiples as non-prime
            for (int k = 2 * i; k <= MAX_V; k += i) {
                prime[k] = 0;
            }
        }
    }
    
    // Set 0 and 1 as non-prime
    prime[0] = 0;
    prime[1] = 0;
    
    // Counter for the number of inputs processed
    int count = 0;
    
    // Read integers from standard input until EOF
    int n;
    while (std::cin >> n) {
        count++;
        int cnt = 0;
        // Count the number of primes less than or equal to n
        for (int i = n; i > 0; i--) {
            if (prime[i] == 1) {
                cnt++;
            }
        }
        // Print the count of primes for the current input
        std::cout << cnt << std::endl;
        // Break the loop after processing 30 inputs
        if (count == 30) break;
    }
    
    return 0;
}

// <END-OF-CODE>
