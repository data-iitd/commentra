#include <iostream>
#include <string>

using namespace std ;

int main ( ) {
    string word ;  // Declaring a string variable to store the input word
    int uppercase = 0 , lowercase = 0 ;  // Declaring two integer variables to store the count of uppercase and lowercase characters

    cin >> word ;  // Reading the first word as input from the user

    for ( int i = 0 ; i < word.length ( ) ; i ++ ) {  // Iterating through each character in the word
        char ch = word.at ( i ) ;  // Assigning the character at the current index to a char variable

        if ( isupper ( ch ) ) {  // Checking if the character is uppercase
            uppercase ++ ;  // Incrementing the uppercase counter
        } else {
            lowercase ++ ;  // Incrementing the lowercase counter
        }
    }

    if ( uppercase > lowercase ) {  // Checking if there are more uppercase characters than lowercase characters
        cout << word.c_str ( ) << endl ;  // Printing the word in uppercase if condition is true
    } else if ( lowercase > uppercase ) {  // Checking if there are more lowercase characters than uppercase characters
        cout << word.c_str ( ) << endl ;  // Printing the word in lowercase if condition is true
    } else {  // If both uppercase and lowercase characters are equal
        cout << word.c_str ( ) << endl ;  // Printing the word in lowercase if both conditions are false
    }

    return 0 ;
}

