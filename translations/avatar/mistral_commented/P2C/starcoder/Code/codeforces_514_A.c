#include <stdio.h>
#include <string.h>

int main ()
{
    char ip [ 100 ];
    char st [ 100 ];
    int i, n;

    scanf ( "%s", ip );

    if ( strlen ( ip )!= 1 )
    {
        if ( ip [ 0 ] == '9' )
        {
            strcpy ( st, "9" );
            ip [ 0 ] = '\0';
        }

        for ( i = 0; ip [ i ]!= '\0'; i++ )
        {
            if ( ip [ i ] - '0' > 4 )
            {
                n = 9 - ( ip [ i ] - '0' );
                strcat ( st, ( char * ) &n );
            }
            else
            {
                strcat ( st, ip [ i ] );
            }
        }
    }
    else
    {
        strcpy ( st, ip );
    }

    printf ( "%d\n", atoi ( st ) );

    return 0;
}

