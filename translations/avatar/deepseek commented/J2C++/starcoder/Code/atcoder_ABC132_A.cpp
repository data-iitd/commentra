
#include <bits/stdc++.h>
// Import necessary header files

using namespace std ;
// Initialize the standard namespace

int main ( ) { 
    string s ; 
    // Declare a string to store the input

    cin >> s ; 
    // Read the input string

    map < char, int > map ; 
    // Initialize a map to store character counts

    for ( int i = 0 ; i < s.length ( ) ; i ++ ) { 
        // Loop through each character in the string
        if ( map.find ( s [ i ] ) == map.end ( ) ) { 
            // If the character is not already in the map, add it with a count of 1
            map [ s [ i ] ] = 1 ; 
        } else { 
            // If the character is already in the map, increment its count
            map [ s [ i ] ] ++ ; 
        } 
    }

    bool ok = true ; 
    // Initialize a boolean flag to check the conditions

    for ( auto c : map ) { 
        // Loop through each entry in the map
        if ( c.second!= 2 ) { 
            // If any character count is not 2, set ok to false and break the loop
            ok = false ; 
            break ; 
        } 
    }

    if ( ok && map.size ( ) == 2 ) { 
        // Check if all characters appear exactly twice and there are exactly 2 unique characters
        cout << "Yes" << endl ; 
        // Print "Yes" if the conditions are met
    } else { 
        cout << "No" << endl ; 
        // Print "No" otherwise
    }

    return 0 ; 
}

