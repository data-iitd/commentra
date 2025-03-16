

#include <stdio.h> // Including the standard input/output library
#include <string.h> // Including the string library

void cout ( char * str ) { // Defining a function named cout that takes a pointer to a character array argument and prints it to the console
    printf ( "%s\n", str ) ; // Printing the given character array to the console
} // End of the function cout

int main ( ) { // Defining the main function that is the entry point of the program
    char a [ 1000 ] = { 0 }, b [ 1000 ] = { 0 }, str [ 1000 ] = { 0 } ; // Declaring three character arrays: a, b, and str
    int n ; // Declaring an integer variable named n

    scanf ( "%d", & n ) ; // Reading an integer value from the console and assigning it to the variable n
    scanf ( "%s", str ) ; // Reading a line of text from the console and assigning it to the variable str

    for ( int i = 0 ; i < n / 2 ; i ++ ) { // Starting a for loop that iterates n/2 times
        a [ i ] = str [ i ] ; // Assigning the character at the current index of str to the variable a
    }

    if ( strcmp ( str, a ) == 0 ) { // Starting an if statement to check if the given string is a palindrome
        cout ( "Yes" ) ; // Printing "Yes" to the console if the given string is a palindrome
    } else {
        cout ( "No" ) ; // Printing "No" to the console if the given string is not a palindrome
    }

    return 0 ; // Returning 0 to indicate successful program execution
} // End of the main function

