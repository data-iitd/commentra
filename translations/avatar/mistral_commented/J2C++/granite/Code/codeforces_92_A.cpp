

#include <iostream> // Including the iostream library for input and output operations

using namespace std ; // Using the standard namespace for the iostream library

int main ( ) {
  int n, k, i = 1, req = 1 ; // Declaring and initializing three integer variables `n`, `k`, `i`, and `req` with the value 1

  cin >> n >> k ; // Reading the first and second integers `n` and `k` from the standard input stream

  while ( k - req >= 0 ) {
    if ( k - req >= 0 ) { // Checking if `k - req` is greater than or equal to 0
      k = k - req ; // If it is, updating the value of `k` by subtracting the value of `req`
    } else {
      break ; // If `k - req` is less than 0, breaking out of the while loop
    }
    i ++ ; // Incrementing the value of `i` by 1

    if ( i % n!= 0 ) { // Checking if the remainder of `i` divided by `n` is not equal to 0
      req = i % n ; // If it is not, updating the value of `req` to the remainder of `i` divided by `n`
    } else {
      req = n ; // If the remainder is equal to 0, updating the value of `req` to `n`
    }
  }

  cout << k ; // Printing the value of `k` to the standard output stream

  return 0 ; // Returning 0 to indicate successful execution of the program
}

