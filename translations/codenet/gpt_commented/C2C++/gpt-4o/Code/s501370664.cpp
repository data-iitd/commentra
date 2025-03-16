#include <iostream>
#include <vector>

// Global vector to hold the sieve flags for prime numbers
std::vector<int> flag;

// Function to generate prime numbers up to a given number using the Sieve of Eratosthenes
void prime(int num) {
    // Resize the flag vector to hold the sieve flags
    flag.resize(num + 1, 0);

    // Implementing the Sieve of Eratosthenes
    for (int i = 2; i * i <= num; i++) {
        // If the number is still marked as prime
        if (flag[i] == 0) {
            // Mark all multiples of i as non-prime
            for (int j = 2; i * j <= num; j++) {
                flag[i * j] = 1; // Marking the multiple as non-prime
            }
        }
    }
}

// Main function to execute the program
int main() {
    int n;

    // Generate prime numbers up to 50000
    prime(50000);

    // Infinite loop to continuously accept user input
    while (true) {
        // Read an integer from the user
        std::cin >> n;
        // Exit the loop if the input is 0
        if (n == 0) {
            break;
        }
        
        int cnt = 0; // Initialize count of valid pairs

        // Check pairs of primes that sum up to n
        for (int i = 2; i * 2 <= n; i++) {
            // If both i and n-i are prime
            if (!flag[i] && !flag[n - i]) {
                cnt++; // Increment the count of valid pairs
            }
        }
        
        // Output the count of prime pairs that sum up to n
        std::cout << cnt << std::endl;
    }

    return 0; // Return success
}

// <END-OF-CODE>
