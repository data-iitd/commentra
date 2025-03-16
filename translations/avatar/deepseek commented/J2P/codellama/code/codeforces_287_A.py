
import sys

def main ( ) : 
    str = [ ] 
    for i in range ( 4 ) : 
        str.append ( sys.stdin.readline ( ) [ :- 1 ] ) 
    for u in range ( 2 ) : 
        for i in range ( 2 ) : 
            if ( ( str [ u ][ i ] == str [ u ][ i + 1 ] and ( str [ u + 1 ][ i ] == str [ u ][ i ] or str [ u + 1 ][ i + 1 ] == str [ u ][ i ] ) ) or ( str [ u + 1 ][ i ] == str [ u + 1 ][ i + 1 ] and ( str [ u ][ i ] == str [ u + 1 ][ i ] or str [ u ][ i + 1 ] == str [ u + 1 ][ i ] ) ) ) : 
                print ( "YES" ) 
                break 
        else : 
            print ( "NO" ) 
            break 
    return 

if __name__ == "__main__" : 
    main ( ) 
    print ( "