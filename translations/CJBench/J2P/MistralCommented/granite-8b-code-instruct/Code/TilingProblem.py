

import sys

# Final class to prevent instantiation from outside
class Main:
    def __init__(self):
        pass

    # Private static variable to keep track of the next tile number
    tile = 1

    # Two dimensional array to store the tiled board
    board = []

    # Method to solve the tiling problem and return the tiled board
    @staticmethod
    def solve_tiling(size, missing_row, missing_col):
        # Initialize the board with given size
        Main.board = [[0 for _ in range(size)] for _ in range(size)]

        # Recursive method to fill the board with tiles
        Main.fill_board(size, 0, 0, missing_row, missing_col)

        # Return the filled board
        return Main.board

    # Recursive method to fill the board with tiles
    @staticmethod
    def fill_board(size, row, col, missing_row, missing_col):
        # Base case: if size is 1, return
        if size == 1:
            return

        # Half the size of the board
        half = size // 2

        # Tile number to be placed
        t = Main.tile
        Main.tile += 1

        # Check the position of missing tile and fill accordingly
        if missing_row < row + half and missing_col < col + half:
            Main.fill_board(half, row, col, missing_row, missing_col) # Top left quadrant
        else:
            # Place the tile at the current position
            Main.board[row + half - 1][col + half - 1] = t

            # Recursively fill the remaining quadrant
            Main.fill_board(half, row, col, row + half - 1, col + half - 1) # Top right quadrant

        if missing_row < row + half and missing_col >= col + half:
            Main.fill_board(half, row, col + half, missing_row, missing_col) # Bottom left quadrant
        else:
            # Place the tile at the current position
            Main.board[row + half - 1][col + half] = t

            # Recursively fill the remaining quadrant
            Main.fill_board(half, row, col + half, row + half - 1, col + half) # Bottom right quadrant

        if missing_row >= row + half and missing_col < col + half:
            Main.fill_board(half, row + half, col, missing_row, missing_col) # Left half
        else:
            # Place the tile at the current position
            Main.board[row + half][col + half - 1] = t

            # Recursively fill the remaining half
            Main.fill_board(half, row + half, col, row + half, col + half - 1) # Right half

        if missing_row >= row + half and missing_col >= col + half:
            Main.fill_board(half, row + half, col + half, missing_row, missing_col) # Top right quadrant
        else:
            # Place the tile at the current position
            Main.board[row + half][col + half] = t

            # Recursively fill the remaining quadrant
            Main.fill_board(half, row + half, col + half, row + half, col + half) # Bottom right quadrant

    # Main method to read input and print the tiled board
    @staticmethod
    def main():
        # Read input size, missing row, and missing column
        size, missing_row, missing_col = map(int, sys.stdin.readline().split())

        # Call the solve_tiling method and print the tiled board
        result = Main.solve_tiling(size, missing_row, missing_col)
        print("Tiled Board:")
        for row in result:
            print(" ".join(map(str, row)))

# Call the main method
Main.main()

# End of code