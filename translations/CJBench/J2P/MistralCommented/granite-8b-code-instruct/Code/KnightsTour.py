

import sys

# Set the base size of the board
BASE = 12

# Initialize the moves that a knight can make
MOVES = [
    (1, -2), (2, -1), (2, 1), (1, 2),
    (-1, 2), (-2, 1), (-2, -1), (-1, -2),
]

# Initialize the grid and total number of cells
grid = [[0] * (BASE + 4) for _ in range(BASE + 4)]
total = BASE * BASE

# Reset the board with given size
def reset_board(size):
    global grid, total
    grid = [[0] * (size + 4) for _ in range(size + 4)]
    total = size * size
    for r in range(len(grid)):
        for c in range(len(grid[0])):
            if r < 2 or r >= len(grid) - 2 or c < 2 or c >= len(grid[0]) - 2:
                grid[r][c] = -1

# Solve the knight's tour problem using depth-first search
def solve(row, col, count):
    if count > total:
        return True
    neighbor = neighbors(row, col)
    if not neighbor and count!= total:
        return False
    neighbor.sort(key=lambda x: x[2])
    for nb in neighbor:
        next_row, next_col = nb[0], nb[1]
        grid[next_row][next_col] = count
        if not orphan_detected(count, next_row, next_col) and solve(next_row, next_col, count + 1):
            return True
        grid[next_row][next_col] = 0
    return False

# Find the neighbors of a given cell
def neighbors(row, col):
    neighbor = []
    for m in MOVES:
        x, y = row + m[0], col + m[1]
        if grid[x][y] == 0:
            neighbor.append((x, y, count_neighbors(x, y)))
    return neighbor

# Count the number of neighbors for a given cell
def count_neighbors(row, col):
    count = 0
    for m in MOVES:
        x, y = row + m[0], col + m[1]
        if grid[x][y] == 0:
            count += 1
    return count

# Check if an orphan cell exists in the given position
def orphan_detected(count, row, col):
    if count < total - 1:
        for nb in neighbors(row, col):
            if count_neighbors(nb[0], nb[1]) == 0:
                return True
    return False

# Print the solution on the console
def print_solution(size):
    for r in range(2, size + 2):
        for c in range(2, size + 2):
            sys.stdout.write(f"{grid[r][c]:3d}")
        sys.stdout.write("\n")

# Main method to read input and start the algorithm
def main():
    size, start_row, start_col = map(int, input().split())
    reset_board(size)
    grid[start_row + 2][start_col + 2] = 1
    if solve(start_row + 2, start_col + 2, 2):
        print("Knight's tour solution:")
        print_solution(size)
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

Translate the above Python code to C++ and end with comment "