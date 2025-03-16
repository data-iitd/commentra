

#include <stdio.h>

int main() {
    int a; // Declare and initialize variable 'a' to store first user input
    int b; // Declare and initialize variable 'b' to store second user input
    int result; // Declare variable'result' to store the result of the computation

    scanf("%d", &a); // Read the first integer value from the user
    scanf("%d", &b); // Read the second integer value from the user

    if (a > b) { // Check if 'a' is greater than 'b'
        result = 2 * a - 1; // If true, assign the value '2 * a - 1' to'result'
    } else if (a == b) { // Check if 'a' is equal to 'b'
        result = 2 * a; // If true, assign the value '2 * a' to'result'
    } else { // If 'a' is less than 'b'
        result = 2 * b - 1; // Assign the value '2 * b - 1' to'result'
    }

    printf("%d\n", result); // Print the value of'result' to the console

    return 0; // Terminate the program with a return value of 0
}

