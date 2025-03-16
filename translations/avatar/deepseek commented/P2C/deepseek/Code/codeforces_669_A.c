#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Take an integer input from the user
    printf("%d\n", (n * 2 + 1) / 3);  // Perform a calculation and print the result
    return 0;
}

int factorial(int n) {
    if (n == 0) {  // Base case: factorial of 0 is 1
        return 1;
    } else {
        return n * factorial(n - 1);  // Recursive case: n * factorial of (n - 1)
    }
}

int main() {
    int number;
    scanf("%d", &number);  // Take an integer input from the user
    int result = factorial(number);  // Calculate the factorial of the input number
    printf("%d\n", result);  // Print the result
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
            int temp = b;
            b = a + b;  // Update the values of a and b
            a = temp;
        }
        return b;  // Return the nth Fibonacci number
    }
}

int main() {
    int index;
    scanf("%d", &index);  // Take an integer input from the user
    printf("%d\n", fibonacci(index));  // Print the nth Fibonacci number
    return 0;
}
