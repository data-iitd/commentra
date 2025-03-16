

#include <bits/stdc++.h> // Included required C++ libraries for input/output and streams

using namespace std ; // Using the'std' namespace for standard library functions

int main ( ) {
  int n ; // Declaring an integer variable 'n' to store the number of test cases

  // Reading the first line of input which contains the number of test cases
  cin >> n ;

  // Checking if the number of test cases is equal to 1
  if ( n == 1 ) {
    // If yes, printing "Hello World" as output
    cout << "Hello World" << endl ;
  } else {
    // If not, reading the next two lines of input which contain two integers
    int num1, num2 ; // Declaring two integer variables 'num1' and 'num2' to store the input integers
    cin >> num1 >> num2 ;

    // Printing the sum of the two integers as output
    cout << num1 + num2 << endl ;
  }

  return 0 ; // Returning 0 to indicate successful program execution
}

