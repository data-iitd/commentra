#include <iostream>
#include <cmath>

int main() {
    try {
        long n;
        std::cin >> n;

        // Calculating the square root of the given number
        int sqrt = static_cast<int>(std::sqrt(n));

        // Initializing the answer variable to 0
        int answer = 0;

        // Checking for prime factors of the given number
        for (int i = 2; i <= sqrt; i++) { // Starting a for loop to check for prime factors
            int count = 0; // Initializing a counter variable to count the number of occurrences of a prime factor
            while (n % i == 0) { // Checking if the given number is divisible by the current prime factor
                n /= i; // Dividing the given number by the current prime factor
                count++; // Incrementing the counter variable
            }

            // Calculating the contribution of the current prime factor to the answer
            for (int j = 1; count - j >= 0; j++) {
                count -= j;
                answer++;
            }
        }

        // Checking for the remaining prime factor (if any)
        if (n > 1) {
            answer++;
        }

        // Printing the result
        std::cout << answer << std::endl;

    } catch (const std::exception& e) { // Catching any exceptions that might occur during the execution
        std::cerr << "Error: " << e.what() << std::endl;
    }

