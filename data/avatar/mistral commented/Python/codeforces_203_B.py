
# Function to solve a single test case
def solve_case ( ) :

    # Read input: number of rows and columns
    n, m = map ( int , input ( ).split ( ) )

    # Initialize a 2D array 'count' of size n x n with all elements as None
    count = [ [None] * n for _ in range (n) ]

    # Variable to store the answer
    ans = - 1

    # Iterate through each query
    for k in range ( m ) :

        # Read input: x and y for the current query
        x, y = map ( int , input ( ).split ( ) )

        # Adjust input for array indexing
        x -= 1
        y -= 1

        # Check if there is a group of 3x3 cells with count equal to 9
        found = False
        for i in range ( x - 2 , x + 1 ) :
            for j in range ( y - 2 , y + 1 ) :
                # Check if the cell is within the grid boundaries
                if i >= 0 and i < n and j >= 0 and j < n :
                    # Increment the count of the current cell
                    count [i] [j] += 1
                    # If the count becomes 9, then we have found the group
                    if count [i] [j] == 9 :
                        found = True
                        break

        # If a group of 3x3 cells with count equal to 9 is found, then update the answer
        if found :
            ans = k + 1
            break

    # Print the answer
    print ( ans )

# Call the function to solve the test case
solve_case ( )