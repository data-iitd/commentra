
#include <iostream>

int main() {
    int n;
    std::cin >> n;  // Take an integer input from the user
    std::cout << fibonacci(n) << std::endl;  // Print the nth Fibonacci number
    return 0;
}

int fibonacci(int n) {
    if (n <= 0) {  // Return 0 for non-positive input
        return 0;
    } else if (n == 1) {  // Return 1 for input of 1
        return 1;
    } else {
        int a = 0, b = 1;  // Initialize the first two Fibonacci numbers
        for (int i = 2; i <= n; i++) {  // Loop from 2 to n
            int c = b;  // Store the current value of b
            b = a + b;  // Update the value of b
            a = c;  // Update the value of a
        }
        return b;  // Return the nth Fibonacci number
    }
}

