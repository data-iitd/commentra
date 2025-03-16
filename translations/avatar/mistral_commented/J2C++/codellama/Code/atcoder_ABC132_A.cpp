
#include <iostream>
#include <string>
#include <map>

using namespace std ;

int main ( ) {
    string s ; // Declaring a string variable to store the input string
    cin >> s ; // Reading a string input from user

    map < char , int > m ; // Declaring an empty map to store character and their frequency

    for ( int i = 0 ; i < s.length ( ) ; i ++ ) { // Iterating through each character in the string
        char currentChar = s [ i ] ; // Assigning the current character to a variable

        if ( m.find ( currentChar ) == m.end ( ) ) { // Checking if the current character is already present in the map
            m [ currentChar ] = 1 ; // If not present, adding the current character with frequency 1 to the map
        } else {
            m [ currentChar ] ++ ; // If present, incrementing the frequency of the current character in the map
        }
    }

    bool ok = true ; // Initializing a boolean variable to check if all characters have frequency 2 or not

    for ( auto c : m ) { // Iterating through each entry in the map
        char key = c.first ; // Assigning the character to a variable
        int value = c.second ; // Assigning the frequency to a variable

        if ( value != 2 ) { // Checking if the frequency of the current character is not 2
            ok = false ; // Setting the boolean variable to false if any character has frequency other than 2
            break ; // Exiting the loop if any character has frequency other than 2
        }
    }

    if ( ok && m.size ( ) == 2 ) { // Checking if all characters have frequency 2 and the size of the map is 2
        cout << "Yes" << endl ; // Printing "Yes" if both conditions are true
    } else {
        cout << "No" << endl ; // Printing "No" if any character has frequency other than 2 or the size of the map is not 2
    }

    return 0 ;
}

