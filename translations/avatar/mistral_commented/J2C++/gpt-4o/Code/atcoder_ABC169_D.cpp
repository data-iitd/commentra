#include <iostream> // Including the iostream library for input and output
#include <cmath> // Including the cmath library for mathematical functions

using namespace std; // Using the standard namespace

int main() { // Starting the main function
    try { // Starting a try block for handling exceptions
        long long n; // Declaring a long long variable for user input
        cin >> n; // Reading a long integer value from user input

        // Calculating the square root of the given number
        int sqrt_n = static_cast<int>(sqrt(n));

        // Initializing the answer variable to 0
        int answer = 0;

        // Checking for prime factors of the given number
        for (int i = 2; i <= sqrt_n; i++) { // Starting a for loop to check for prime factors
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
        cout << answer << endl;

    } catch (const exception& e) { // Catching any exceptions that might occur during the execution
        cout << "Error: " << e.what() << endl;
    }

    return 0; // Returning 0 to indicate successful execution
} // End of main function
// <END-OF-CODE>
