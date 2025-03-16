import sys
import math

def main ( ):
    n = int ( sys.stdin.readline ( ) )
    k = int ( sys.stdin.readline ( ) )
    bb = [ int ( sys.stdin.readline ( ) ) for i in range ( n ) ]

    # Initialize an array to store the result
    aa = [ 0 for i in range ( n ) ]
    m = 0

    # Process the array bb in reverse order
    for a in range ( n - 1 , -1 , -1 ):
        j = 0
        while ( bb [ a ] > 0 ):
            if ( aa [ j ] >= a + k ):
                bb [ a ] -= 1
            j += 1
        for j_ in range ( m , j - 1 , -1 ):
            aa [ j_ ] = aa [ j_ - 1 ]
        aa [ j ] = a

    # Print the contents of the array aa, incrementing each element by 1
    for i in range ( n ):
        print ( aa [ i ] + 1 , end = " " )
    print ( )

main ( )

