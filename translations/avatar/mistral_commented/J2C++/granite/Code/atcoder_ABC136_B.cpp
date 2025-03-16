
#include <iostream> // Including the standard input/output stream objects iostream and using namespace std

using namespace std ; // Using the standard namespace

int main ( ) {
    int N ; // Declaring an integer variable 'N' to store the input value
    cin >> N ; // Reading the first integer value from the standard input stream and assigning it to the variable 'N'

    int count = 0 ; // Initializing the counter variable 'count' to zero
    int temp = N ; // Assigning the value of 'N' to the variable 'temp'

    // The following while loop calculates the number of digits in the given integer 'N'
    while ( temp > 0 ) {
        temp /= 10 ; // Dividing the current value of 'temp' by 10 to get the last digit
        count ++ ; // Incrementing the counter variable 'count' by 1
    }

    int ans = 0 ; // Declaring an integer variable 'ans' to store the final answer

    for ( int i = 1 ; i <= count ; i ++ ) { // The following for loop iterates through each digit of the given integer 'N'
        if ( i == count ) { // If the current digit is the last digit
            if ( i % 2 == 1 ) { // If the last digit is odd
                ans += ( N - pow ( 10, i - 1 ) + 1 ) ; // Adding the sum of digits before the last odd digit to the answer
            }
        } else { // If the current digit is not the last digit
            if ( i == 1 ) { // If the current digit is the first digit
                ans += 9 ; // Adding the number of digits after the first digit to the answer
            } else if ( i % 2 == 1 ) { // If the current digit is odd
                ans += ( pow ( 10, i ) - pow ( 10, i - 1 ) ) ; // Adding the difference between the 10 raised to the power of the current digit and the 10 raised to the power of the previous digit to the answer
            }
        }
    }

    cout << ans ; // Printing the final answer to the standard output stream

    return 0 ; // Returning 0 to indicate successful program execution
}

