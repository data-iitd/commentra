
#include <stdio.h> // Include the standard input/output library

int main ( void ) {
    int N ; // Declare an integer variable 'N' to store the input integer value
    scanf ( "%d", &N ) ; // Read the input integer value from the standard input stream and assign it to the variable 'N'

    int count = 0 ; // Initialize the counter variable 'count' to zero
    int temp = N ; // Assign the value of 'N' to the variable 'temp'

    // The following while loop calculates the number of digits in the given integer 'N'
    while ( temp > 0 ) {
        temp /= 10 ; // Divide the current value of 'temp' by 10 to get the last digit
        count ++ ; // Increment the counter variable 'count' by 1
    }

    int ans = 0 ; // Initialize the variable 'ans' to store the final answer
    for ( int i = 1 ; i <= count ; i ++ ) { // The following for loop iterates through each digit of the given integer 'N'
        if ( i == count ) { // If the current digit is the last digit
            if ( i % 2 == 1 ) { // If the last digit is odd
                ans += ( N - pow ( 10, i - 1 ) + 1 ) ; // Add the sum of digits before the last odd digit to the answer
            }
        } else { // If the current digit is not the last digit
            if ( i == 1 ) { // If the current digit is the first digit
                ans += 9 ; // Add the number of digits after the first digit to the answer
            } else if ( i % 2 == 1 ) { // If the current digit is odd
                ans += ( pow ( 10, i ) - pow ( 10, i - 1 ) ) ; // Add the difference between the 10 raised to the power of the current digit and the 10 raised to the power of the previous digit to the answer
            }
        }
    }

    printf ( "%d", ans ) ; // Print the final answer to the standard output stream

    return 0 ; // Return 0 to indicate successful execution of the program
}

