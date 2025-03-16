
#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std ;

// Main method declaration
int main ( ) {
    string s ; // Declare a string to store the first input string
    string t ; // Declare a string to store the second input string
    int ura = 0 ; // Declare a counter for unique characters in the first string
    int opa = 0 ; // Declare a counter for opposite characters in the second string

    // Read the first input string from the console
    getline ( cin , s ) ;

    // Read the second input string from the console
    getline ( cin , t ) ;

    // Create a HashMap to store the frequency of each character in the second string
    map < char , int > tmap ;

    // Read the characters of the second string and store their frequencies in the HashMap
    for ( int i = 0 ; i < t.length ( ) ; i ++ ) {
        char ch = t [ i ] ;
        if ( tmap.find ( ch ) == tmap.end ( ) ) // If the character is not already in the HashMap
            tmap [ ch ] = 1 ; // Add it with a frequency of 1
        else
            tmap [ ch ] ++ ; // If the character is already in the HashMap, increment its frequency
    }

    // Process the first string
    int length = s.length ( ) ;
    for ( int i = 0 ; i < length ; i ++ ) {
        char ch = s [ i ] ;
        int num = tmap [ ch ] ;
        if ( num == 0 ) // If the character is not in the second string
            continue ;
        int inum = num ;
        if ( inum == 1 ) // If the character appears only once in the second string
            tmap.erase ( ch ) ; // Remove it from the HashMap
        else
            tmap [ ch ] = inum - 1 ; // If the character appears more than once in the second string, decrement its frequency
        s [ i ] = 'Я' ; // Replace the character in the string with 'Я'
        ura ++ ; // Increment the counter for unique characters
    }

    // Process the reversed version of the first string
    for ( int i = 0 ; i < length ; i ++ ) {
        char ch = s [ i ] ;
        char rch = reverse ( ch ) ; // Get the reverse character of the current character
        int num = tmap [ rch ] ;
        if ( num == 0 ) // If the reverse character is not in the second string
            continue ;
        int inum = num ;
        if ( inum == 1 ) // If the reverse character appears only once in the second string
            tmap.erase ( rch ) ; // Remove it from the HashMap
        else
            tmap [ rch ] = inum - 1 ; // If the reverse character appears more than once in the second string, decrement its frequency
        opa ++ ; // Increment the counter for opposite characters
    }

    // Print the results
    cout << ura << " " << opa << endl ;

    return 0 ;
}

// Reverse the given character
char reverse ( char ch ) {
    if ( islower ( ch ) ) { // If the character is lowercase
        return toupper ( ch ) ; // Return its uppercase version
    } else {
        return tolower ( ch ) ; // If the character is uppercase, return its lowercase version
    }
}

