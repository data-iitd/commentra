
#include <iostream>
#include <cmath>
#include <string>

using namespace std ;

int main() {
  // Initialize a variable N to read the first integer from the standard input
  int N ;
  cin >> N ;

  // Initialize a variable K to read the second integer from the standard input
  int K ;
  cin >> K ;

  // Initialize a string variable S to read the string from the standard input
  string S ;
  cin >> S ;

  // Initialize a boolean variable firstTime to true
  bool firstTime = true ;

  // Initialize an integer variable step to 1
  int step = 1 ;

  // Perform the main logic while K is greater than zero
  while ( K > 0 ) {
    // Create a new string variable T to store the reversed version of S
    string T = S ;
    reverse(T.begin(), T.end()) ;

    // Create a new string variable revU to store the concatenation of S and T reversed
    string revU = S + T ;
    reverse(revU.begin(), revU.end()) ;

    // Create a string variable sDash to store the current substring of revU
    string sDash = S ;

    // Iterate through the substrings of revU starting from the end of S
    for ( int i = N ; i >= 0 ; i -= step ) {
      // Get the substring of revU starting from the current index i and of length N
      string tmp = revU.substr(i, N) ;

      // Compare the current substring tmp with the current substring sDash
      if ( sDash.compare(tmp) > 0 ) {
        // Update the current substring sDash with the new substring tmp
        sDash = tmp ;
      } else {
        // If this is not the first iteration, break the loop
        if ( ! firstTime ) {
          break ;
        }
      }
    }

    // Perform some actions based on the comparison of sDash and S
    if ( firstTime ) {
      firstTime = false ;
      // Check if the length of S raised to the power of K is greater than N
      if ( pow(2, K) > N ) {
        // Print the first character of S N times and exit the program
        char c = sDash[0] ;
        for ( int i = 0 ; i < N ; i ++ ) {
          cout << c ;
        }
        cout << endl ;
        return 0 ;
      }
    } else {
      // Update the value of step
      step += step ;
    }

    // Decrement the value of K
    K-- ;

    // Update the value of S to be the current substring sDash reversed
    S = sDash ;
    reverse(S.begin(), S.end()) ;
  }

  // Print the reversed version of the final string S
  reverse(S.begin(), S.end()) ;
  cout << S << endl ;

  return 0 ;
}

