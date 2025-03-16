#include <stdio.h>
#include <string.h>
int main ( )
{
int n;
char s [ 1000001 ];
scanf ( "%d", &n );
scanf ( "%s", s );
if ( n % 2!= 0 )
printf ( "No" );
else if ( strncmp ( s, s + n / 2, n / 2 ) == 0 )
printf ( "Yes" );
else
printf ( "No" );
return 0;
}
