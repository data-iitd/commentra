
#include <iostream>
#include <string>
#include <map>

using namespace std ;

int main ( ) {
    int N ;  // Declaring an integer variable to store the number of strings
    string next ;  // Declaring a string variable to store the next character of the current string
    bool ans = true ;  // Declaring a boolean variable to store the result of the check
    map < int , string > map ;  // Declaring an empty map to store strings
    map < int , string > past ;  // Declaring an empty map to store the previous strings

    cin >> N ;  // Reading the number of strings from the input

    for ( int i = 0 ; i < N ; i ++ ) {  // Loop to read strings from the input and store them in the map
        string temp ;
        cin >> temp ;
        map.insert ( make_pair ( i , temp ) ) ;
    }

    for ( int i = 0 ; i < N ; i ++ ) {  // Loop to check for the condition
        if ( past.find ( i ) != past.end ( ) ) {  // Checking if the current string is already in the map
            ans = false ;
            break ;
        }
        past.insert ( make_pair ( i , map.find ( i ) -> second ) ) ;  // Storing the current string in the map

        if ( i != 0 ) {  // Checking if it's not the first iteration of the loop
            if ( next != map.find ( i ) -> second.substr ( 0 , 1 ) ) {  // Checking if the current string starts with the same character as the previous string
                ans = false ;
                break ;
            }
        }
        next = map.find ( i ) -> second.substr ( map.find ( i ) -> second.length ( ) - 1 , map.find ( i ) -> second.length ( ) ) ;  // Storing the last character of the current string in the next variable
    }

    if ( ans ) {  // Printing "Yes" if the condition is satisfied
        cout << "Yes" << endl ;
    } else {  // Printing "No" if the condition is not satisfied
        cout << "No" << endl ;
    }

    return 0 ;
}

