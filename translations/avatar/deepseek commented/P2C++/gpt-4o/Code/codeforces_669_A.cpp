#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Take an integer input from the user
    cout << (n * 2 + 1) / 3 << endl;  // Perform a calculation and print the result

    // Function to calculate factorial
    auto factorial = [](int n) {
        if (n == 0)  // Base case: factorial of 0 is 1
            return 1;
        else
            return n * factorial(n - 1);  // Recursive case
    };

    int number;
    cin >> number;  // Take an integer input from the user
    int result = factorial(number);  // Calculate the factorial of the input number
    cout << result << endl;  // Print the result

    // Function to calculate Fibonacci number
    auto fibonacci = [](int n) {
        if (n <= 0)  // Return 0 for non-positive input
            return 0;
        else if (n == 1)  // Return 1 for input of 1
            return 1;
        else {
            int a = 0, b = 1;  // Initialize the first two Fibonacci numbers
            for (int i = 2; i <= n; ++i) {  // Loop from 2 to n
                int temp = b;  // Store the current Fibonacci number
                b = a + b;  // Update b to the next Fibonacci number
                a = temp;  // Update a to the previous Fibonacci number
            }
            return b;  // Return the nth Fibonacci number
        }
    };

    int index;
    cin >> index;  // Take an integer input from the user
    cout << fibonacci(index) << endl;  // Print the nth Fibonacci number

    return 0;
}

// <END-OF-CODE>
