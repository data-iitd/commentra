
import sys
import math

def solve ( ) :
    n = int ( sys.stdin.readline ( ) )
    array = [ 0 for i in range ( 1001 ) ]
    for i in range ( n ) :
        index = int ( sys.stdin.readline ( ) )
        array [ index ] += 1
    countMax = - 1
    for i in range ( 1 , len ( array ) ) :
        if countMax < array [ i ] :
            countMax = array [ i ]
    if n % 2 == 0 :
        if countMax <= n / 2 :
            print ( "YES" )
        else :
            print ( "NO" )
    else :
        if countMax <= n / 2 + 1 :
            print ( "YES" )
        else :
            print ( "NO" )

solve ( )

