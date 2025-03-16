
#include <iostream>
using namespace std ;

int main ( ) {
    int n ; // Declaring a variable n of type integer
    cin >> n ; // Reading an integer input from the user and storing it in variable n
    solve ( n ) ; // Calling the solve method with the input value n
    return 0 ;
}

void solve ( int n ) {
    // Calculating the result based on the given logic
    cout << ( n / 3 ) * 2 + ( n % 3 == 0 ? 0 : 1 ) << endl ; // Printing the result to the console
}

