// Importing necessary C++ classes for reading input from the console and writing output to the console
#include <iostream>
#include <string>

// Main method is the entry point of the C++ application
int main ( ) {

    // Creating a string variable to store input
    std::string input ;

    // Creating a string variable to store each word in the input
    std::string word ;

    // Creating an integer variable to store the result
    int result = 0 ;

    // Taking input from the console
    std::cin >> input ;

    // Iterating through each character in the input
    for ( char c : input ) {

        // If the character is a space, then increment the result variable
        if ( c =='' ) result++ ;

        // If the character is a zero, then break the loop
        if ( c == '0' ) break ;
    }

    // Writing the result to the console
    std::cout << result << std::endl ;

    // Returning from the main method
    return 0 ;
}

