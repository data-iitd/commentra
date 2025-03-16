n, m = map ( int, input ( ).strip ( ).split ( ) )
out = new int [ n ]
comp = new int [ n ]
for ( int i = 0 ; i < n ; i ++ )
    comp [ i ] = i + 2
for ( int i = 0 ; i < m ; i ++ ) :
    l, r, x = map ( int, input ( ).strip ( ).split ( ) )
    t = l
    while ( t <= r ) :
        next_val = comp [ t - 1 ]
        if ( out [ t - 1 ] == 0 && t!= x ) :
            out [ t - 1 ] = x
        comp [ t - 1 ] = r + 1 if t >= x else x
        t = next_val
System.out.println ( Arrays.toString ( out ) )

