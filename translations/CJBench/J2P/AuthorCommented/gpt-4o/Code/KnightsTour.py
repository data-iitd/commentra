import numpy as np

class KnightsTour:
    BASE = 12  # The size of the chess board (12x12 grid, with 2 extra rows/columns as a buffer around a 8x8 area)
    
    # Possible moves for a knight in chess
    MOVES = [
        (1, -2), (2, -1), (2, 1), (1, 2),
        (-1, 2), (-2, 1), (-2, -1), (-1, -2),
    ]

    def __init__(self, size):
        self.size = size
        self.grid = np.zeros((size + 4, size + 4), dtype=int)
        self.total = size * size
        self.reset_board()

    def reset_board(self):
        for r in range(self.grid.shape[0]):
            for c in range(self.grid.shape[1]):
                if r < 2 or r >= self.grid.shape[0] - 2 or c < 2 or c >= self.grid.shape[1] - 2:
                    self.grid[r][c] = -1  # Mark boundaries

    def solve(self, row, col, count):
        if count > self.total:
            return True

        neighbors = self.get_neighbors(row, col)
        if not neighbors and count != self.total:
            return False

        neighbors.sort(key=lambda x: x[2])  # Sort by number of possible next moves
        for nb in neighbors:
            next_row, next_col = nb[0], nb[1]
            self.grid[next_row][next_col] = count
            if not self.orphan_detected(count, next_row, next_col) and self.solve(next_row, next_col, count + 1):
                return True
            self.grid[next_row][next_col] = 0  # Backtrack
        return False

    def get_neighbors(self, row, col):
        neighbor = []
        for m in self.MOVES:
            x, y = row + m[0], col + m[1]
            if self.grid[x][y] == 0:
                neighbor.append((x, y, self.count_neighbors(x, y)))
        return neighbor

    def count_neighbors(self, row, col):
        count = 0
        for m in self.MOVES:
            x, y = row + m[0], col + m[1]
            if self.grid[x][y] == 0:
                count += 1
        return count

    def orphan_detected(self, count, row, col):
        if count < self.total - 1:
            for nb in self.get_neighbors(row, col):
                if self.count_neighbors(nb[0], nb[1]) == 0:
                    return True
        return False

    def print_solution(self):
        for r in range(2, self.size + 2):
            for c in range(2, self.size + 2):
                print(f"{self.grid[r][c]:3d}", end=' ')
            print()

def main():
    size = int(input("Enter the size of the board (N): "))
    start_row = int(input("Enter the starting row: "))
    start_col = int(input("Enter the starting column: "))

    knight_tour = KnightsTour(size)
    knight_tour.grid[start_row + 2][start_col + 2] = 1

    if knight_tour.solve(start_row + 2, start_col + 2, 2):
        print("Knight's tour solution:")
        knight_tour.print_solution()
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
