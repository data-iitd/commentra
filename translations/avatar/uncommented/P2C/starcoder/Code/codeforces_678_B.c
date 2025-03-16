#include <stdio.h>
int main ( )
{
    int n, d, ans;
    n = 2000;
    d = 'f';
    if ( n % 400 == 0 || ( n % 4 == 0 && n % 100!= 0 ) )
        ans = 'ly';
    else
        ans = 'nly';
    while ( 1 )
    {
        if ( n % 400 == 0 || ( n % 4 == 0 && n % 100!= 0 ) )
        {
            if ( d =='m' )
                d = 'w';
            else if ( d == 't' )
                d = 'th';
            else if ( d == 'w' )
                d = 'f';
            else if ( d == 'th' )
                d ='sa';
            else if ( d == 'f' )
                d ='s';
            else if ( d =='sa' )
                d ='m';
            else if ( d =='s' )
                d = 't';
        }
        else
        {
            if ( d =='m' )
                d = 't';
            else if ( d == 't' )
                d = 'w';
            else if ( d == 'w' )
                d = 'th';
            else if ( d == 'th' )
                d = 'f';
            else if ( d == 'f' )
                d ='sa';
            else if ( d =='sa' )
                d ='s';
            else if ( d =='s' )
                d ='m';
        }
        if ( d == 'f' && ans == 'ly' && leapyear ( n ) == 'y' )
            break;
        else if ( d == 'f' && ans == 'nly' && leapyear ( n ) == 'n' )
            break;
    }
    printf ( "%d\n", n );
    return 0;
}

