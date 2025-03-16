
import sys

def solve ( ) :
    N , X = map ( int , input ( ).split ( ) )
    x = [ int ( _ ) for _ in input ( ).split ( ) ]
    xsum = [ 0 ] + [ sum ( x [ : i + 1 ] ) for i in range ( N ) ]

    ans = X * N + 5 * xsum [ N ]

    for i in range ( 1 , N ) :
        cost = X * i + 5 * ( xsum [ N ] - xsum [ N - i ] )
        for j in range ( 5 , 0 , -2 ) :
            if cost > ans :
                break
            cost += j * ( xsum [ N - i - 1 ] - xsum [ max ( N - i - 1 - i , 0 ) ] )
        ans = min ( ans , cost )

    print ( ans + N * X )

solve ( )

