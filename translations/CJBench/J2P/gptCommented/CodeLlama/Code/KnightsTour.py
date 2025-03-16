
import sys

# Possible moves for the knight in chess
MOVES = [
    [1, -2], [2, -1], [2, 1], [1, 2],
    [-1, 2], [-2, 1], [-2, -1], [-1, -2],
]

# 2D array to represent the chessboard
grid = []
# Total number of squares to be covered by the knight
total = 0

# Method to reset the chessboard with a given size
def resetBoard(size):
    # Initialize the grid with additional padding
    global grid
    grid = [[0] * (size + 4) for _ in range(size + 4)]
    total = size * size # Calculate total squares
    # Set the outer border of the grid to -1 (indicating invalid squares)
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if r < 2 or r >= len(grid) - 2 or c < 2 or c >= len(grid[0]) - 2:
                grid[r][c] = -1

# Recursive method to solve the knight's tour problem
def solve(row, col, count):
    # If all squares are covered, return true
    if count > total:
        return True

    # Get the list of valid neighboring moves
    neighbor = neighbors(row, col)
    # If no neighbors and not all squares are covered, return false
    if not neighbor and count != total:
        return False

    # Sort neighbors based on the number of further possible moves (Warnsdorff's rule)
    neighbor.sort(key=lambda x: x[2])

    # Try each neighbor
    for nb in neighbor:
        nextRow = nb[0]
        nextCol = nb[1]
        grid[nextRow][nextCol] = count # Mark the square as visited

        # Check for orphan condition and recursively solve for the next move
        if not orphanDetected(count, nextRow, nextCol) and solve(nextRow, nextCol, count + 1):
            return True # If solution found, return true

        # Backtrack: unmark the square
        grid[nextRow][nextCol] = 0
    return False # No solution found

# Method to find valid neighboring squares for the knight's next move
def neighbors(row, col):
    neighbor = []
    # Check all possible knight moves
    for m in MOVES:
        x = row + m[0]
        y = col + m[1]
        # If the square is unvisited, add it to the neighbor list
        if grid[x][y] == 0:
            neighbor.append([x, y, countNeighbors(x, y)])
    return neighbor # Return the list of neighbors

# Method to count how many unvisited neighbors a square has
def countNeighbors(row, col):
    count = 0
    # Check all possible knight moves
    for m in MOVES:
        x = row + m[0]
        y = col + m[1]
        # Increment count if the neighbor is unvisited
        if grid[x][y] == 0:
            count += 1
    return count # Return the count of unvisited neighbors

# Method to detect if moving to a square creates an orphan situation
def orphanDetected(count, row, col):
    # Only check for orphan condition if not all squares are covered
    if count < total - 1:
        # Check neighbors of the current square
        for nb in neighbors(row, col):
            # If any neighbor has no unvisited neighbors, return true
            if countNeighbors(nb[0], nb[1]) == 0:
                return True
    return False # No orphan detected

# Method to print the solution of the knight's tour
def printSolution(size):
    for r in range(2, len(grid) - 2):
        for c in range(2, len(grid[0]) - 2):
            print(f"{grid[r][c]:3}", end="") # Print the grid with formatting
        print() # New line after each row

# Main method to execute the knight's tour algorithm
def main():
    # Read the size of the board and starting position from user input
    size = int(input())
    startRow = int(input())
    startCol = int(input())

    # Reset the board and mark the starting position
    resetBoard(size)
    grid[startRow + 2][startCol + 2] = 1

    # Attempt to solve the knight's tour and print the result
    if solve(startRow + 2, startCol + 2, 2):
        print("Knight's tour solution:")
        printSolution(size)
    else:
        print("No solution exists.") # No solution found

if __name__ == "__main__":
    main()
