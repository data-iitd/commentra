
import sys

def main ( ) :
    N = int ( sys.stdin.readline ( ) )
    M = int ( sys.stdin.readline ( ) )

    H = [ int ( sys.stdin.readline ( ) ) for i in range ( N ) ]
    ans = [ True for i in range ( N ) ]

    for query in range ( M ) :
        temp1 = int ( sys.stdin.readline ( ) )
        temp2 = int ( sys.stdin.readline ( ) )

        if H [ temp1 - 1 ] < H [ temp2 - 1 ] :
            ans [ temp1 - 1 ] = False
        elif H [ temp1 - 1 ] > H [ temp2 - 1 ] :
            ans [ temp2 - 1 ] = False
        else :
            ans [ temp1 - 1 ] = False
            ans [ temp2 - 1 ] = False

    ans2 = 0
    for i in range ( N ) :
        if ans [ i ] :
            ans2 += 1

    print ( ans2 )

if __name__ == "__main__" :
    main ( )

