

#include <stdio.h>

int main ( ) {
    int n ; // Declaring an integer variable n
    scanf ( "%d", & n ) ; // Reading an integer input from the user and storing it in variable n
    solve ( n ) ; // Calling the solve function with the input value n
    return 0 ; // Returning 0 to indicate successful execution of the program
}

void solve ( int n ) {
    // Calculating the result based on the given logic
    printf ( "%d", ( n / 3 ) * 2 + ( n % 3 == 0? 0 : 1 ) ) ; // Printing the result to the console
}

// END-OF-CODE