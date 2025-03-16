def solve_case():
    # Read the dimensions of the grid (n) and the number of operations (m)
    n, m = map(int, input().split())
    
    # Initialize a 2D list to keep track of counts for each cell in the grid
    count = [None] * n
    for i in range(n):
        count[i] = [0] * n  # Each cell starts with a count of 0
    
    ans = -1  # Initialize the answer variable to -1 (indicating no solution found)
    
    # Process each operation
    for k in range(m):
        # Read the coordinates for the current operation and adjust for 0-based indexing
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        
        found = False  # Flag to indicate if a cell has reached the count of 9
        
        # Iterate over the 3x3 grid centered at (x, y)
        for i in range(x - 2, x + 1):
            for j in range(y - 2, y + 1):
                # Check if the indices are within the bounds of the grid
                if i >= 0 and i < n and j >= 0 and j < n:
                    count[i][j] += 1  # Increment the count for the current cell
                    
                    # Check if the count for this cell has reached 9
                    if count[i][j] == 9:
                        found = True  # Mark that we found a cell with count 9
        
        # If a cell with count 9 was found, update the answer and break the loop
        if found:
            ans = k + 1  # Store the 1-based index of the operation
            break
    
    # Print the result: the operation number where a cell reached count 9, or -1 if none did
    print(ans)

# Call the function to execute the case solving
solve_case()
