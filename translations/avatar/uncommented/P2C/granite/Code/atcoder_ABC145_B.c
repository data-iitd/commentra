
#include <stdio.h>

int main ( ) {
int n;
char s [ 100000 ];
scanf ( "%d", & n );
scanf ( "%s", s );
if ( n % 2!= 0 ) printf ( "No\n" );
else if ( strncmp ( s, s + n / 2, n / 2 ) == 0 ) printf ( "Yes\n" );
else printf ( "No\n" );
return 0;
}
//END-OF-CODE