import sys
import math
from collections import defaultdict
sys.setrecursionlimit ( 10 ** 7 )  # Set recursion limit to prevent stack overflow
def input ( ) :
    return sys.stdin.readline ( ) [ : - 1 ]
mod = 10 ** 9 + 7  # Define modulo constant
def I ( ) : return int ( input ( ) )
def II ( ) : return map ( int , input ( ).split ( ) )
def III ( ) : return list ( map ( int , input ( ).split ( ) ) )
def Line ( N ) :
    read_all = [ tuple ( map ( int , input ( ).split ( ) ) ) for _ in range ( N ) ]
    return map ( list , zip ( * read_all ) )
S = str ( input ( ) )  # Read input string
n = len ( S )  # Get length of the string
if n == 1 :  # Check if the string length is 1
    if S == '5' or S == '?' :  # Check if the string is '5' or '?'
        print ( 1 )  # Print 1 if true
    else :
        print ( 0 )  # Print 0 otherwise
    exit ( )  # Exit the program
dp = [ [ 0 ] * 13 for i in range ( n ) ]  # Initialize dp array
for i in range ( n ) :  # Iterate over the length of the string
    if i == 0 :  # Base case for the first character
        if S [ i ] != '?' :  # Check if the character is not '?'
            dp [ i ] [ int ( S [ i ] ) ] += 1  # Update dp value directly
        else :
            for j in range ( 10 ) :  # Iterate over all possible digits
                dp [ i ] [ j ] += 1  # Increment dp value
    else :  # General case for subsequent characters
        if S [ i ] != '?' :  # Check if the character is not '?'
            for k in range ( 13 ) :  # Iterate over all possible remainders
                dp [ i ] [ ( k * 10 + int ( S [ i ] ) ) % 13 ] += dp [ i - 1 ] [ k ]  # Update dp value
        else :
            for j in range ( 10 ) :  # Iterate over all possible digits
                for k in range ( 13 ) :  # Iterate over all possible remainders
                    dp [ i ] [ ( k * 10 + j ) % 13 ] += dp [ i - 1 ] [ k ]  # Update dp value
        for k in range ( 13 ) :  # Apply modulo to prevent overflow
            dp [ i ] [ k ] %= mod
print ( dp [ n - 1 ] [ 5 ] )  # Print the result