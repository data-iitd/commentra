
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std ;

int main ( ) {
    int num = 998244353 ;  // Initializing a variable 'num' with a value
    string line ;  // Creating a string variable to store the input line
    vector < int > ai ;  // Creating an empty vector to store the first array elements
    vector < int > bi ;  // Creating an empty vector to store the second array elements

    int n ;  // Creating an integer variable to store the number of test cases
    cin >> n ;  // Reading the number of test cases from the input

    for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through the test cases
        stringstream ss ;  // Creating a stringstream object to parse the input line
        getline ( cin , line ) ;  // Reading the input line from the standard input stream
        ss << line ;  // Parsing the input line
        int a , b ;  // Creating two integer variables to store the first and second array elements
        ss >> a >> b ;  // Reading the first and second array elements from the stringstream object
        ai.push_back ( a ) ;  // Adding the first array element to the vector
        bi.push_back ( b ) ;  // Adding the second array element to the vector
    }

    // Sorting the vectors in ascending order
    sort ( ai.begin ( ) , ai.end ( ) ) ;
    sort ( bi.begin ( ) , bi.end ( ) ) ;

    if ( n % 2 == 1 ) {  // Checking if the number of test cases is odd
        cout << bi [ bi.size ( ) / 2 ] - ai [ ai.size ( ) / 2 ] + 1 << endl ;  // Calculating and printing the answer for odd number of test cases
    } else {
        double b = ( ai [ ai.size ( ) / 2 ] + ai [ ai.size ( ) / 2 - 1 ] + 0.0 ) / 2 ;  // Calculating the average of the middle two elements of the first vector
        double c = ( bi [ bi.size ( ) / 2 ] + bi [ bi.size ( ) / 2 - 1 ] + 0.0 ) / 2 ;  // Calculating the average of the middle two elements of the second vector
        cout << ( int ) ( 2 * ( c - b ) + 1 ) << endl ;  // Calculating and printing the answer for even number of test cases
    }

    return 0 ;  // Returning 0 to indicate successful execution
}

