#include <iostream>
#include <string>
using namespace std ;

int main ( ) {
    int n ; // Declaring an integer variable to store the input
    string s = "" ; // Declaring an empty string to store the binary representation
    
    // Reading the input
    cin >> n ;
    
    // Converting the integer to binary representation
    while ( n > 0 ) {
        int x = n % 2 ; // Getting the remainder when divided by 2
        n /= 2 ; // Dividing the number by 2
        s += x + "" ; // Appending the remainder to the string
    }
    
    int ans = 0 ; // Declaring a variable to count the number of '1's
    
    // Counting the number of '1's in the binary representation
    for ( int i = 0 ; i < s.length ( ) ; i ++ ) {
        if ( s.at ( i ) == '1' ) {
            ans ++ ; // Incrementing the count if the character is '1'
        }
    }
    
    cout << ans << endl ; // Printing the count of '1's
    
    return 0 ;
}

