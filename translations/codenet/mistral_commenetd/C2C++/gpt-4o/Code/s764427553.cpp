#include <iostream>
#include <vector>

using namespace std;

// Main function starts here
int main() {
    // Initialize a constant MAX_V
    const int MAX_V = 999999;
    // Create a vector 'prime' of size MAX_V+1 with all elements set to true
    vector<bool> prime(MAX_V + 1, true);

    // Sieve of Eratosthenes algorithm to find prime numbers
    for (int i = 2; i <= MAX_V; i++) {
        // If i is prime, mark all its multiples as composite
        if (prime[i]) {
            for (int k = i * i; k <= MAX_V; k += i) {
                prime[k] = false;
            }
        }
    }

    // Set prime[0] and prime[1] to false as they are not prime numbers
    prime[0] = false;
    prime[1] = false;

    // Initialize a counter 'count' for the number of test cases
    int count = 0;
    int n;

    // Read input test cases until end of file is reached
    while (cin >> n) {
        // Increment the counter for each test case
        count++;

        // Initialize a counter 'cnt' to count the number of prime digits in n
        int cnt = 0;

        // Iterate through each digit of n and count the number of prime digits
        while (n > 0) {
            int digit = n % 10; // Get the last digit
            if (prime[digit]) {
                cnt++; // Increment the counter if the digit is prime
            }
            n /= 10; // Remove the last digit
        }

        // Print the result for the current test case
        cout << cnt << endl;

        // Break the loop if the required number of test cases have been processed
        if (count == 30) break;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
