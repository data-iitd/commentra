
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
  int n , k , i , req ; // Declaring four variables `n`, `k`, `i`, and `req`
  scanf ( "%d %d" , &n , &k ) ; // Reading two integers `n` and `k` from the standard input stream
  i = 1 ; // Initializing the value of `i` to 1
  req = 1 ; // Initializing the value of `req` to 1

  // Starting a while loop that continues as long as `k - req` is greater than or equal to 0
  while ( k - req >= 0 ) {
    if ( k - req >= 0 ) { // Checking if `k - req` is greater than or equal to 0
      k = k - req ; // If it is, updating the value of `k` by subtracting the value of `req`
    } else {
      break ; // If `k - req` is less than 0, breaking out of the while loop
    }
    i ++ ; // Incrementing the value of `i` by 1

    if ( i % n != 0 ) { // Checking if the remainder of `i` divided by `n` is not equal to 0
      req = i % n ; // If it is not, updating the value of `req` to the remainder of `i` divided by `n`
    } else {
      req = n ; // If the remainder is equal to 0, updating the value of `req` to `n`
    }
  }

  // Printing the value of `k` to the standard output stream
  printf ( "%d\n" , k ) ;
  return 0 ;
}

