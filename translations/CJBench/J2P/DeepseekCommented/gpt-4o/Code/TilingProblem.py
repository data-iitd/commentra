class Main:
    # Static variable to keep track of the tile number
    tile = 1
    # 2D list to represent the board
    board = []

    # Method to solve the tiling problem
    @staticmethod
    def solve_tiling(size, missing_row, missing_col):
        # Initialize the board with the given size
        Main.board = [[0] * size for _ in range(size)]
        # Start filling the board recursively
        Main.fill_board(size, 0, 0, missing_row, missing_col)
        return Main.board  # Return the completed board

    # Recursive method to fill the board with tiles
    @staticmethod
    def fill_board(size, row, col, missing_row, missing_col):
        # Base case: if the size of the board is 1, return
        if size == 1:
            return

        # Calculate half the size of the current board
        half = size // 2
        # Get the current tile number and increment it for the next tile
        t = Main.tile
        Main.tile += 1

        # Check if the missing tile is in the top-left quadrant
        if missing_row < row + half and missing_col < col + half:
            Main.fill_board(half, row, col, missing_row, missing_col)  # Recur for the top-left quadrant
        else:
            # Place a tile in the center of the top-left quadrant
            Main.board[row + half - 1][col + half - 1] = t
            Main.fill_board(half, row, col, row + half - 1, col + half - 1)  # Recur for the top-left quadrant

        # Check if the missing tile is in the top-right quadrant
        if missing_row < row + half and missing_col >= col + half:
            Main.fill_board(half, row, col + half, missing_row, missing_col)  # Recur for the top-right quadrant
        else:
            # Place a tile in the center of the top-right quadrant
            Main.board[row + half - 1][col + half] = t
            Main.fill_board(half, row, col + half, row + half - 1, col + half)  # Recur for the top-right quadrant

        # Check if the missing tile is in the bottom-left quadrant
        if missing_row >= row + half and missing_col < col + half:
            Main.fill_board(half, row + half, col, missing_row, missing_col)  # Recur for the bottom-left quadrant
        else:
            # Place a tile in the center of the bottom-left quadrant
            Main.board[row + half][col + half - 1] = t
            Main.fill_board(half, row + half, col, row + half, col + half - 1)  # Recur for the bottom-left quadrant

        # Check if the missing tile is in the bottom-right quadrant
        if missing_row >= row + half and missing_col >= col + half:
            Main.fill_board(half, row + half, col + half, missing_row, missing_col)  # Recur for the bottom-right quadrant
        else:
            # Place a tile in the center of the bottom-right quadrant
            Main.board[row + half][col + half] = t
            Main.fill_board(half, row + half, col + half, row + half, col + half)  # Recur for the bottom-right quadrant

    # Main method to execute the program
    @staticmethod
    def main():
        # Create a scanner to read input
        scanner = Scanner(System.in)
        # Read the size of the board and the position of the missing tile
        size = scanner.nextInt()
        missing_row = scanner.nextInt()
        missing_col = scanner.nextInt()
        # Solve the tiling problem and get the result
        result = Main.solve_tiling(size, missing_row, missing_col)
        # Print the tiled board
        print("Tiled Board:")
        for i in range(size):
            for j in range(size):
                print(result[i][j], end=" ")  # Print each tile number
            print()  # Move to the next line after each row
        scanner.close()  # Close the scanner

# Import the Scanner class from the java.util package
from java.util import Scanner

# Execute the main method
Main.main()
