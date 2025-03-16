#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

int mod = ( int ) 1e9 + 7 ;
int DX [ ] = { - 1, 0, 1, 0 }, DY [ ] = { 0, - 1, 0, 1 } ;
int n ;
long long k ;
long long a [ ] ;

int main ( ) {
  scanf ( "%d", & n ) ;
  scanf ( "%lld", & k ) ;
  a = ( long long * ) malloc ( n * sizeof ( long long ) ) ;
  for ( int i = 0 ; i < n ; ++ i ) {
    scanf ( "%lld", & a [ i ] ) ;
  }
  qsort ( a, n, sizeof ( long long ), cmp ) ;
  long long INF = ( long long ) ( 1e18 ) + 1 ;
  long long l = - INF ;
  long long r = INF ;
  while ( l + 1 < r ) {
    long long c = ( l + r ) / 2 ;
    if ( check ( c ) ) l = c ;
    else r = c ;
  }
  printf ( "%lld\n", l ) ;
  return 0 ;
}

int cmp ( const void * a, const void * b ) {
  return ( *( long long * ) a ) - ( *( long long * ) b ) ;
}

bool check ( long long x ) {
  long long tot = 0 ;
  for ( int i = 0 ; i < n ; i ++ ) {
    long long now = a [ i ] ;
    int l = 0, r = n ;
    if ( now >= 0 ) {
      while ( l < r ) {
        int c = ( l + r ) / 2 ;
        if ( now * a [ c ] < x ) l = c + 1 ;
        else r = c ;
      }
      tot += l ;
    } else {
      while ( l < r ) {
        int c = ( l + r ) / 2 ;
        if ( now * a [ c ] >= x ) l = c + 1 ;
        else r = c ;
      }
      tot += ( n - l ) ;
    }
    if ( ( long long ) a [ i ] * a [ i ] < x ) tot -- ;
  }
  if ( tot / 2 < k ) return true ;
  else return false ;
}

