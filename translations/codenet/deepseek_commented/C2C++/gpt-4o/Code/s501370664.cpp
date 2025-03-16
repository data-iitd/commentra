#include <iostream> // Include iostream for input/output
#include <vector>   // Include vector for dynamic array

std::vector<int> flag; // Declare a global vector to keep track of prime numbers

// Function to mark non-prime numbers up to a given number 'num'
void prime(int num) {
    flag.resize(num + 1, 0); // Resize the flag vector and initialize with 0

    for (int i = 2; i * i <= num; i++) { // Iterate to mark non-prime numbers
        if (flag[i] == 0) { // If 'i' is a prime number
            for (int j = 2; i * j <= num; j++) { // Mark multiples of 'i' as non-prime
                flag[i * j] = 1;
            }
        }
    }
}

// Main function to read an integer, calculate pairs of primes summing to 'n', and print the result
int main() {
    int n; // Declare variable to store input
    prime(50000); // Call the prime function to mark non-prime numbers up to 50000

    while (true) { // Infinite loop to read input until 'n' is zero
        std::cin >> n; // Read an integer 'n' from the user
        if (n == 0) {
            break; // Exit the loop if 'n' is zero
        }
        int cnt = 0; // Initialize the count of pairs
        for (int i = 2; i * 2 <= n; i++) { // Loop to find pairs of primes summing to 'n'
            if (flag[i] == 0 && flag[n - i] == 0) { // Check if both 'i' and 'n-i' are prime
                cnt++; // Increment the count if a valid pair is found
            }
        }
        std::cout << cnt << std::endl; // Print the count of pairs of primes summing to 'n'
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
