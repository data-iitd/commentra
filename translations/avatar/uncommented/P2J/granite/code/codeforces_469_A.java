
Scanner in = new Scanner ( System.in );
int max_level = in.nextInt ( );
int [] x = new int [ max_level ];
int [] y = new int [ max_level ];
for ( int i = 0 ; i < max_level ; i ++ ) {
    x [ i ] = in.nextInt ( );
}
for ( int i = 0 ; i < max_level ; i ++ ) {
    y [ i ] = in.nextInt ( );
}
Arrays.sort ( x );
Arrays.sort ( y );
int i = 0, j = 0 ;
while ( i < max_level && j < max_level ) {
    if ( x [ i ] == y [ j ] ) {
        i ++ ;
        j ++ ;
    } else if ( x [ i ] < y [ j ] ) {
        i ++ ;
    } else {
        j ++ ;
    }
}
if ( i == max_level && j == max_level ) {
    System.out.println ( "I become the guy." );
} else {
    System.out.println ( "Oh, my keyboard!" );
}
