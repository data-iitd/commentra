
import sys  # Import the sys module for reading input

def main ( ):
    N, M = map ( int, input ( ).split ( ) )  # Read the first two integers from the input, which represent the size of the grid and the number of stones to be placed
    black = [ [ 0 ] * ( N + 2 ) for _ in range ( N + 2 ) ]  # Create a 2D list of size (N+2) x (N+2) to represent the grid
    
    for m in range ( 1, M + 1 ) :  # Iterate M times, once for each stone to be placed
        x, y = map ( int, input ( ).split ( ) )  # Read the x-coordinate and y-coordinate of the next stone to be placed
        
        for xx in range ( x - 1, x + 2 ) :  # Iterate over all the neighboring cells in the x-direction
            for yy in range ( y - 1, y + 2 ) :  # Iterate over all the neighboring cells in the y-direction
                if ( black [ xx ] [ yy ] += 1 ) == 9 :  # Check if the number of black cells around this cell becomes 9
                    print ( m )  # If so, print the index of the stone that caused this condition and return
                    sys.exit ( )  # Exit the program
    
    print ( -1 )  # If we finish iterating over all the stones without finding one that has 9 black neighbors, print -1 and return

if __name__ == "__main__":
    main ( )  # Call the main function to start the program

