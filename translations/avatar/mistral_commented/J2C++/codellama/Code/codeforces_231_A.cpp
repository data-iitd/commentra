#include <iostream>
using namespace std ;

int main ( ) {
    int t ; // Read the number of test cases from the standard input
    int count = 0 ; // Initialize a counter variable to keep track of the number of valid cases

    // Read the number of test cases and process each one in the while loop
    while ( t -- > 0 ) {
        int a, b, c ; // Declare three integer variables to store the input values
        cin >> a >> b >> c ; // Read the three integers from the standard input

        // Check if any of the given integers are equal to 1. If so, increment the counter.
        if ( ( a == 1 && b == 1 ) || ( a == 1 && c == 1 ) || ( b == 1 && c == 1 ) || ( a == 1 && b == 1 && c == 1 ) ) {
            count ++ ; // Increment the counter if any of the given integers are equal to 1
        }
    }

    // Print the value of the counter to the standard output
    cout << count << endl ;

    return 0 ;
}

