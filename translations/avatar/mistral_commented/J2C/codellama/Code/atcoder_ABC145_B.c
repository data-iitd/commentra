
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cout ( char *str ) { // Defining a function named cout that takes a String argument and prints it to the console
    printf ( "%s\n" , str ) ; // Printing the given String to the console
}

int main ( ) { // Defining the main function that is the entry point of the program
    char a [ ] = "" , b [ ] = "" , str [ ] = "" ; // Declaring three String variables: a, b, and str
    int n ; // Declaring an integer variable named n

    scanf ( "%d" , &n ) ; // Reading an integer value from the console and assigning it to the variable n
    getchar ( ) ; // Consuming the newline character left after reading an integer value

    fgets ( str , sizeof ( str ) , stdin ) ; // Reading a line of text from the console and assigning it to the variable str

    for ( int i = 0 ; i < n / 2 ; i ++ ) { // Starting a for loop that iterates n/2 times
        a [ i ] = str [ i ] ; // Appending the character at the current index of str to the variable a
    }

    if ( strcmp ( str , a ) == 0 ) { // Starting an if statement to check if the given string is a palindrome
        cout ( "Yes" ) ; // Printing "Yes" to the console if the given string is a palindrome
    } else {
        cout ( "No" ) ; // Printing "No" to the console if the given string is not a palindrome
    }

    return 0 ; // Returning 0 to indicate that the program executed successfully
}

