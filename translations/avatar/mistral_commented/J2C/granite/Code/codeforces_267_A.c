
#include <stdio.h> // Include the standard input/output library

int sub ( int a, int b ) { // Define the sub function for subtracting two numbers
    int min = ( a < b )? a : b ; // Find the smaller number
    int max = ( a > b )? a : b ; // Find the larger number
    int result = 0 ; // Initialize the result variable

    while ( min > 0 ) { // Iterate as long as the smaller number is greater than zero
        result += max / min ; // Add the quotient of the larger number divided by the smaller number to the result
        max = max % min ; // Update the larger number by taking the remainder of the larger number with the smaller number
        int curr_min = ( min < max )? min : max ; // Find the current smaller number
        int curr_max = ( min > max )? min : max ; // Find the current larger number
        min = curr_min ; // Update the smaller number
        max = curr_max ; // Update the larger number
    }

    return result ; // Return the final result
}

int main ( ) { // Define the main function
    int n ; // Declare the variable for the number of test cases
    scanf ( "%d", &n ) ; // Read the number of test cases from the user

    for ( int i = 0 ; i < n ; i ++ ) { // Iterate through each test case
        int a, b ; // Declare the variables for the two numbers
        scanf ( "%d %d", &a, &b ) ; // Read the two numbers from the user
        printf ( "%d\n", sub ( a, b ) ) ; // Print the result of subtracting 'b' from 'a'
    }

    return 0 ; // Return 0 to indicate successful execution
}

