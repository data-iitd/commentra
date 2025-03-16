#include <stdio.h>

// Function to calculate (n * 2 + 1) // 3
int calculate(int n) {
    return (n * 2 + 1) / 3;
}

// Function to calculate factorial
long long factorial(int n) {
    if (n == 0) {  // Base case: factorial of 0 is 1
        return 1;
    } else {
        return n * factorial(n - 1);  // Recursive case
    }
}

// Function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n <= 0) {  // Return 0 for non-positive input
        return 0;
    } else if (n == 1) {  // Return 1 for input of 1
        return 1;
    } else {
        int a = 0, b = 1;  // Initialize the first two Fibonacci numbers
        for (int i = 2; i <= n; i++) {  // Loop from 2 to n
            int temp = b;  // Store the current Fibonacci number
            b = a + b;  // Update b to the next Fibonacci number
            a = temp;  // Update a to the previous Fibonacci number
        }
        return b;  // Return the nth Fibonacci number
    }
}

int main() {
    int n;

    // Take an integer input for the first calculation
    printf("Enter an integer for calculation: ");
    scanf("%d", &n);
    printf("%d\n", calculate(n));  // Perform the calculation and print the result

    // Take an integer input for factorial calculation
    printf("Enter an integer for factorial: ");
    scanf("%d", &n);
    printf("%lld\n", factorial(n));  // Calculate the factorial and print the result

    // Take an integer input for Fibonacci calculation
    printf("Enter an integer for Fibonacci: ");
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));  // Print the nth Fibonacci number

    return 0;
}

// <END-OF-CODE>
