
import sys

# Set the base size of the board
BASE = 12

# Initialize the moves that a knight can make
MOVES = [
    [1, -2], [2, -1], [2, 1], [1, 2],
    [-1, 2], [-2, 1], [-2, -1], [-1, -2],
]

# Initialize the grid and total number of cells
grid = []
total = 0

# Reset the board with given size
def resetBoard(size):
    global grid, total
    grid = [[0 for _ in range(size + 4)] for _ in range(size + 4)] # Allocate memory for the grid
    total = size * size # Calculate the total number of cells
    for r in range(len(grid)): # Iterate through rows
        for c in range(len(grid[0])): # Iterate through columns
            if r < 2 or r >= len(grid) - 2 or c < 2 or c >= len(grid[0]) - 2: # If cell is on the border
                grid[r][c] = -1 # Set it to -1 (out of bounds)

# Solve the knight's tour problem using depth-first search
def solve(row, col, count):
    if count > total: return True # If all cells have been filled, return true

    neighbor = neighbors(row, col) # Get the list of neighbors
    if len(neighbor) == 0 and count!= total: return False # If the current cell has no neighbors and the tour is not complete, return false

    neighbor.sort(key = lambda a: a[2]) # Sort neighbors based on the number of neighbors they have
    for nb in neighbor: # Iterate through neighbors
        nextRow = nb[0]
        nextCol = nb[1]

        grid[nextRow][nextCol] = count # Place the knight on the neighboring cell
        if not orphanDetected(count, nextRow, nextCol) and solve(nextRow, nextCol, count + 1): # Recursively call the solve function
            return True
        grid[nextRow][nextCol] = 0 # Backtrack and remove the knight from the neighboring cell
    return False # If no neighboring cell can be filled, return false

# Find the neighbors of a given cell
def neighbors(row, col):
    neighbor = [] # Initialize an empty list to store neighbors
    for m in MOVES: # Iterate through all possible moves
        x = row + m[0] # Calculate the next row
        y = col + m[1] # Calculate the next column
        if grid[x][y] == 0: # If the neighboring cell is empty
            neighbor.append([x, y, countNeighbors(x, y)]) # Add the neighbor to the list along with its number of neighbors
    return neighbor

# Count the number of neighbors for a given cell
def countNeighbors(row, col):
    count = 0 # Initialize the count to 0
    for m in MOVES: # Iterate through all possible moves
        x = row + m[0] # Calculate the next row
        y = col + m[1] # Calculate the next column
        if grid[x][y] == 0: count += 1 # Increment the count if the neighboring cell is empty
    return count

# Check if an orphan cell exists in the given position
def orphanDetected(count, row, col):
    if count < total - 1: # If the current cell has not been filled yet and the tour is not complete
        for nb in neighbors(row, col): # Iterate through the neighbors of the current cell
            if countNeighbors(nb[0], nb[1]) == 0: # If a neighbor has no remaining neighbors
                return True # Return true, indicating an orphan cell has been found
    return False # If no orphan cell is found, return false

# Print the solution on the console
def printSolution(size):
    for r in range(2, size + 2): # Iterate through rows
        for c in range(2, size + 2): # Iterate through columns
            print("%3d" % grid[r][c], end = "") # Print the cell value
        print() # Move to the next row

# Main method to read input and start the algorithm
def main():
    size = int(input()) # Read the size of the board
    startRow = int(input()) # Read the starting row
    startCol = int(input()) # Read the starting column

    resetBoard(size) # Initialize the board with the given size
    grid[startRow + 2][startCol + 2] = 1 # Place the knight on the starting cell

    if solve(startRow + 2, startCol + 2, 2): # Try to find a solution starting from the starting cell
        print("Knight's tour solution:") # Print the solution header
        printSolution(size) # Print the solution on the console
    else:
        print("No solution exists.") # Print the error message if no solution is found

if __name__ == "__main__":
    main()

