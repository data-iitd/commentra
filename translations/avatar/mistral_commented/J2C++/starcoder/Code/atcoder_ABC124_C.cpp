
#include <bits/stdc++.h>
using namespace std;

// Class to solve the problem
class CColoringColorfully {
public:
  // Method to solve the problem
  void solve ( int testNumber, istream & in, ostream & out ) {
    string x ; // Read the input string
    cin >> x ; // Read the input string
    string a = x ; // Create a string object 'a' with the same string as 'x'
    string b = x ; // Create a string object 'b' with the same string as 'x'
    int a1 = 0 ; // Initialize counter for number of consecutive '1's in string 'a'
    int a2 = 0 ; // Initialize counter for number of consecutive '1's in string 'b'

    // Loop through each character in string 'a' starting from index 1
    for ( int i = 1 ; i < x.length ( ) ; i ++ ) {
      if ( a[ i ] == a[ i - 1 ] ) { // Check if current character is same as previous character
        if ( a[ i ] == '1' ) a[ i ] = '0' ; // If '1', change it to '0'
        else a[ i ] = '1' ; // If not '1', change it to '1'
        a1 ++ ; // Increment counter for number of consecutive '1's
      }
    }

    // Loop through each character in string 'b' starting from the last character
    for ( int i = x.length ( ) - 1 ; i > 0 ; i -- ) {
      if ( b[ i ] == b[ i - 1 ] ) { // Check if current character is same as previous character
        if ( b[ i - 1 ] == '1' ) b[ i - 1 ] = '0' ; // If '1', change it to '0'
        else b[ i - 1 ] = '1' ; // If not '1', change it to '1'
        a2 ++ ; // Increment counter for number of consecutive '1's
      }
    }

    // Print the minimum number of consecutive '1's in strings 'a' and 'b'
    out << min ( a1, a2 ) << endl ;
  }
} ;

// Main method to start the program
int main ( ) {
  ios_base :: sync_with_stdio ( false ) ; // Disable synchronization with C++ streams
  cin.tie ( 0 ) ; // This is for fast I/O
  int testNumber ; // Number of test cases
  cin >> testNumber ; // Read the number of test cases
  while ( testNumber -- ) {
    CColoringColorfully solver = CColoringColorfully ( ) ; // Initialize solver object
    solver.solve ( testNumber + 1, cin, cout ) ; // Solve the problem and print the output
  }
  return 0 ;
}

