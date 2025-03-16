import sys ; 
import math ; 

def solve ( ) : 
    # Reading the number of test cases (t) and other required values
    x = int ( sys.stdin.readline ( ) ) ; # Target value x
    t = int ( sys.stdin.readline ( ) ) ; # Number of test cases (unused in this code)
    a = int ( sys.stdin.readline ( ) ) ; # Value a
    b = int ( sys.stdin.readline ( ) ) ; # Value b
    da = int ( sys.stdin.readline ( ) ) ; # Difference a (da)
    db = int ( sys.stdin.readline ( ) ) ; # Difference b (db)
    
    # Variables to store calculated values
    first = 0 ; 
    second = 0 ; 
    
    # Flag to determine if a solution is found
    ok = False ; 
    
    # Nested loop to calculate possible values of first and second
    for i in range ( 0 , t ) : 
        first = a - ( da * i ) ; # Calculate first value
        for j in range ( 0 , t ) : 
            second = b - ( db * j ) ; # Calculate second value
            if ( second + first == x or second == x or first == x or x == 0 ) : 
                # Check if the sum of first and second equals x, or if either value equals x, or if x is zero
                ok = True ; 
                break ; 
        if ( ok ) break ; # Exit the outer loop if a solution is found
    
    # Print the result based on the flag
    if ( ok ) print ( "YES" ) ; 
    else print ( "NO" ) ; 

def main ( ) : 
    solve ( ) ; 

if ( __name__ == "__main__" ) : 
    main ( ) ; 

# 