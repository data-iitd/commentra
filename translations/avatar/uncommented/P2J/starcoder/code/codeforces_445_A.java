n, m = map ( int, input ( ).split ( ) )
l = new String [ n ]
for i in range ( n ) :
    s = input ( )
    s = s.toCharArray ( )
    for j in range ( m ) :
        if s [ j ] == '.' :
            if ( i + j ) & 1 : s [ j ] = 'W'
            else : s [ j ] = 'B'
    l [ i ] = new String ( s )
for c : System. out. println ( c )

