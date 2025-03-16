#include <iostream>
#include <cstdlib>

using namespace std ;

int main ( ) {
    // Main method is the entry point of the C++ application
    // It has a void return type and no parameters
    // We are using the standard input and output streams to read and write data

    int n ;
    // Declaring and initializing an integer variable 'n'

    cin >> n ;
    // Reading the number of test cases (n) from the standard input using the >> operator

    int a = 0 , b = 0 , c = 0 ;
    // Declaring and initializing three integer variables a, b, and c with zero values

    for ( int i = 0 ; i < n ; i ++ ) {
        int x ;
        cin >> x ;
        a += x ;
    }
    // Using a for loop to read and sum up the first number in each test case using the >> operator
    // and adding it to the variable 'a'

    for ( int i = 0 ; i < n - 1 ; i ++ ) {
        int x ;
        cin >> x ;
        b += x ;
    }
    // Using a for loop to read and sum up the second number in each test case (except the last one) using the >> operator
    // and adding it to the variable 'b'

    for ( int i = 0 ; i < n - 2 ; i ++ ) {
        int x ;
        cin >> x ;
        c += x ;
    }
    // Using a for loop to read and sum up the third number in each test case (except the last two) using the >> operator
    // and adding it to the variable 'c'

    int x = a - b ;
    // Calculating the difference between the sum of the first and second number in each test case and storing it in a variable 'x'

    int y = b - c ;
    // Calculating the difference between the sum of the second and third number in each test case and storing it in a variable 'y'

    cout << x << endl ;
    cout << y << endl ;
    // Printing the values of 'x' and 'y' to the standard output using the << operator and endl

    return 0 ;
}

