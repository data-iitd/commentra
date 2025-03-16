import sys ; 
import math ; 

def solve ( n , k , a ) : 
    a.sort ( ) ; 
    ans = 0 ; 
    for i in range ( k ) : 
        ans += a [ i ] ; 
    print ( ans ) ; 

def main ( ) : 
    n = int ( sys.stdin.readline ( ) ) ; 
    k = int ( sys.stdin.readline ( ) ) ; 
    a = [ int ( sys.stdin.readline ( ) ) for i in range ( n ) ] ; 
    solve ( n , k , a ) ; 

if __name__ == "__main__" : 
    main ( ) ; 

