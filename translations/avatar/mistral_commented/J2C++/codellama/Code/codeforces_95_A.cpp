
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std ;

int main ( ) {
    int n ; // Declaring the number of character arrays to be processed
    cin >> n ; // Reading the number of character arrays to be processed

    char [ ] [ ] ss ; // Declaring a 2D array to store the character arrays
    ss = new char [ n ] [ ] ; // Creating a 2D array to store the character arrays

    // Reading the character arrays and storing them in the 2D array
    for ( int i = 0 ; i < n ; i ++ ) {
        ss [ i ] = new char [ 100 ] ;
        cin >> ss [ i ] ;
    }

    char [ ] cc ; // Declaring a character array to store the character array to be compared with the input character arrays
    cin >> cc ; // Reading the character array to be compared with the input character arrays
    int m = strlen ( cc ) ; // Finding the length of the character array cc

    char c ; // Declaring a character to store the character to be matched with the character array cc
    cin >> c ; // Reading the character to be matched with the character array cc
    char c_ = toupper ( c ) ; // Converting the character to uppercase
    char a = c == 'a' ? 'b' : 'a' ; // Determining the character a based on the character c
    char a_ = toupper ( a ) ; // Converting the character a to uppercase

    bool [ ] lucky ; // Declaring a boolean array to keep track of the matching indices in cc
    lucky = new bool [ m ] ; // Creating a boolean array to keep track of the matching indices in cc

    // Iterating through each character in cc and comparing it with all characters in each character array in ss
    for ( int j = 0 ; j < m ; j ++ ) {
        for ( int i = 0 ; i < n ; i ++ ) {
            int l = strlen ( ss [ i ] ) ; // Finding the length of the character array in ss at the current index i

            if ( m - j >= l && strncmp ( cc + j , ss [ i ] , l ) == 0 ) { // If the length of cc minus the current index j is greater than or equal to the length of the character array in ss at the current index i, and if the comparison of the substrings starting from the current indices in cc and ss returns 0, then set the boolean value at the current index j in lucky to true
                for ( int h = 0 ; h < l ; h ++ ) { // Iterating through each character in the character array in ss at the current index i
                    lucky [ j + h ] = true ; // Setting the boolean value at the current index j+h in lucky to true
                }
            }
        }
    }

    // Iterating through each character in cc and updating it based on the boolean values in lucky
    for ( int j = 0 ; j < m ; j ++ ) {
        if ( lucky [ j ] ) { // If the boolean value at the current index j in lucky is true
            if ( tolower ( cc [ j ] ) == c ) { // If the character at the current index j in cc is equal to the character c in lowercase
                cc [ j ] = isupper ( cc [ j ] ) ? a_ : a ; // Update the character at the current index j in cc based on the character a
            } else {
                cc [ j ] = isupper ( cc [ j ] ) ? c_ : c ; // Update the character at the current index j in cc based on the character c
            }
        }
    }

    // Printing the updated character array cc
    cout << cc << endl ;

    return 0 ;
}

