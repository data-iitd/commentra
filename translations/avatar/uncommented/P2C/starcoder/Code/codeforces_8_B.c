#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( )
{
    char record_of_movements [ 100000 ] ;
    int x, y, i, j, bug ;
    char d_movement [ 4 ] [ 2 ] = { "L", "R", "U", "D" } ;
    char d [ 100000 ] [ 100000 ] ;
    scanf ( "%s", record_of_movements ) ;
    x = y = 0 ;
    bug = 0 ;
    for ( i = 0 ; record_of_movements [ i ]!= '\0' ; i ++ )
    {
        for ( j = 0 ; j < 4 ; j ++ )
        {
            if ( record_of_movements [ i ] == d_movement [ j ] [ 0 ] )
            {
                x += d_movement [ j ] [ 1 ] ;
                break ;
            }
        }
        if ( j == 4 )
        {
            bug = 1 ;
            break ;
        }
    }
    if ( bug )
    {
        printf ( "BUG" ) ;
    }
    else
    {
        printf ( "OK" ) ;
    }
    return 0 ;
}
