
import sys

def main ( ):
    N = int ( sys.stdin.readline ( ) )
    A = [ int ( sys.stdin.readline ( ) ) for _ in range ( N ) ]
    A.sort ( )
    min = A [ 0 ]
    max = A [ N - 1 ]
    mins = 0
    maxs = 0
    for value in A:
        if value == min:
            mins += 1
        if value == max:
            maxs += 1
    if min == max:
        result = ( max - min ) + 1
        result *= mins
        result -= mins * ( mins - 1 ) / 2
        print ( result )
    else:
        result = ( max - min )
        result *= mins
        result *= maxs
        print ( result )

if __name__ == "__main__":
    main ( )

