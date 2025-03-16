
#include <iostream>
#include <cmath>
#include <vector>

using namespace std ;

int main ( ) {
    int n ;  // Declaring the variable 'n' for the number
    int square ;  // Declaring the variable 'square' for the square of the number
    int loop ;  // Declaring the variable 'loop' for the number of pairs to be printed
    int div ;  // Declaring the variable 'div' for half of the number of pairs

    cin >> n ;  // Reading the number 'n' from the user

    square = pow ( n , 2 ) ;  // Calculating the square of the number 'n'

    vector < int > odd ;  // Creating an empty vector for odd numbers
    vector < int > even ;  // Creating an empty vector for even numbers

    for ( int i = 1 ; i <= square ; i ++ ) {  // Looping from 1 to square
        if ( i % 2 == 0 ) {  // If the number is even
            even.push_back ( i ) ;  // Add the number to the even vector
        } else {  // If the number is odd
            odd.push_back ( i ) ;  // Add the number to the odd vector
        }
    }

    loop = square / n ;  // Calculating the number of pairs to be printed
    div = loop / 2 ;  // Calculating half of the number of pairs

    for ( int i = 1 ; i <= loop ; i ++ ) {  // Looping through each pair
        for ( int j = 0 ; j < div ; j ++ ) {  // Looping through half of the pair
            if ( i % 2 == 1 ) {  // If the current pair is odd
                cout << odd.at ( 0 ) << " " << even.at ( even.size ( ) - 1 ) << " " ;  // Print the first and last numbers of the current pair
                odd.erase ( odd.begin ( ) ) ;  // Remove the first number from the odd vector
                even.erase ( even.end ( ) - 1 ) ;  // Remove the last number from the even vector
            } else {  // If the current pair is even
                cout << even.at ( 0 ) << " " << odd.at ( odd.size ( ) - 1 ) << " " ;  // Print the last and first numbers of the current pair
                even.erase ( even.begin ( ) ) ;  // Remove the first number from the even vector
                odd.erase ( odd.end ( ) - 1 ) ;  // Remove the last number from the odd vector
            }
        }
        cout << endl ;  // Printing a newline after each pair
    }

    return 0 ;  // Returning 0 to indicate that the program executed successfully
}

