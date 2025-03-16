
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std ;

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
    string str1, str2 ;
    cin >> str1 >> str2 ;

    // Converting the two strings to integers and storing them in variables 'num1' and 'num2'
    int num1 = stoi ( str1 ) ;
    int num2 = stoi ( str2 ) ;

    // Printing the sum of the two integers as output
    cout << num1 + num2 << endl ;
  }

  return 0 ;
}

