#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Take an integer input from the user
    cout << (n * 2 + 1) / 3 << endl;  // Perform a calculation and print the result
    return 0;
}

void factorial(int n) {
    if (n == 0) {  // Base case: factorial of 0 is 1
        cout << 1 << endl;
    } else {
        cout << n * factorial(n - 1) << endl;  // Recursive case: n * factorial of (n - 1)
    }
}

int number;
cin >> number;  // Take an integer input from the user
factorial(number);  // Calculate the factorial of the input number






void fibonacci(int n) {
    if (n <= 0) {  // Return 0 for non-positive input
        cout << 0 << endl;
    } else if (n == 1) {  // Return 1 for input of 1
        cout << 1 << endl;
    } else {
        int a = 0, b = 1;  // Initialize the first two Fibonacci numbers
        for (int i = 2; i <= n; i++) {  // Loop from 2 to n
            int temp = b;
            b = a + b;  // Update the values of a and b
            a = temp;
        }
        cout << b << endl;  // Return the nth Fibonacci number
    }
}

int index;
cin >> index;  // Take an integer input from the user
fibonacci(index);  // Print the nth Fibonacci number
