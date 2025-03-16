class Tiling:
    def __init__(self):
        self.tile = 1
        self.board = []

    def solve_tiling(self, size, missing_row, missing_col):
        # Initialize the board with given size
        self.board = [[0] * size for _ in range(size)]
        # Recursive method to fill the board with tiles
        self.fill_board(size, 0, 0, missing_row, missing_col)
        # Return the filled board
        return self.board

    def fill_board(self, size, row, col, missing_row, missing_col):
        # Base case: if size is 1, return
        if size == 1:
            return

        # Half the size of the board
        half = size // 2

        # Tile number to be placed
        t = self.tile
        self.tile += 1

        # Check the position of missing tile and fill accordingly
        if missing_row < row + half and missing_col < col + half:
            self.fill_board(half, row, col, missing_row, missing_col)  # Top left quadrant
        else:
            # Place the tile at the current position
            self.board[row + half - 1][col + half - 1] = t
            # Recursively fill the remaining quadrant
            self.fill_board(half, row, col, row + half - 1, col + half - 1)  # Top right quadrant

        if missing_row < row + half and missing_col >= col + half:
            self.fill_board(half, row, col + half, missing_row, missing_col)  # Bottom left quadrant
        else:
            # Place the tile at the current position
            self.board[row + half - 1][col + half] = t
            # Recursively fill the remaining quadrant
            self.fill_board(half, row, col + half, row + half - 1, col + half)  # Bottom right quadrant

        if missing_row >= row + half and missing_col < col + half:
            self.fill_board(half, row + half, col, missing_row, missing_col)  # Left half
        else:
            # Place the tile at the current position
            self.board[row + half][col + half - 1] = t
            # Recursively fill the remaining half
            self.fill_board(half, row + half, col, row + half, col + half - 1)  # Right half

        if missing_row >= row + half and missing_col >= col + half:
            self.fill_board(half, row + half, col + half, missing_row, missing_col)  # Top right quadrant
        else:
            # Place the tile at the current position
            self.board[row + half][col + half] = t
            # Recursively fill the remaining quadrant
            self.fill_board(half, row + half, col + half, row + half, col + half)  # Bottom right quadrant


if __name__ == "__main__":
    # Read input size, missing row, and missing column
    size = int(input("Enter the size of the board: "))
    missing_row = int(input("Enter the missing row: "))
    missing_col = int(input("Enter the missing column: "))

    # Create an instance of Tiling and call the solve_tiling method
    tiling = Tiling()
    result = tiling.solve_tiling(size, missing_row, missing_col)

    # Print the tiled board
    print("Tiled Board:")
    for row in result:
        print(" ".join(map(str, row)))

# <END-OF-CODE>
