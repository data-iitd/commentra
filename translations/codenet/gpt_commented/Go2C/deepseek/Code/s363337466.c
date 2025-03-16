#include <stdio.h>
#include <math.h>

// walkOnMultiplicationTable calculates a specific value based on the input number.
// It finds the largest divisor of the number that is less than the square root of the number.
int walkOnMultiplicationTable(int num) {
    // Initialize a variable to store the largest divisor found
    int div = 0;

    // Iterate from the largest integer less than or equal to the square root of num down to 2
    for (int i = (int)sqrt(num); i > 1; i--) {
        // Check if i is a divisor of num
        if (num % i == 0) {
            div = i; // Store the divisor
            break;   // Exit the loop once the largest divisor is found
        }
    }

    // If no divisor was found, return num - 1 (indicating num is prime)
    if (div == 0) {
        return num - 1;
    }

    // Calculate and return the result based on the found divisor
    return div + num / div - 2;
}

int main() {
    // Declare a variable to hold user input
    int a;

    // Read an integer from standard input
    scanf("%d", &a);

    // Call the walkOnMultiplicationTable function and print the result
    printf("%d\n", walkOnMultiplicationTable(a));

    return 0;
}
