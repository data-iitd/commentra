#include <stdio.h>
#include <stdlib.h>

int main ( ) {
	int N;
	scanf ( "%d", &N );
	double x [ N ];
	for ( int i = 0 ; i < N ; i ++ ) {
		char s [ 100 ];
		scanf ( "%s", s );
		if ( s [ 0 ] == 'J' && s [ 1 ] == 'P' && s [ 2 ] == 'Y' ) {
			x [ i ] = atof ( s + 4 );
		} else if ( s [ 0 ] == 'B' && s [ 1 ] == 'T' && s [ 2 ] == 'C' ) {
			x [ i ] = atof ( s + 4 ) * 380000.0;
		} else {
			x [ i ] = atof ( s );
		}
	}
	double ans = 0.0;
	for ( int i = 0 ; i < N ; i ++ ) {
		ans += x [ i ];
	}
	printf ( "%.2lf\n", ans );
	return 0;
}
