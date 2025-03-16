
import sys
import math

def resetBoard(size):
    global grid
    global total
    grid = [[0] * (size + 4) for _ in range(size + 4)]
    total = size * size
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if r < 2 or r >= len(grid) - 2 or c < 2 or c >= len(grid[0]) - 2:
                grid[r][c] = -1

def solve(row, col, count):
    if count > total:
        return True
    neighbor = neighbors(row, col)
    if not neighbor and count != total:
        return False
    neighbor.sort(key=lambda x: x[2])
    for nb in neighbor:
        nextRow = nb[0]
        nextCol = nb[1]
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
            neighbor.append([x, y, countNeighbors(x, y)])
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
            if countNeighbors(nb[0], nb[1]) == 0:
                return True
    return False

def printSolution(size):
    for r in range(2, len(grid) - 2):
        for c in range(2, len(grid[0]) - 2):
            print(f"{grid[r][c]:3d}", end="")
        print()

MOVES = [
    [1, -2], [2, -1], [2, 1], [1, 2],
    [-1, 2], [-2, 1], [-2, -1], [-1, -2],
]

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    startRow = int(sys.stdin.readline())
    startCol = int(sys.stdin.readline())
    resetBoard(size)
    grid[startRow + 2][startCol + 2] = 1
    if solve(startRow + 2, startCol + 2, 2):
        print("Knight's tour solution:")
        printSolution(size)
    else:
        print("No solution exists.")

