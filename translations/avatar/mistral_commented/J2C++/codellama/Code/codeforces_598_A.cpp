
#include <iostream>
#include <cmath>

using namespace std ;

int main ( ) {

    int q ; // Declaring the integer variable 'q'

    long s ; // Declaring the long variable 's'

    int x ; // Declaring the integer variable 'x'

    int n ; // Declaring the integer variable 'n'

    cin >> q ; // Reading the number of test cases from the console

    while ( q -- > 0 ) { // Starting a while loop that runs q times

        cin >> n ; // Reading the integer 'n' from the console

        x = ( int ) ( log ( n ) / log ( 2 ) ) ; // Calculating the integer 'x' using the logarithmic formula

        x ++ ; // Incrementing the value of 'x' by 1

        s = - 1 * ( long ) pow ( 2 , x ) + 2 + ( ( long ) n * ( long ) ( n + 1 ) ) / 2 - ( long ) pow ( 2 , x ) ; // Calculating the value of 's' using the given formula

        cout << s << endl ; // Printing the value of 's' to the console
    }

    return 0 ; // Returning 0 to the operating system
}

