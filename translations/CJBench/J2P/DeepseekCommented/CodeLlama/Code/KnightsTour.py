import sys

# Constants for the knight's moves and the base size of the board.
BASE = 12
MOVES = [
    [1, -2], [2, -1], [2, 1], [1, 2],
    [-1, 2], [-2, 1], [-2, -1], [-1, -2],
]

# Static variables for the grid and the total number of cells.
grid = []
total = 0

# Initializes the board with the given size, setting boundaries and some cells to -1.
def resetBoard(size):
    global grid, total
    grid = [[0] * (size + 4) for _ in range(size + 4)]
    total = size * size
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if r < 2 or r >= len(grid) - 2 or c < 2 or c >= len(grid[0]) - 2:
                grid[r][c] = -1

# Attempts to solve the Knight's Tour problem using backtracking.
def solve(row, col, count):
    global grid, total
    if count > total:
        return True  # If all cells are visited, return true.
    neighbor = neighbors(row, col)  # Get valid neighboring positions.
    if not neighbor and count != total:
        return False  # If no neighbors and not all cells visited, return false.
    neighbor.sort(key=lambda x: x[2])  # Sort neighbors by the number of neighbors.
    for nb in neighbor:
        nextRow = nb[0]
        nextCol = nb[1]
        grid[nextRow][nextCol] = count  # Mark the cell as visited.
        if not orphanDetected(count, nextRow, nextCol) and solve(nextRow, nextCol, count + 1):
            return True  # Recursively attempt to solve from the next position.
        grid[nextRow][nextCol] = 0  # Backtrack: unmark the cell.
    return False

# Finds all valid neighboring positions for the knight and counts their neighbors.
def neighbors(row, col):
    neighbor = []
    for m in MOVES:
        x = row + m[0]
        y = col + m[1]
        if grid[x][y] == 0:
            neighbor.append([x, y, countNeighbors(x, y)])
    return neighbor

# Counts the number of valid neighboring positions for a given cell.
def countNeighbors(row, col):
    count = 0
    for m in MOVES:
        x = row + m[0]
        y = col + m[1]
        if grid[x][y] == 0:
            count += 1
    return count

# Checks if a cell is an orphan (no valid moves from there).
def orphanDetected(count, row, col):
    if count < total - 1:
        for nb in neighbors(row, col):
            if countNeighbors(nb[0], nb[1]) == 0:
                return True
    return False

# Prints the solution grid.
def printSolution(size):
    for r in range(2, len(grid) - 2):
        for c in range(2, len(grid[0]) - 2):
            print(f"{grid[r][c]:3}", end="")
        print()

# The entry point of the program. Initializes the board, solves the Knight's Tour problem, and prints the solution.
def main():
    size = int(sys.stdin.readline())
    startRow, startCol = map(int, sys.stdin.readline().split())
    resetBoard(size)
    grid[startRow + 2][startCol + 2] = 1  # Mark the starting position.
    if solve(startRow + 2, startCol + 2, 2):
        print("Knight's tour solution:")
        printSolution(size)
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()
