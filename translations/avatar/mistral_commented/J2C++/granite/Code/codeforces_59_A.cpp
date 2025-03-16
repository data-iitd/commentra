
#include <iostream>  // Importing the iostream library for input/output operations
#include <string>  // Importing the string library for string manipulation

using namespace std;  // Using the standard namespace for the standard library

int main ( ) {  // Main function, entry point of the program
    string word;  // Declaring a string variable to store the input word

    cout << "Enter a word: ";  // Displaying a prompt to the user to enter a word
    cin >> word;  // Reading the input word from the console and storing it in the word variable

    int uppercase = 0;  // Initializing a counter for uppercase characters
    int lowercase = 0;  // Initializing a counter for lowercase characters

    for ( int i = 0 ; i < word.length ( ) ; i ++ ) {  // Iterating through each character in the word
        char ch = word.at ( i ) ;  // Assigning the character at the current index to a char variable

        if ( isupper ( ch ) ) {  // Checking if the character is uppercase
            uppercase ++ ;  // Incrementing the uppercase counter
        } else {
            lowercase ++ ;  // Incrementing the lowercase counter
        }
    }

    if ( uppercase > lowercase ) {  // Checking if there are more uppercase characters than lowercase characters
        transform ( word.begin ( ), word.end ( ), word.begin ( ), ::toupper ) ;  // Transforming the word to uppercase using the transform function
    } else if ( lowercase > uppercase ) {  // Checking if there are more lowercase characters than uppercase characters
        transform ( word.begin ( ), word.end ( ), word.begin ( ), ::tolower ) ;  // Transforming the word to lowercase using the transform function
    } else {  // If both uppercase and lowercase characters are equal
        transform ( word.begin ( ), word.end ( ), word.begin ( ), ::tolower ) ;  // Transforming the word to lowercase using the transform function
    }

    cout << word << endl;  // Printing the transformed word to the console

    return 0;  // Returning 0 to indicate successful execution of the program
}

