
#include <bits/stdc++.h>
using namespace std;

class Main {
public:
    // Constructor for creating an instance of Main class and setting output stream to System.out
    Main ( ) {
        ios_base :: sync_with_stdio ( false ) ;
        cin.tie ( 0 ) ;
        cout.tie ( 0 ) ;
    }

    int main ( ) {
        int n ; // Number of character arrays to be processed
        cin >> n ;

        char [ ] [ ] ss = new char [ n ] [ ] ; // Creating a 2D array to store the character arrays

        // Reading the character arrays and storing them in the 2D array
        for ( int i = 0 ; i < n ; i ++ ) {
            cin >> ss [ i ] ;
        }

        char [ ] cc = new char [ 1000001 ] ; // Creating a character array to store the character array to be compared with the input character arrays
        cin >> cc ; // Reading the character array to be compared with the input character arrays
        int m = strlen ( cc ) ; // Finding the length of the character array cc

        char c ; // Character to be matched with the character array cc
        cin >> c ;
        char c_ = toupper ( c ) ; // Converting the character to uppercase
        char a = c == 'a'? 'b' : 'a' ; // Determining the character a based on the character c
        char a_ = toupper ( a ) ; // Converting the character a to uppercase

        bool [ ] lucky = new bool [ m ] ; // Creating a boolean array to keep track of the matching indices in cc

        // Iterating through each character in cc and comparing it with all characters in each character array in ss
        for ( int j = 0 ; j < m ; j ++ ) {
            for ( int i = 0 ; i < n ; i ++ ) {
                int l = strlen ( ss [ i ] ) ; // Finding the length of the character array in ss at the current index i

                if ( m - j >= l && strcmp ( cc + j, ss [ i ] ) == 0 ) { // If the length of cc minus the current index j is greater than or equal to the length of the character array in ss at the current index i, and if the comparison of the substrings starting from the current indices in cc and ss returns 0, then set the boolean value at the current index j in lucky to true
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
                    cc [ j ] = isupper ( cc [ j ] )? a_ : a ; // Update the character at the current index j in cc based on the character a
                } else {
                    cc [ j ] = isupper ( cc [ j ] )? c_ : c ; // Update the character at the current index j in cc based on the character c
                }
            }
        }

        // Printing the updated character array cc
        cout << cc << endl ;
    }
} ;

// 