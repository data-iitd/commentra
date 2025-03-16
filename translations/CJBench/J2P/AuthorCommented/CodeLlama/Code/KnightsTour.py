
import sys

# The size of the chess board (12x12 grid, with 2 extra rows/columns as a buffer around a 8x8 area)
BASE = 12

# Possible moves for a knight in chess
MOVES = [
    [1, -2], [2, -1], [2, 1], [1, 2],
    [-1, 2], [-2, 1], [-2, -1], [-1, -2],
]

# Chess grid representing the board
grid = []

# Total number of cells the knight needs to visit
total = 0

def resetBoard(size):
    global grid, total
    grid = [[0] * (size + 4) for _ in range(size + 4)]
    total = size * size
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if r < 2 or r >= len(grid) - 2 or c < 2 or c >= len(grid[0]) - 2:
                grid[r][c] = -1 # Mark boundaries

def solve(row, col, count):
    if count > total:
        return True

    neighbor = neighbors(row, col)
    if not neighbor and count != total:
        return False

    neighbor.sort(key=lambda x: x[2])
    for nb in neighbor:
        nextRow, nextCol, _ = nb
        grid[nextRow][nextCol] = count
        if not orphanDetected(count, nextRow, nextCol) and solve(nextRow, nextCol, count + 1):
            return True
        grid[nextRow][nextCol] = 0
    return False

def neighbors(row, col):
    neighbor = []
    for m in MOVES:
        x = row + m[0]
        y = col + m[1]
        if grid[x][y] == 0:
            neighbor.append((x, y, countNeighbors(x, y)))
    return neighbor

def countNeighbors(row, col):
    count = 0
    for m in MOVES:
        x = row + m[0]
        y = col + m[1]
        if grid[x][y] == 0:
            count += 1
    return count

def orphanDetected(count, row, col):
    if count < total - 1:
        for nb in neighbors(row, col):
            if countNeighbors(*nb) == 0:
                return True
    return False

def printSolution(size):
    for r in range(2, len(grid) - 2):
        for c in range(2, len(grid[0]) - 2):
            print(f"{grid[r][c]:3}", end="")
        print()

def main():
    size = int(sys.stdin.readline())

    startRow, startCol = map(int, sys.stdin.readline().split())

    resetBoard(size)
    grid[startRow + 2][startCol + 2] = 1

    if solve(startRow + 2, startCol + 2, 2):
        print("Knight's tour solution:")
        printSolution(size)
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

