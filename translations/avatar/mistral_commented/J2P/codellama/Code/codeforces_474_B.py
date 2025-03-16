import sys

def main ( ) :
    n = int ( sys.stdin.readline ( ) )
    arr = [ int ( sys.stdin.readline ( ) ) ]
    for i in range ( 1 , n ) :
        arr.append ( int ( sys.stdin.readline ( ) ) + arr [ i - 1 ] )
    m = int ( sys.stdin.readline ( ) )
    q = [ int ( sys.stdin.readline ( ) ) for i in range ( m ) ]
    for k in range ( m ) :
        print ( fun ( arr , q [ k ] , n , m ) + 1 )

def fun ( arr , q , n , m ) :
    i = 0
    j = n
    while i <= j :
        md = i + ( j - i ) // 2
        if arr [ md ] == q :
            return md
        elif arr [ md ] > q :
            j = md - 1
        else :
            i = md + 1
    return j

if __name__ == "__main__" :
    main ( )

