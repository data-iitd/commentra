
import sys

# Private constructor to prevent instantiation
class Main:
    # Constant for the base size of the grid
    BASE = 12

    # Possible moves for the knight in chess
    MOVES = [
        (1, -2), (2, -1), (2, 1), (1, 2),
        (-1, 2), (-2, 1), (-2, -1), (-1, -2),
    ]

    # 2D array to represent the chessboard
    grid = []
    # Total number of squares to be covered by the knight
    total = 0

    # Method to reset the chessboard with a given size
    @staticmethod
    def reset_board(size):
        # Initialize the grid with additional padding
        Main.grid = [[0] * (size + 4) for _ in range(size + 4)]
        Main.total = size * size
        # Set the outer border of the grid to -1 (indicating invalid squares)
        for r in range(len(Main.grid)):
            for c in range(len(Main.grid[0])):
                if r < 2 or r >= len(Main.grid) - 2 or c < 2 or c >= len(Main.grid[0]) - 2:
                    Main.grid[r][c] = -1

    # Recursive method to solve the knight's tour problem
    @staticmethod
    def solve(row, col, count):
        # If all squares are covered, return true
        if count > Main.total:
            return True

        # Get the list of valid neighboring moves
        neighbors = Main.neighbors(row, col)
        # If no neighbors and not all squares are covered, return false
        if not neighbors and count!= Main.total:
            return False

        # Sort neighbors based on the number of further possible moves (Warnsdorff's rule)
        neighbors.sort(key=lambda nb: nb[2])

        # Try each neighbor
        for nb in neighbors:
            next_row, next_col = nb[0], nb[1]
            Main.grid[next_row][next_col] = count  # Mark the square as visited

            # Check for orphan condition and recursively solve for the next move
            if not Main.orphan_detected(count, next_row, next_col) and Main.solve(next_row, next_col, count + 1):
                return True  # If solution found, return true

            # Backtrack: unmark the square
            Main.grid[next_row][next_col] = 0

        return False  # No solution found

    # Method to find valid neighboring squares for the knight's next move
    @staticmethod
    def neighbors(row, col):
        neighbors = []
        # Check all possible knight moves
        for m in Main.MOVES:
            x, y = row + m[0], col + m[1]
            # If the square is unvisited, add it to the neighbor list
            if Main.grid[x][y] == 0:
                neighbors.append((x, y, Main.count_neighbors(x, y)))
        return neighbors  # Return the list of neighbors

    # Method to count how many unvisited neighbors a square has
    @staticmethod
    def count_neighbors(row, col):
        count = 0
        # Check all possible knight moves
        for m in Main.MOVES:
            x, y = row + m[0], col + m[1]
            # Increment count if the neighbor is unvisited
            if Main.grid[x][y] == 0:
                count += 1
        return count  # Return the count of unvisited neighbors

    # Method to detect if moving to a square creates an orphan situation
    @staticmethod
    def orphan_detected(count, row, col):
        # Only check for orphan condition if not all squares are covered
        if count < Main.total - 1:
            # Check neighbors of the current square
            for nb in Main.neighbors(row, col):
                # If any neighbor has no unvisited neighbors, return true
                if Main.count_neighbors(nb[0], nb[1]) == 0:
                    return True
        return False  # No orphan detected

    # Method to print the solution of the knight's tour
    @staticmethod
    def print_solution(size):
        for r in range(2, size + 2):
            for c in range(2, size + 2):
                sys.stdout.write(f"{Main.grid[r][c]:3d}")  # Print the grid with formatting
            sys.stdout.write("\n")  # New line after each row

    # Main method to execute the knight's tour algorithm
    @staticmethod
    def main():
        size, start_row, start_col = map(int, input().split())  # Read the size of the board and starting position from user input

        # Reset the board and mark the starting position
        Main.reset_board(size)
        Main.grid[start_row + 2][start_col + 2] = 1

        # Attempt to solve the knight's tour and print the result
        if Main.solve(start_row + 2, start_col + 2, 2):
            print("Knight's tour solution:")
            Main.print_solution(size)
        else:
            print("No solution exists.")  # No solution found

# Call the main method to execute the knight's tour algorithm
Main.main()

