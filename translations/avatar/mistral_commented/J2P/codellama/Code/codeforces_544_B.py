import sys

def main ( ) :
    # Read the first integer 'n' from the input
    n = int ( sys.stdin.readline ( ) . strip ( ) )
    # Read the second integer 'count' from the input
    count = int ( sys.stdin.readline ( ) . strip ( ) )
    # Call the printIsland method with the arguments 'n' and 'count'
    printIsland ( n , count )

def printIsland ( n , count ) :
    # Calculate the side length 'a' of the square grid of size 'n x n'
    a = ( n + 1 ) // 2
    # Calculate the square of the side length 'b' of the grid
    b = n // 2
    # Calculate the maximum number of 'L' islands that can be placed in the grid
    max = a * a + b * b

    # Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
    if count > max :
        # If yes, print "NO" and return from the method
        print ( "NO" )
        return

    # If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid
    print ( "YES" )

    # Initialize a list 'grid' to store a row of the grid
    for i in range ( n ) :
        # Initialize a list 'row' to store a row of the grid
        row = [ ]
        for j in range ( n ) :
            # If the cell is in the position where an 'L' island can be placed, append an 'L' character to the list 'row' and decrement the count
            if ( i + j ) % 2 == 0 and count > 0 :
                row.append ( 'L' )
                count -= 1
            # Otherwise, append an 'S' character to the list 'row'
            else :
                row.append ( 'S' )
        # Print the contents of the list 'row' to represent a row of the grid
        print ( "".join ( row ) )

if __name__ == "__main__" :
    main ( )

