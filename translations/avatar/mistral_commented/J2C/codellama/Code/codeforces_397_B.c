
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MOD (long) (1e9 + 7)

int main ( ) {

long n, a, b, t, x, low, high, ans;

scanf ( "%ld", &t );

while ( t -- > 0 ) {

scanf ( "%ld %ld %ld", &n, &a, &b );

if ( n < a ) {
printf ( "No\n" );
continue;
}

if ( a == b ) {
if ( n % a == 0 ) {
printf ( "Yes\n" );
} else {
printf ( "No\n" );
}
continue;
}

x = b / ( b - a );
if ( n > x * a ) {
printf ( "Yes\n" );
continue;
}

low = 1;
high = x + 1;
ans = 1;

while ( low <= high ) {
mid = ( low + high ) / 2;
if ( mid * a < n ) {
low = mid + 1;
} else {
ans = mid;
high = mid - 1;
}
}

if ( n > ( ans - 1 ) * b && n < ans * a ) {
printf ( "No\n" );
} else {
printf ( "Yes\n" );
}
}

return 0;
}

