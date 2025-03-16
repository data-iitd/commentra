
def solve_case ( ) :
    # Read the dimensions of the grid and the number of operations
    n , m = map ( int , input ( ).split ( ) )
    
    # Initialize a count grid with all elements set to 0
    count = [ None ] * n
    for i in range ( n ) :
        count [ i ] = [ 0 ] * n
    
    # Initialize the answer to -1
    ans = - 1
    
    # Loop through each operation
    for k in range ( m ) :
        # Read the coordinates of the operation
        x , y = map ( int , input ( ).split ( ) )
        
        # Adjust the coordinates to zero-based index
        x -= 1
        y -= 1
        
        # Flag to check if a cell in the 3x3 grid reaches a count of 9
        found = False
        
        # Check the 3x3 grid centered at (x, y)
        for i in range ( x - 2 , x + 1 ) :
            for j in range ( y - 2 , y + 1 ) :
                if i >= 0 and i < n and j >= 0 and j < n :
                    count [ i ] [ j ] += 1
                    if count [ i ] [ j ] == 9 :
                        found = True
        
        # If a cell in the 3x3 grid reaches a count of 9, update ans and break
        if found :
            ans = k + 1
            break
    
    # Print the result
    print ( ans )
solve_case ( )

