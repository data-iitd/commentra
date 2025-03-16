

#include <stdio.h>

int factorial(int n) {
    if (n == 0) {  // Base case: factorial of 0 is 1
        return 1;
    } else {
        return n * factorial(n - 1);  // Recursive case: n * factorial of (n - 1)
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);  // Take an integer input from the user
    int result = factorial(number);  // Calculate the factorial of the input number
    printf("Factorial of %d is %d\n", number, result);  // Print the result
    return 0;
}

