
import sys ;
import math ;

def main ( ) :
    n = int ( sys.stdin.readline ( ) ) ;
    ss = [ ] ;

    for i in range ( n ) :
        ss.append ( sys.stdin.readline ( ).strip ( ) ) ;

    cc = sys.stdin.readline ( ).strip ( ) ;
    m = len ( cc ) ;

    c = sys.stdin.readline ( ).strip ( ) [ 0 ] ;
    a = 'b' if c == 'a' else 'a' ;

    lucky = [ False for i in range ( m ) ] ;

    for j in range ( m ) :
        for i in range ( n ) :
            l = len ( ss [ i ] ) ;

            if m - j >= l and cc [ j : j + l ] == ss [ i ] :
                for h in range ( l ) :
                    lucky [ j + h ] = True ;

    for j in range ( m ) :
        if lucky [ j ] :
            if cc [ j ].lower ( ) == c :
                cc = cc [ : j ] + a + cc [ j + 1 : ] ;
            else :
                cc = cc [ : j ] + c + cc [ j + 1 : ] ;

    print ( cc ) ;

if __name__ == "__main__" :
    main ( ) ;

