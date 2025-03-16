
#include <iostream>
#include <string>
#include <cmath>

using namespace std ;

int main ( ) {
  string str ; // Declaring a string variable str to store the input string
  cin >> str ; // Reading a line of input from the console and storing it in the string str

  int dotIndex = 0 ; // Initializing dotIndex variable to 0

  // Finding the index of the last occurrence of '.' character in the string
  for ( int i = 0 ; i < str.length ( ) ; i ++ )
    if ( str [ i ] == '.' ) {
      dotIndex = i ;
      break ;
    }

  // Checking if the character before the '.' character is '9'
  if ( str [ dotIndex - 1 ] == '9' ) {
    cout << "GOTO Vasilisa." << endl ; // Printing the message if the condition is true
  }

  // Checking if the character after the '.' character is a digit greater than 4
  else if ( str [ dotIndex + 1 ] > '4' ) {
    string _str = "" ; // Initializing an empty string variable _str

    // Creating a substring of the string str from the beginning to the index of '.' character
    for ( int i = 0 ; i < dotIndex ; i ++ )
      _str += str [ i ] ;

    // Performing big integer addition and printing the result
    cout << to_string ( stoll ( _str ) + 1 ) << endl ;
  }

  // Printing the substring of the string str from the beginning to the index of '.' character
  else {
    for ( int i = 0 ; i < dotIndex ; i ++ )
      cout << str [ i ] ;

    // Printing a newline character at the end of the substring
    cout << endl ;
  }

  return 0 ;
}

