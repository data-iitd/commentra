import sys
from typing import List, Tuple

# Possible moves for the knight in chess
MOVES = [
    (1, -2), (2, -1), (2, 1), (1, 2),
    (-1, 2), (-2, 1), (-2, -1), (-1, -2),
]

def reset_board(size: int) -> List[List[int]]:
    # Initialize the grid with additional padding
    grid = [[0] * (size + 4) for _ in range(size + 4)]
    total = size * size  # Calculate total squares
    # Set the outer border of the grid to -1 (indicating invalid squares)
    for r in range(size + 4):
        for c in range(size + 4):
            if r < 2 or r >= size + 2 or c < 2 or c >= size + 2:
                grid[r][c] = -1
    return grid

def solve(grid: List[List[int]], row: int, col: int, count: int, size: int) -> bool:
    # If all squares are covered, return True
    if count > size * size:
        return True

    # Get the list of valid neighboring moves
    neighbors = find_neighbors(grid, row, col)
    # If no neighbors and not all squares are covered, return False
    if not neighbors and count != size * size:
        return False

    # Sort neighbors based on the number of further possible moves (Warnsdorff's rule)
    neighbors.sort(key=lambda x: x[2])

    # Try each neighbor
    for next_row, next_col, _ in neighbors:
        grid[next_row][next_col] = count  # Mark the square as visited

        # Check for orphan condition and recursively solve for the next move
        if not orphan_detected(grid, count, next_row, next_col) and solve(grid, next_row, next_col, count + 1, size):
            return True  # If solution found, return True

        # Backtrack: unmark the square
        grid[next_row][next_col] = 0

    return False  # No solution found

def find_neighbors(grid: List[List[int]], row: int, col: int) -> List[Tuple[int, int, int]]:
    neighbors = []
    # Check all possible knight moves
    for move in MOVES:
        x, y = row + move[0], col + move[1]
        # If the square is unvisited, add it to the neighbor list
        if grid[x][y] == 0:
            neighbors.append((x, y, count_neighbors(grid, x, y)))
    return neighbors

def count_neighbors(grid: List[List[int]], row: int, col: int) -> int:
    count = 0
    # Check all possible knight moves
    for move in MOVES:
        x, y = row + move[0], col + move[1]
        # Increment count if the neighbor is unvisited
        if grid[x][y] == 0:
            count += 1
    return count

def orphan_detected(grid: List[List[int]], count: int, row: int, col: int) -> bool:
    # Only check for orphan condition if not all squares are covered
    if count < size * size - 1:
        # Check neighbors of the current square
        for x, y, _ in find_neighbors(grid, row, col):
            # If any neighbor has no unvisited neighbors, return True
            if count_neighbors(grid, x, y) == 0:
                return True
    return False

def print_solution(grid: List[List[int]], size: int) -> None:
    for r in range(2, size + 2):
        for c in range(2, size + 2):
            print(f"{grid[r][c]:3d}", end="")  # Print the grid with formatting
        print()  # New line after each row

# Main function to execute the knight's tour algorithm
def main():
    # Read the size of the board and starting position from user input
    size = int(input().strip())
    start_row, start_col = map(int, input().strip().split())

    # Reset the board and mark the starting position
    grid = reset_board(size)
    grid[start_row + 2][start_col + 2] = 1

    # Attempt to solve the knight's tour and print the result
    if solve(grid, start_row + 2, start_col + 2, 2, size):
        print("Knight's tour solution:")
        print_solution(grid, size)
    else:
        print("No solution exists.")  # No solution found

if __name__ == "__main__":
    main()
