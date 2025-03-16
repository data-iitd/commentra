
#include <bits/stdc++.h> // Include the necessary header files

using namespace std; // Using the standard namespace

int main() { // Starting the main function
    try { // Starting a try block for handling exceptions
        long long n; // Declaring a long long integer variable for storing the input value
        cin >> n; // Reading the input value from the user

        // Calculating the square root of the given number
        int sqrt = sqrt(n);

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
                answer++; // Incrementing the answer variable
            }
        }

        // Checking for the remaining prime factor (if any)
        if (n > 1) {
            answer++; // Incrementing the answer variable
        }

        // Printing the result
        cout << answer << endl; // Printing the result to the console

    } catch (exception &e) { // Catching any exceptions that might occur during the execution
        cout << "Error: " << e.what() << endl; // Printing an error message if an exception occurs
    }

    return 0; // Returning 0 to indicate successful execution of the program
}

