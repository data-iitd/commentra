
#include <stdio.h>

int main ( void ) {
int n, x;
scanf ( "%d %d", &n, &x );
print ( x, n );
return 0;
}

void print ( int x, int n ) {
int max = n * 2 - 1;
if ( x == 1 || x == max ) {
puts ( "No" );
return;
}
puts ( "Yes" );
for ( int i = x + n - 1; i < x + n + max - 1; i ++ ) {
printf ( "%d\n", ( i % max + 1 ) );
}
}

// 