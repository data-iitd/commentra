
#include <iostream>
using namespace std ;

int main ( ) {
  int n , k , i = 1 , req = 1 ;
  cin >> n >> k ;

  while ( k - req >= 0 ) {
    if ( k - req >= 0 ) {
      k = k - req ;
    } else {
      break ;
    }
    i ++ ;

    if ( i % n != 0 ) {
      req = i % n ;
    } else {
      req = n ;
    }
  }

  cout << k << endl ;
  return 0 ;
}

