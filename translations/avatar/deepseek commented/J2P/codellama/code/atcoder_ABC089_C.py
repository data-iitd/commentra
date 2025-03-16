
import sys ; import math ; import string ; import itertools ; 
# Import necessary libraries for input/output operations and string manipulations.

def solve ( testNumber , inp , out ) : 
    n = int ( inp.readline ( ) ) ; 
    cnt = [ 0 ] * 5 ; 
    # Read the number of strings and initialize the count array.

    for i in range ( n ) : 
        str = inp.readline ( ) ; 
        if str [ 0 ] == 'M' : 
            cnt [ 0 ] += 1 ; 
        elif str [ 0 ] == 'A' : 
            cnt [ 1 ] += 1 ; 
        elif str [ 0 ] == 'R' : 
            cnt [ 2 ] += 1 ; 
        elif str [ 0 ] == 'C' : 
            cnt [ 3 ] += 1 ; 
        elif str [ 0 ] == 'H' : 
            cnt [ 4 ] += 1 ; 
        # Count the occurrences of each character at the start of the strings.
    res = cnt [ 0 ] * cnt [ 1 ] * cnt [ 2 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 2 ] * cnt [ 3 ] * cnt [ 4 ] ; 
    out.write ( str ( res ) + '\n' ) ; 
    # Calculate the number of combinations and print the result.

if __name__ == '__main__' : 
    solve ( 1 , sys.stdin , sys.stdout ) ; 
    # Create an instance of TaskC and solve the problem.

