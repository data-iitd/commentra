
#include <iostream>

using namespace std ;

int main ( ) {
    // Initialize a variable `T` with the value of 0
    int T = 0 ;

    // Initialize a variable `S` with the value of 0
    int S = 0 ;

    // Initialize a variable `q` with the value of 0
    int q = 0 ;

    // Initialize a variable `previous` with the value of 0
    long previous = 0 ;

    // Initialize a variable `answer` with the value of 0
    int answer = 0 ;

    // Read the first integer `T` from the standard input stream
    cin >> T ;

    // Read the second integer `S` from the standard input stream
    cin >> S ;

    // Read the third integer `q` from the standard input stream
    cin >> q ;

    // Initialize the variable `previous` with the value of `S`
    previous = S ;

    // Start a while loop that continues as long as `previous` is less than `T`
    while ( previous < T ) {
        // Increment the value of `answer` by 1
        answer ++ ;

        // Multiply the value of `previous` by `q`
        previous *= q ;
    }

    // Print the value of `answer` to the standard output stream
    cout << answer << endl ;

    // End the program
    return 0 ;
}

