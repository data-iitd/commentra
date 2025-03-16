
import sys

# Constants for the knight's moves and the base size of the board.
BASE = 12
MOVES = [(1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2)]

# Static variables for the grid and the total number of cells.
grid = None
total = 0

# Initializes the board with the given size, setting boundaries and some cells to -1.
def reset_board(size):
    global grid, total
    grid = [[0] * (size + 4) for _ in range(size + 4)]
    total = size * size
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if r < 2 or r >= len(grid) - 2 or c < 2 or c >= len(grid[0]) - 2:
                grid[r][c] = -1

# Attempts to solve the Knight's Tour problem using backtracking.
def solve(row, col, count):
    if count > total:
        return True  # If all cells are visited, return true.
    neighbors = get_neighbors(row, col)  # Get valid neighboring positions.
    if not neighbors and count!= total:
        return False  # If no neighbors and not all cells visited, return false.
    neighbors.sort(key=lambda nb: nb[2])  # Sort neighbors by the number of neighbors.
    for nb in neighbors:
        next_row, next_col = nb[0], nb[1]
        grid[next_row][next_col] = count  # Mark the cell as visited.
        if not orphan_detected(count, next_row, next_col) and solve(next_row, next_col, count + 1):
            return True  # Recursively attempt to solve from the next position.
        grid[next_row][next_col] = 0  # Backtrack: unmark the cell.
    return False

# Finds all valid neighboring positions for the knight and counts their neighbors.
def get_neighbors(row, col):
    neighbors = []
    for m in MOVES:
        x, y = row + m[0], col + m[1]
        if grid[x][y] == 0:
            neighbors.append((x, y, count_neighbors(x, y)))
    return neighbors

# Counts the number of valid neighboring positions for a given cell.
def count_neighbors(row, col):
    count = 0
    for m in MOVES:
        x, y = row + m[0], col + m[1]
        if grid[x][y] == 0:
            count += 1
    return count

# Checks if a cell is an orphan (no valid moves from there).
def orphan_detected(count, row, col):
    if count < total - 1:
        for nb in get_neighbors(row, col):
            if count_neighbors(nb[0], nb[1]) == 0:
                return True
    return False

# Prints the solution grid.
def print_solution(size):
    for r in range(2, size + 2):
        for c in range(2, size + 2):
            sys.stdout.write(f"{grid[r][c]:3d}")
        sys.stdout.write("\n")

# The entry point of the program. Initializes the board, solves the Knight's Tour problem, and prints the solution.
def main():
    size, start_row, start_col = map(int, input().split())
    reset_board(size)
    grid[start_row + 2][start_col + 2] = 1  # Mark the starting position.
    if solve(start_row + 2, start_col + 2, 2):
        print("Knight's tour solution:")
        print_solution(size)
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

