#include <iostream>
#include <cmath>

using namespace std ;

int main ( ) {
    int N ; // Declaring the variable 'N' to store the integer value
    int count = 0 ; // Declaring the variable 'count' to store the number of digits in the given integer 'N'
    int temp ; // Declaring the variable 'temp' to store the value of 'N'
    int ans = 0 ; // Declaring the variable 'ans' to store the final answer

    cin >> N ; // Reading the first integer value from the standard input stream and assigning it to the variable 'N'

    temp = N ; // Assigning the value of 'N' to the variable 'temp'

    // The following while loop calculates the number of digits in the given integer 'N'
    while ( temp > 0 ) {
        temp /= 10 ; // Dividing the current value of 'temp' by 10 to get the last digit
        count ++ ; // Incrementing the counter variable 'count' by 1
    }

    for ( int i = 1 ; i <= count ; i ++ ) { // The following for loop iterates through each digit of the given integer 'N'
        if ( i == count ) { // If the current digit is the last digit
            if ( i % 2 == 1 ) { // If the last digit is odd
                ans += ( N - pow ( 10 , i - 1 ) + 1 ) ; // Adding the sum of digits before the last odd digit to the answer
            }
        } else { // If the current digit is not the last digit
            if ( i == 1 ) { // If the current digit is the first digit
                ans += 9 ; // Adding the number of digits after the first digit to the answer
            } else if ( i % 2 == 1 ) { // If the current digit is odd
                ans += ( pow ( 10 , i ) - pow ( 10 , i - 1 ) ) ; // Adding the difference between the 10 raised to the power of the current digit and the 10 raised to the power of the previous digit to the answer
            }
        }
    }

    cout << ans << endl ; // Printing the final answer to the standard output stream

    return 0 ; // Returning 0 to indicate that the program executed successfully
}

