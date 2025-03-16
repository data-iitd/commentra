
#include <iostream>
#include <string>
#include <cmath>

using namespace std ; 

int main ( ) { 
    // Read input string from the user
    string str ; 
    cin >> str ; 

    // Find the index of the dot ('.') in the string
    int dotIndex = 0 ; 
    for ( int i = 0 ; i < str.length ( ) ; i ++ ) 
        if ( str [ i ] == '.' ) { 
            dotIndex = i ; 
            break ; 
        } 

    // Check if the character before the dot is '9'
    if ( str [ dotIndex - 1 ] == '9' ) { 
        cout << "GOTO Vasilisa." << endl ; 
    } 
    // If the character before the dot is not '9', check the digit after the dot
    else if ( str [ dotIndex + 1 ] > '4' ) { 
        // Increment the number before the dot by 1 and print the result
        string _str = "" ; 
        for ( int i = 0 ; i < dotIndex ; i ++ ) 
            _str += str [ i ] ; 
        cout << to_string ( stoll ( _str ) + 1 ) << endl ; 
    } 
    // If the digit after the dot is 4 or less, print the number before the dot without any changes
    else { 
        for ( int i = 0 ; i < dotIndex ; i ++ ) 
            cout << str [ i ] ; 
        cout << endl ; 
    } 
} 

