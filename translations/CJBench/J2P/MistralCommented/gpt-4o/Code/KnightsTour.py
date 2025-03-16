import sys
from typing import List, Tuple

class KnightTour:
    # Set the base size of the board
    BASE = 12

    # Initialize the moves that a knight can make
    MOVES = [
        (1, -2), (2, -1), (2, 1), (1, 2),
        (-1, 2), (-2, 1), (-2, -1), (-1, -2),
    ]

    def __init__(self, size: int, start_row: int, start_col: int):
        self.size = size
        self.start_row = start_row + 2
        self.start_col = start_col + 2
        self.grid = [[0] * (size + 4) for _ in range(size + 4)]
        self.total = size * size
        self.reset_board()

    def reset_board(self):
        for r in range(len(self.grid)):
            for c in range(len(self.grid[0])):
                if r < 2 or r >= len(self.grid) - 2 or c < 2 or c >= len(self.grid[0]) - 2:
                    self.grid[r][c] = -1

    def solve(self, row: int, col: int, count: int) -> bool:
        if count > self.total:
            return True

        neighbors = self.get_neighbors(row, col)
        if not neighbors and count != self.total:
            return False

        neighbors.sort(key=lambda x: x[2])  # Sort neighbors based on the number of neighbors they have
        for nb in neighbors:
            next_row, next_col = nb[0], nb[1]
            self.grid[next_row][next_col] = count
            if not self.orphan_detected(count, next_row, next_col) and self.solve(next_row, next_col, count + 1):
                return True
            self.grid[next_row][next_col] = 0  # Backtrack

        return False

    def get_neighbors(self, row: int, col: int) -> List[Tuple[int, int, int]]:
        neighbors = []
        for m in self.MOVES:
            x, y = row + m[0], col + m[1]
            if self.grid[x][y] == 0:
                neighbors.append((x, y, self.count_neighbors(x, y)))
        return neighbors

    def count_neighbors(self, row: int, col: int) -> int:
        count = 0
        for m in self.MOVES:
            x, y = row + m[0], col + m[1]
            if self.grid[x][y] == 0:
                count += 1
        return count

    def orphan_detected(self, count: int, row: int, col: int) -> bool:
        if count < self.total - 1:
            for nb in self.get_neighbors(row, col):
                if self.count_neighbors(nb[0], nb[1]) == 0:
                    return True
        return False

    def print_solution(self):
        for r in range(2, self.size + 2):
            for c in range(2, self.size + 2):
                print(f"{self.grid[r][c]:3d}", end="")
            print()

def main():
    size = int(input())
    start_row = int(input())
    start_col = int(input())

    knight_tour = KnightTour(size, start_row, start_col)
    knight_tour.grid[knight_tour.start_row][knight_tour.start_col] = 1

    if knight_tour.solve(knight_tour.start_row, knight_tour.start_col, 2):
        print("Knight's tour solution:")
        knight_tour.print_solution()
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
