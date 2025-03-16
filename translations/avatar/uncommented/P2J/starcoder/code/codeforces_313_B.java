soz = input ( )
a = new int [ soz.length ( ) + 1 ]
for ( int i = 1 ; i < a.length ; i++ )
    a [ i ] = a [ i - 1 ]
    if ( soz [ i - 1 ] == soz [ i ] )
        a [ i ] += 1
n = Integer.parseInt ( input ( ) )
arr = new int [ n ]
for ( int i = 0 ; i < n ; i++ )
    m, l = input ( ).split ( " " )
    arr [ i ] = a [ Integer.parseInt ( l ) - 1 ] - a [ Integer.parseInt ( m ) - 1 ]
for ( int i = 0 ; i < n ; i++ )
    System.out.println ( arr [ i ] )

