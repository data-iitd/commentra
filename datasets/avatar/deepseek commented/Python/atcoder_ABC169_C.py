
def main ( ) :
    from sys import setrecursionlimit , stdin
    from os import environ
    from collections import defaultdict , deque , Counter
    from math import ceil , floor , gcd
    from itertools import accumulate , combinations , combinations_with_replacement
    
    # Set the recursion limit to avoid infinite recursion
    setrecursionlimit ( 10 ** 6 )
    
    # Debugging function to print debug information if TERM_PROGRAM is in environ
    dbg = ( lambda * something : print ( * something ) ) if 'TERM_PROGRAM' in environ else lambda * x : 0
    
    # Function to read input from stdin without trailing whitespace
    input = lambda : stdin.readline ( ).rstrip ( )
    
    # Helper function to read a list of integers
    LMIIS = lambda : list ( map ( int , input ( ).split ( ) ) )
    
    # Helper function to read a single integer
    II = lambda : int ( input ( ) )
    
    # Constant for modulo operation
    P = 10 ** 9 + 7
    
    # Constant for infinity
    INF = 10 ** 9 + 10
    
    # Read two inputs, convert one to integer and the other to scaled integer
    sa , sb = input ( ).split ( )
    a = int ( sa )
    b = int ( float ( sb ) * 100 + 0.1 )
    
    # Perform the calculation and print the result
    print ( a * b // 100 )
    
main ( )