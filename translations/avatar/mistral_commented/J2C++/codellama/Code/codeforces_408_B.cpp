
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std ;

bool isValid ( string s1 , string s2 ) { // Check if the given strings are valid
    int n1 = s1.length ( ) ; // Get the length of the first string
    int n2 = s2.length ( ) ; // Get the length of the second string

    map < char , bool > map ; // Create a map to store the presence of characters in the first string

    for ( char c : s1 ) { // Iterate through each character in the first string
        map [ c ] = true ; // Mark the character as present in the map
    }

    for ( char c : s2 ) { // Iterate through each character in the second string
        if ( ! map [ c ] ) { // If the character is not present in the first string, return false
            return false ;
        }
    }

    return true ; // If all characters in the second string are present in the first string, return true
}

int main ( ) {
    string s1 , s2 ; // Declare two strings

    cin >> s1 >> s2 ; // Read the first string from the input

    if ( isValid ( s1 , s2 ) == false ) { // Check if the given strings are valid
        cout << - 1 << endl ; // If not valid, print -1 and exit
    } else { // If the strings are valid, proceed with the computation
        map < char , int > m1 , m2 ; // Create two maps to store the frequency of characters in the first and second strings

        for ( char c : s1 ) { // Iterate through each character in the first string
            m1 [ c ] ++ ; // Increment the count of the character in the first string
        }

        for ( char c : s2 ) { // Iterate through each character in the second string
            m2 [ c ] ++ ; // Increment the count of the character in the second string
        }

        int ans = 0 ; // Initialize the answer variable to 0
        set < char > hs ; // Create a set to store unique characters in the second string

        for ( char c : s2 ) { // Iterate through each character in the second string
            if ( hs.find ( c ) == hs.end ( ) ) { // If the character is not already in the set, add it and compute the answer
                hs.insert ( c ) ;
                int x1 = m1 [ c ] ; // Get the count of the character in the first string
                int x2 = m2 [ c ] ; // Get the count of the character in the second string
                x1 = min ( x1 , x2 ) ; // Take the minimum count
                ans += x1 ; // Add the minimum count to the answer
            }
        }

        cout << ans << endl ; // Print the answer
    }

    return 0 ;
}

