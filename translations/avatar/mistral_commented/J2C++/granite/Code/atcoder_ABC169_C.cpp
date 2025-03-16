

#include <iostream> // Including standard input/output stream objects
#include <string> // Including string class
#include <cstdlib> // Including C++ standard library functions

using namespace std;

int main ( ) {
    // Initializing string variable 'a'
    string a ;

    // Reading string value from the console and assigning it to 'a'
    getline ( cin, a ) ;

    // Declaring and initializing string variable 'b'
    string b ;

    // Reading string value from the console and assigning it to 'b'
    getline ( cin, b ) ;

    // Declaring and initializing string variable 'bStr'
    string bStr = "" ;

    // Loop to iterate through each character in string 'b'
    for ( int i = 0 ; i < b.length ( ) ; i ++ ) {
        // If current character is not '.', add it to string 'bStr'
        if ( b [ i ]!= '.' ) {
            bStr += b [ i ] ;
        }
    }

    // Declaring and initializing integer variable 'bInt'
    int bInt = stoi ( bStr ) ; // Converting string 'bStr' to integer and assigning it to 'bInt'

    // Declaring and initializing long variable'result'
    long result = ( stol ( a ) * bInt ) / 100 ; // Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to'result'

    // Printing the value of'result' to the console
    cout << result << endl ;

    return 0 ; // Returning 0 to indicate successful program execution
}

