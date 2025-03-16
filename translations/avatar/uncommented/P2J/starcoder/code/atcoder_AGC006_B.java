N, X = [ int ( _ ) for _ in input ( ).split ( ) ]
from itertools import permutations
def calc ( x ) :
    def sub ( y, debug = 0 ) :
        if debug :
            System.out.println ( "D" + y )
        while len ( y ) > 1 :
            y = [ sorted ( y [ i : i + 3 ] ) [ 1 ] for i in range ( len ( y ) - 2 ) ]
            if debug :
                System.out.println ( "D" + y )
        return y
    y = sub ( x )
    if y [ 0 ] == 2 :
        pass
        sub ( x, 1 )
        System.out.println ( "=" + x )
    return y [ 0 ]
if X == 1 or X == N * 2 - 1 :
    System.out.println ( "No" )
else :
    System.out.println ( "Yes" )
    if X == N * 2 - 2 :
        xs = new ArrayList < > ( )
        for i in range ( N - 1, X + 2 ) :
            xs.add ( i )
        for i in range ( 1, N - 1 ) :
            xs.add ( i )
    else :
        ys = new ArrayList < > ( )
        for i in range ( 1, X - 1 ) :
            ys.add ( i )
        for i in range ( X + 3, N * 2 ) :
            ys.add ( i )
        xs = ys.subList ( 0, N - 3 )
        xs.add ( X + 2 )
        xs.add ( X - 1 )
        xs.add ( X )
        xs.add ( X + 1 )
        xs.addAll ( ys.subList ( N - 3, ys.size ( ) ) )
    for x in xs :
        System.out.println ( x )



