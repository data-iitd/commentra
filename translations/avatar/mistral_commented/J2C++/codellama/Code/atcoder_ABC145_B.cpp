
#include <iostream>
#include <string>

using namespace std ; // Using the standard namespace std

void cout ( string str ) { // Defining a function named cout that takes a string argument and prints it to the console
    cout << str << endl ; // Printing the given string to the console
}

int main ( ) { // Defining the main function that is the entry point of the program
    int n ; // Declaring an integer variable named n
    string a = "" , b = "" , str ; // Declaring three string variables: a, b, and str

    cin >> n ; // Reading an integer value from the console and assigning it to the variable n
    cin.ignore ( ) ; // Consuming the newline character left after reading an integer value

    getline ( cin , str ) ; // Reading a line of text from the console and assigning it to the variable str

    for ( int i = 0 ; i < n / 2 ; i ++ ) { // Starting a for loop that iterates n/2 times
        a = a + str [ i ] ; // Appending the character at the current index of str to the variable a
    }

    if ( str.compare ( a + a ) == 0 ) { // Starting an if statement to check if the given string is a palindrome
        cout ( "Yes" ) ; // Printing "Yes" to the console if the given string is a palindrome
    } else {
        cout ( "No" ) ; // Printing "No" to the console if the given string is not a palindrome
    }

    return 0 ; // Returning 0 to indicate that the program ended successfully
}

