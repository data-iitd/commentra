import sys
from typing import List, Tuple

# Set the base size of the board
BASE = 12

# Initialize the moves that a knight can make
MOVES = [
    (1, -2), (2, -1), (2, 1), (1, 2),
    (-1, 2), (-2, 1), (-2, -1), (-1, -2),
]

# Initialize the grid and total number of cells
grid = []
total = 0

# Reset the board with given size
def reset_board(size: int) -> None:
    global grid, total
    grid = [[0] * (size + 4) for _ in range(size + 4)]  # Allocate memory for the grid
    total = size * size  # Calculate the total number of cells
    for r in range(len(grid)):  # Iterate through rows
        for c in range(len(grid[0])):  # Iterate through columns
            if r < 2 or r >= len(grid) - 2 or c < 2 or c >= len(grid[0]) - 2:  # If cell is on the border
                grid[r][c] = -1  # Set it to -1 (out of bounds)

# Solve the knight's tour problem using depth-first search
def solve(row: int, col: int, count: int) -> bool:
    if count > total: return True  # If all cells have been filled, return True

    neighbors = neighbors(row, col)  # Get the list of neighbors
    if not neighbors and count != total: return False  # If the current cell has no neighbors and the tour is not complete, return False

    neighbors.sort(key=lambda a: a[2])  # Sort neighbors based on the number of neighbors they have
    for nb in neighbors:  # Iterate through neighbors
        next_row, next_col = nb[0], nb[1]

        grid[next_row][next_col] = count  # Place the knight on the neighboring cell
        if not orphan_detected(count, next_row, next_col) and solve(next_row, next_col, count + 1):  # Recursively call the solve function
            return True
        grid[next_row][next_col] = 0  # Backtrack and remove the knight from the neighboring cell
    return False  # If no neighboring cell can be filled, return False

# Find the neighbors of a given cell
def neighbors(row: int, col: int) -> List[Tuple[int, int, int]]:
    neighbor = []  # Initialize an empty list to store neighbors
    for m in MOVES:  # Iterate through all possible moves
        x = row + m[0]  # Calculate the next row
        y = col + m[1]  # Calculate the next column
        if grid[x][y] == 0:  # If the neighboring cell is empty
            neighbor.append((x, y, count_neighbors(x, y)))  # Add the neighbor to the list along with its number of neighbors
    return neighbor

# Count the number of neighbors for a given cell
def count_neighbors(row: int, col: int) -> int:
    count = 0  # Initialize the count to 0
    for m in MOVES:  # Iterate through all possible moves
        x = row + m[0]  # Calculate the next row
        y = col + m[1]  # Calculate the next column
        if grid[x][y] == 0: count += 1  # Increment the count if the neighboring cell is empty
    return count

# Check if an orphan cell exists in the given position
def orphan_detected(count: int, row: int, col: int) -> bool:
    if count < total - 1:  # If the current cell has not been filled yet and the tour is not complete
        for nb in neighbors(row, col):  # Iterate through the neighbors of the current cell
            if count_neighbors(nb[0], nb[1]) == 0:  # If a neighbor has no remaining neighbors
                return True  # Return True, indicating an orphan cell has been found
    return False  # If no orphan cell is found, return False

# Print the solution on the console
def print_solution(size: int) -> None:
    for r in range(2, size + 2):  # Iterate through rows
        for c in range(2, size + 2):  # Iterate through columns
            print(f"{grid[r][c]:3d}", end="")  # Print the cell value
        print()  # Move to the next row

# Main method to read input and start the algorithm
def main() -> None:
    size = int(input())  # Read the size of the board
    start_row = int(input())  # Read the starting row
    start_col = int(input())  # Read the starting column

    reset_board(size)  # Initialize the board with the given size
    grid[start_row + 2][start_col + 2] = 1  # Place the knight on the starting cell

    if solve(start_row + 2, start_col + 2, 2):  # Try to find a solution starting from the starting cell
        print("Knight's tour solution:")  # Print the solution header
        print_solution(size)  # Print the solution on the console
    else:
        print("No solution exists.")  # Print the error message if no solution is found

if __name__ == "__main__":
    main()
