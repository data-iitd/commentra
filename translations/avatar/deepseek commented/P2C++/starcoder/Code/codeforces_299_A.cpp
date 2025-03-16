
#include <bits/stdc++.h>
using namespace std;

int main ( ) {
  int n;
  cin >> n;
  vector < int > a ( n );
  for ( int i = 0 ; i < n ; i ++ )
    cin >> a [ i ];
  sort ( a.begin ( ), a.end ( ) );
  if ( any_of ( a.begin ( ) + 1, a.end ( ), [ & ]( int x ) { return a [ 0 ] % x == 0; } ) )
    cout << a [ 0 ] << endl;
  else
    cout << - 1 << endl;
  return ( 0 );
}

