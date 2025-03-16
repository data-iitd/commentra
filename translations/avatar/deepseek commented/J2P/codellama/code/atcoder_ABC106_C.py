
import sys

def main ( ) : 
    str = sys.stdin.readline ( ) . strip ( ) 
    c = list ( str ) 
    k = int ( sys.stdin.readline ( ) . strip ( ) ) 
    n = len ( str ) 
    
    for i in range ( k ) : 
        if c [ i ] == '1' : 
            if i == k - 1 : 
                print ( 1 ) 
                return 
        else : 
            print ( c [ i ] ) 
            return 

if __name__ == "__main__" : 
    main ( ) 

