
import sys

def main ( ) :
    n , m = map ( int , input ( ). split ( ) )
    a = [ int ( input ( ) ) / 2 for _ in range ( n ) ]

    gcd = 1
    lcm = 1

    for i in range ( n ) :
        gcd = getGCD ( lcm , a [ i ] )
        lcm = lcm * a [ i ] // gcd

        if lcm > m :
            print ( 0 )
            return

    for i in range ( n ) :
        if lcm // a [ i ] % 2 == 0 :
            print ( 0 )
            return

    print ( ( m // lcm + 1 ) // 2 )

def getGCD ( a , b ) :
    if b == 0 :
        return a
    else :
        return getGCD ( b , a % b )

if __name__ == "__main__" :
    main ( )

