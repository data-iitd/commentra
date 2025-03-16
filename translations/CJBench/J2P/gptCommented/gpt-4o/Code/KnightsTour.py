import numpy as np

class KnightTour:
    # Constant for the base size of the grid
    BASE = 12

    # Possible moves for the knight in chess
    MOVES = [
        (1, -2), (2, -1), (2, 1), (1, 2),
        (-1, 2), (-2, 1), (-2, -1), (-1, -2),
    ]

    def __init__(self, size, start_row, start_col):
        self.size = size
        self.total = size * size  # Total number of squares to be covered by the knight
        self.grid = np.zeros((size + 4, size + 4), dtype=int)  # Initialize the grid
        self.reset_board()  # Set the outer border of the grid to -1
        self.grid[start_row + 2][start_col + 2] = 1  # Mark the starting position

    def reset_board(self):
        # Set the outer border of the grid to -1 (indicating invalid squares)
        for r in range(self.grid.shape[0]):
            for c in range(self.grid.shape[1]):
                if r < 2 or r >= self.grid.shape[0] - 2 or c < 2 or c >= self.grid.shape[1] - 2:
                    self.grid[r][c] = -1

    def solve(self, row, col, count):
        # If all squares are covered, return true
        if count > self.total:
            return True

        # Get the list of valid neighboring moves
        neighbors = self.get_neighbors(row, col)
        # If no neighbors and not all squares are covered, return false
        if not neighbors and count != self.total:
            return False

        # Sort neighbors based on the number of further possible moves (Warnsdorff's rule)
        neighbors.sort(key=lambda x: x[2])

        # Try each neighbor
        for nb in neighbors:
            next_row, next_col = nb[0], nb[1]
            self.grid[next_row][next_col] = count  # Mark the square as visited

            # Check for orphan condition and recursively solve for the next move
            if not self.orphan_detected(count, next_row, next_col) and self.solve(next_row, next_col, count + 1):
                return True  # If solution found, return true

            # Backtrack: unmark the square
            self.grid[next_row][next_col] = 0
        return False  # No solution found

    def get_neighbors(self, row, col):
        neighbors = []
        # Check all possible knight moves
        for m in self.MOVES:
            x, y = row + m[0], col + m[1]
            # If the square is unvisited, add it to the neighbor list
            if self.grid[x][y] == 0:
                neighbors.append((x, y, self.count_neighbors(x, y)))
        return neighbors  # Return the list of neighbors

    def count_neighbors(self, row, col):
        count = 0
        # Check all possible knight moves
        for m in self.MOVES:
            x, y = row + m[0], col + m[1]
            # Increment count if the neighbor is unvisited
            if self.grid[x][y] == 0:
                count += 1
        return count  # Return the count of unvisited neighbors

    def orphan_detected(self, count, row, col):
        # Only check for orphan condition if not all squares are covered
        if count < self.total - 1:
            # Check neighbors of the current square
            for nb in self.get_neighbors(row, col):
                # If any neighbor has no unvisited neighbors, return true
                if self.count_neighbors(nb[0], nb[1]) == 0:
                    return True
        return False  # No orphan detected

    def print_solution(self):
        for r in range(2, self.size + 2):
            for c in range(2, self.size + 2):
                print(f"{self.grid[r][c]:3d}", end=' ')  # Print the grid with formatting
            print()  # New line after each row

def main():
    size = int(input("Enter the size of the board: "))
    start_row = int(input("Enter the starting row: "))
    start_col = int(input("Enter the starting column: "))

    knight_tour = KnightTour(size, start_row, start_col)

    # Attempt to solve the knight's tour and print the result
    if knight_tour.solve(start_row + 2, start_col + 2, 2):
        print("Knight's tour solution:")
        knight_tour.print_solution()
    else:
        print("No solution exists.")  # No solution found

if __name__ == "__main__":
    main()

# <END-OF-CODE>
