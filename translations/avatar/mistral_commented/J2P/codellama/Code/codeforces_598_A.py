
import math

def main ( ) :

    q = int ( input ( ) )

    while ( q > 0 ) :

        n = int ( input ( ) )

        x = int ( math.log ( n ) / math.log ( 2 ) )

        x += 1

        s = - 1 * ( int ) ( math.pow ( 2 , x ) ) + 2 + ( ( int ) n * ( int ) ( n + 1 ) ) / 2 - ( int ) math.pow ( 2 , x )

        print ( s )

        q -= 1

main ( )


