
#include <iostream> // Importing theiostream library
#include <string> // Importing the string library

using namespace std ; // Using the standard namespace

int main ( ) {
    int n ; // Declaring an integer variable to store the input
    cin >> n ; // Reading an integer input
    
    string s = "" ; // Initializing an empty string to store binary representation
    
    // Converting the integer to binary representation
    while ( n > 0 ) {
        int x = n % 2 ; // Getting the remainder when divided by 2
        n /= 2 ; // Dividing the number by 2
        s += to_string ( x ) ; // Appending the remainder to the string
    }
    
    int ans = 0 ; // Initializing a variable to count the number of '1's
    
    // Counting the number of '1's in the binary representation
    for ( int i = 0 ; i < s.length ( ) ; i ++ ) {
        if ( s [ i ] == '1' ) {
            ans ++ ; // Incrementing the count if the character is '1'
        }
    }
    
    cout << ans << endl ; // Printing the count of '1's
    
    return 0 ; // Returning 0 to indicate successful execution
}

