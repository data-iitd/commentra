import sys ;  # Import the sys module to read input from stdin

def main ( ):
    N, M = map ( int, sys.stdin.readline ( ).split ( ) )  # Read the first integer from the input, which represents the size of the grid and the number of stones to be placed on the grid
    
    black = [ [ 0 for i in range ( N + 2 ) ] for j in range ( N + 2 ) ]  # Create a 2D array of size (N+2) x (N+2) to represent the grid
    
    for m in range ( 1, M + 1 ) :  # Iterate M times, once for each stone to be placed
        x, y = map ( int, sys.stdin.readline ( ).split ( ) )  # Read the x-coordinate of the next stone to be placed and the y-coordinate of the next stone to be placed
        
        for xx in range ( x - 1, x + 2 ) :  # Iterate over all the neighboring cells in the x-direction
            for yy in range ( y - 1, y + 2 ) :  # Iterate over all the neighboring cells in the y-direction
                black [ xx ] [ yy ] += 1  # Increment the number of black cells around this cell by 1
        
        if black [ x ] [ y ] == 9 :  # Check if the number of black cells around this cell becomes 9
            print ( m )  # If so, print the index of the stone that caused this condition and return
            return
    
    print ( -1 )  # If we finish iterating over all the stones without finding one that has 9 black neighbors, print -1 and return

if __name__ == '__main__' :
    main ( )

