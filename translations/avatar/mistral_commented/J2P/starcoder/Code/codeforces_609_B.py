# Importing the required utility class Scanner from the Python standard library
import sys
import math

# Initializing the main method with an empty string array as arguments
def main ( ):

    # Creating a new Scanner object to read input from the standard input stream
    in = sys.stdin ;

    # Reading the first integer input n from the user
    n = int ( in.readline ( ) )

    # Reading the second integer input m from the user
    m = int ( in.readline ( ) )

    # Creating an integer array arr of size n to store the input integers
    arr = [ ]
    for i in range ( n ) :
        arr.append ( int ( in.readline ( ) ) )

    # Creating an integer array gen of size 11 to store the count of each integer occurrence
    gen = [ 0 ] * 11

    # Reading the input integers and storing them in the arr array
    for i in range ( n ) :
        gen [ arr [ i ] ] += 1

    # Calculating the answer
    ans = 0
    for i in range ( 1, m + 1 ) :
        for k in range ( 1, m + 1 ) :
            # Skipping the case when i and k are equal to avoid double counting
            if ( i!= k ) :
                # Multiplying the count of i and k and adding it to the answer
                ans += gen [ i ] * gen [ k ]

    # Printing the answer divided by 2
    print ( ans / 2 )

# Calling the main method
if __name__ == '__main__' :
    main ( )

# 