
import sys
import math

def main ( ) :
    num = 998244353  # Initializing a variable 'num' with a value
    n = int ( sys.stdin.readline ( ) )  # Reading the number of test cases from the input
    ai = [ ]  # Creating an empty list to store the first array elements
    bi = [ ]  # Creating an empty list to store the second array elements

    for i in range ( n ) :  # Iterating through the test cases
        ai.append ( int ( sys.stdin.readline ( ).split ( ) [ 0 ] ) )  # Adding the first array element to the list
        bi.append ( int ( sys.stdin.readline ( ).split ( ) [ 0 ] ) )  # Adding the second array element to the list

    # Sorting the lists in ascending order
    ai.sort ( )
    bi.sort ( )

    if n % 2 == 1 :  # Checking if the number of test cases is odd
        print ( int ( bi [ int ( math.floor ( n / 2 ) ) ] - ai [ int ( math.floor ( n / 2 ) ) ] + 1 ) )  # Calculating and printing the answer for odd number of test cases
    else :
        b = ( ai [ int ( math.floor ( n / 2 ) ) ] + ai [ int ( math.floor ( n / 2 ) - 1 ) ] + 0.0 ) / 2  # Calculating the average of the middle two elements of the first list
        c = ( bi [ int ( math.floor ( n / 2 ) ) ] + bi [ int ( math.floor ( n / 2 ) - 1 ) ] + 0.0 ) / 2  # Calculating the average of the middle two elements of the second list
        print ( int ( 2 * ( c - b ) + 1 ) )  # Calculating and printing the answer for even number of test cases

if __name__ == "__main__" :
    main ( )

