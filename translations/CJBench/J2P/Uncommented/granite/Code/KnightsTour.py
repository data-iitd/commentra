

import sys
BASE = 12
MOVES = [
    (1, -2), (2, -1), (2, 1), (1, 2),
    (-1, 2), (-2, 1), (-2, -1), (-1, -2),
]
grid = []
total = 0
def resetBoard(size):
    global grid, total
    grid = [[0] * (size + 4) for _ in range(size + 4)]
    total = size * size
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if r < 2 or r >= len(grid) - 2 or c < 2 or c >= len(grid[0]) - 2:
                grid[r][c] = -1
def solve(row, col, count):
    if count > total: return True
    neighbors = getNeighbors(row, col)
    if not neighbors and count!= total: return False
    neighbors.sort(key=lambda nb: nb[2])
    for nb in neighbors:
        nextRow, nextCol = nb[0], nb[1]
        grid[nextRow][nextCol] = count
        if not orphanDetected(count, nextRow, nextCol) and solve(nextRow, nextCol, count + 1):
            return True
        grid[nextRow][nextCol] = 0
    return False
def getNeighbors(row, col):
    neighbors = []
    for m in MOVES:
        x, y = row + m[0], col + m[1]
        if grid[x][y] == 0:
            neighbors.append((x, y, countNeighbors(x, y)))
    return neighbors
def countNeighbors(row, col):
    count = 0
    for m in MOVES:
        x, y = row + m[0], col + m[1]
        if grid[x][y] == 0: count += 1
    return count
def orphanDetected(count, row, col):
    if count < total - 1:
        for nb in getNeighbors(row, col):
            if countNeighbors(*nb[:2]) == 0:
                return True
    return False
def printSolution(size):
    for r in range(2, size + 2):
        for c in range(2, size + 2):
            print(f"{grid[r][c]:3d}", end="")
        print()
def main():
    size, startRow, startCol = map(int, input().split())
    resetBoard(size)
    grid[startRow + 2][startCol + 2] = 1
    if solve(startRow + 2, startCol + 2, 2):
        print("Knight's tour solution:")
        printSolution(size)
    else:
        print("No solution exists.")
if __name__ == "__main__":
    main()
