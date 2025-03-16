
#include <iostream>
#include <algorithm>

using namespace std ;

int main ( ) {
  int n ; // Declaring a variable to store the number of elements in the array
  cin >> n ; // Reading the number of elements in the array from user input
  int a [ n ] ; // Creating an integer array of size n

  // Initializing the array with user input
  for ( int i = 0 ; i < n ; i ++ ) {
    cin >> a [ i ] ;
  }

  // Sorting the array in ascending order
  sort ( a , a + n ) ;

  // Checking if there is any pair of adjacent elements that satisfy the condition
  for ( int i = 0 ; i < n - 1 ; i ++ ) {
    // Checking if the next element is less than twice the current element and they are not the same
    if ( a [ i + 1 ] < a [ i ] * 2 && a [ i ] != a [ i + 1 ] ) {
      cout << "YES" << endl ; // Printing "YES" if a pair is found
      return 0 ; // Exiting the method if a pair is found
    }
  }

  // If no pair is found, printing "NO"
  cout << "NO" << endl ;

  return 0 ;
}

