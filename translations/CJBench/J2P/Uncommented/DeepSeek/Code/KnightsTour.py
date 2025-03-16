import sys
from typing import List, Tuple

BASE = 12
MOVES = [
    (1, -2), (2, -1), (2, 1), (1, 2),
    (-1, 2), (-2, 1), (-2, -1), (-1, -2),
]

def reset_board(size: int) -> List[List[int]]:
    grid = [[0] * (size + 4) for _ in range(size + 4)]
    total = size * size
    for r in range(size + 4):
        for c in range(size + 4):
            if r < 2 or r >= size + 2 or c < 2 or c >= size + 2:
                grid[r][c] = -1
    return grid

def solve(row: int, col: int, count: int, size: int) -> bool:
    if count > total:
        return True
    neighbors = get_neighbors(row, col, size)
    if not neighbors and count != total:
        return False
    neighbors.sort(key=lambda a: a[2])
    for next_row, next_col, _ in neighbors:
        grid[next_row][next_col] = count
        if not orphan_detected(count, next_row, next_col) and solve(next_row, next_col, count + 1, size):
            return True
        grid[next_row][next_col] = 0
    return False

def get_neighbors(row: int, col: int, size: int) -> List[Tuple[int, int, int]]:
    neighbors = []
    for move in MOVES:
        next_row, next_col = row + move[0], col + move[1]
        if grid[next_row][next_col] == 0:
            neighbors.append((next_row, next_col, count_neighbors(next_row, next_col)))
    return neighbors

def count_neighbors(row: int, col: int) -> int:
    count = 0
    for move in MOVES:
        next_row, next_col = row + move[0], col + move[1]
        if grid[next_row][next_col] == 0:
            count += 1
    return count

def orphan_detected(count: int, row: int, col: int) -> bool:
    if count < total - 1:
        for next_row, next_col, _ in get_neighbors(row, col, size):
            if count_neighbors(next_row, next_col) == 0:
                return True
    return False

def print_solution(size: int) -> None:
    for r in range(2, size + 2):
        for c in range(2, size + 2):
            print(f"{grid[r][c]:3d}", end="")
        print()

if __name__ == "__main__":
    size = int(sys.stdin.readline().strip())
    start_row, start_col = map(int, sys.stdin.readline().strip().split())
    grid = reset_board(size)
    grid[start_row + 2][start_col + 2] = 1
    total = size * size
    if solve(start_row + 2, start_col + 2, 2, size):
        print("Knight's tour solution:")
        print_solution(size)
    else:
        print("No solution exists.")
