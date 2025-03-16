#include <iostream>
#include <string>

using namespace std ; 

int main ( ) { 
    string s ; // Declare a string variable s
    int length ; // Declare an integer variable length
    char ch ; // Declare a character variable ch

    // Read a line of input from the user and store it in the string variable s
    getline ( cin , s ) ; 

    // Calculate the length of the string s and store it in the integer variable length
    length = s.length ( ) ; 

    // Initialize the character variable ch to 0
    ch = 0 ; 

    // Iterate through the string s in reverse order, starting from the last character
    for ( int i = length - 1 ; i >= 0 ; i -- ) { 
        // Check if the current character is not a space or a question mark
        if ( s [ i ] != ' ' && s [ i ] != '?' ) { 
            // Assign the current character to the variable ch
            ch = s [ i ] ; 
            break ; // Exit the loop
        } 
    }

    // Convert the character ch to lowercase
    ch = tolower ( ch ) ; 

    // Check if ch is one of the vowels (a, e, i, o, u, y)
    if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' ) { 
        // Print "YES" if ch is a vowel
        cout << "YES" << endl ; 
    } else { 
        // Print "NO" if ch is not a vowel
        cout << "NO" << endl ; 
    } 

    return 0 ; // Return 0 to indicate that the program executed successfully
}

