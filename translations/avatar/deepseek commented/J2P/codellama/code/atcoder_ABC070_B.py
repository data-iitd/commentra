
import sys ; 

# Import the sys module for reading input from the standard input stream

def main ( ) : 
    a = int ( sys.stdin.readline ( ) ) ; 
    b = int ( sys.stdin.readline ( ) ) ; 
    c = int ( sys.stdin.readline ( ) ) ; 
    d = int ( sys.stdin.readline ( ) ) ; 
    
    # Read four integers from the input
    
    if c > b : 
        print ( 0 ) ; 
    elif a > d : 
        print ( 0 ) ; 
    elif a < c : 
        print ( min ( b , d ) - c ) ; 
    else : 
        l = [ a , b , c , d ] ; 
        l.sort ( ) ; 
        print ( l [ 2 ] - l [ 1 ] ) ; 
    
    # Check the values of a, b, c, and d and print the result based on the conditions
    
if __name__ == "__main__" : 
    main ( ) ; 
    
    # Call the main function
    
# 