n, k = map ( int, input ( ).split ( ) )
v = input ( )
d = new String [ ]
d [ 0 ] = "LEFT"
d [ 1 ] = "RIGHT"
f = k - 1 < n - k
m = Math. min ( k - 1, n - k )
a = new String [ 2 * m + 2 ]
for ( int i = 0 ; i < m ; i ++ )
    a [ 2 * i ] = d [! f ]
    a [ 2 * i + 1 ] = d [ f ]
for ( int i = v. length ( ) - 1 ; i >= 0 ; i -= 2 * f + 1 )
    a [ 2 * m ] = "PRINT " + v. substring ( i, i + 1 )
    a [ 2 * m + 1 ] = d [ f ]
for ( String s : a )
    System. out. println ( s )
