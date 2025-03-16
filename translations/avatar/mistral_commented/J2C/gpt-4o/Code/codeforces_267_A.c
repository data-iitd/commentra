#include <stdio.h> // Including standard input-output library

// Function to perform the subtraction operation
int sub(int a, int b) {
    int min = (a < b) ? a : b; // Finding the smaller number
    int max = (a > b) ? a : b; // Finding the larger number
    int result = 0; // Initializing the result variable

    while (min > 0) { // Iterating as long as the smaller number is greater than zero
        result += max / min; // Adding the quotient of the larger number divided by the smaller number to the result
        max = max % min; // Updating the larger number by taking the remainder of the larger number with the smaller number
        int curr_min = (min < max) ? min : max; // Finding the current smaller number
        int curr_max = (min > max) ? min : max; // Finding the current larger number
        min = curr_min; // Updating the smaller number
        max = curr_max; // Updating the larger number
    }

    return result; // Returning the final result
}

int main() { // Defining the main function
    int n; // Variable to store the number of test cases
    scanf("%d", &n); // Reading the number of test cases from the user

    for (int i = 0; i < n; i++) { // Iterating through each test case
        int a, b; // Variables to store the two numbers
        scanf("%d %d", &a, &b); // Reading the two numbers from the user
        printf("%d\n", sub(a, b)); // Printing the result of subtracting 'b' from 'a'
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
