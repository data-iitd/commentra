
import sys

# Main function is the entry point of the Python application
def main ( ):
    # Creating a new Scanner object to read input from the standard input stream
    sc = sys.stdin

    # Declaring and initializing an integer array x of size 3
    x = [ 0 ] * 3

    # Declaring and initializing an integer max to 0
    max = 0

    # Reading the size of the array x from the standard input stream
    for i in range ( 3 ):
        x [ i ] = int ( sc.readline ( ) ) # Reading the i-th element of the array x from the standard input stream
        max = max ( max, x [ i ] ) # Finding the maximum element of the array x

    # Declaring and initializing an integer k
    k = int ( sc.readline ( ) )

    # Declaring and initializing an array a of size 3, where each element is a List of Longs
    a = [ [ ] for i in range ( 3 ) ]

    # Reading the elements of each sub-list a[i] of size x[i] from the standard input stream and sorting it in ascending order
    for i in range ( 3 ):
        for j in range ( x [ i ] ):
            a [ i ].append ( int ( sc.readline ( ) ) )
        a [ i ].sort ( )

    # Closing the Scanner object
    sc.close ( )

    # Declaring and initializing an empty list ans to store the sum of three elements from different sub-lists that are less than or equal to k
    ans = [ ]

    # Finding all such sums and adding them to the list ans
    for i in range ( x [ 0 ] ):
        for j in range ( x [ 1 ] ):
            for m in range ( x [ 2 ] ):
                if ( ( i + 1 ) * ( j + 1 ) * ( m + 1 ) <= k ): # Checking if the product of (i+1), (j+1), and (m+1) is less than or equal to k
                    tmp = a [ 0 ] [ x [ 0 ] - i - 1 ] # Getting the (x[0]-i)-th element of the sub-list a[0]
                            + a [ 1 ] [ x [ 1 ] - j - 1 ] # Getting the (x[1]-j)-th element of the sub-list a[1]
                            + a [ 2 ] [ x [ 2 ] - m - 1 ] # Getting the (x[2]-m)-th element of the sub-list a[2]
                    ans.append ( tmp ) # Adding the sum of the three elements to the list ans

    ans.sort ( ) # Sorting the list ans in ascending order

    n = len ( ans ) # Getting the size of the list ans

    # Printing the i-th element of the list ans, where i is the index of the element to be printed, starting from the last one
    for i in range ( k ):
        print ( ans [ n - i - 1 ] )

# Calling the main function
if __name__ == '__main__':
    main ( )

