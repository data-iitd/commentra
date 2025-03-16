#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main ( void )
{
    char given [ 100 ];
    int l1 [ 4 ];
    int x1, y1, x2, y2, denominator, numerator, quotient, d;
    scanf ( "%s", given );
    sscanf ( given, "%d %d %d %d", & l1 [ 0 ], & l1 [ 1 ], & l1 [ 2 ], & l1 [ 3 ] );
    x1 = l1 [ 0 ];
    y1 = l1 [ 1 ];
    x2 = l1 [ 2 ];
    y2 = l1 [ 3 ];
    denominator = x2 - x1;
    numerator = y2 - y1;
    if ( denominator != 0 )
    {
        quotient = numerator / denominator;
    }
    if ( numerator == 0 )
    {
        d = ( int ) sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) );
        x4 = x1;
        x3 = x2;
        y3 = y2 + d;
        y4 = y1 + d;
        printf ( "%d %d %d %d", x3, y3, x4, y4 );
    }
    else if ( denominator == 0 )
    {
        y4 = y2;
        y3 = y1;
        d = ( int ) sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) );
        x4 = x1 + d;
        x3 = x2 + d;
        printf ( "%d %d %d %d", x3, y3, x4, y4 );
    }
    else if ( quotient == 1 )
    {
        x4 = x2;
        x3 = x1;
        y4 = y1;
        y3 = y2;
        printf ( "%d %d %d %d", x3, y3, x4, y4 );
    }
    else if ( quotient == - 1 )
    {
        x4 = x1;
        x3 = x2;
        y4 = y2;
        y3 = y1;
        printf ( "%d %d %d %d", x3, y3, x4, y4 );
    }
    else
    {
        printf ( "-1" );
    }
    return 0;
}
