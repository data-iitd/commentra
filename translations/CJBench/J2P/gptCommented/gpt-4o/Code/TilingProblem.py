class TilingSolver:
    def __init__(self):
        self.tile = 1  # Static variable to keep track of the tile number
        self.board = []  # 2D list to represent the board

    def solve_tiling(self, size, missing_row, missing_col):
        # Initialize the board with the given size
        self.board = [[0] * size for _ in range(size)]
        # Start filling the board recursively
        self.fill_board(size, 0, 0, missing_row, missing_col)
        return self.board  # Return the completed board

    def fill_board(self, size, row, col, missing_row, missing_col):
        # Base case: if the size of the board is 1, return
        if size == 1:
            return

        half = size // 2  # Calculate half the size of the current board
        t = self.tile  # Get the current tile number
        self.tile += 1  # Increment for the next tile

        # Check if the missing tile is in the top-left quadrant
        if missing_row < row + half and missing_col < col + half:
            self.fill_board(half, row, col, missing_row, missing_col)  # Recur for the top-left quadrant
        else:
            # Place a tile in the center of the top-left quadrant
            self.board[row + half - 1][col + half - 1] = t
            self.fill_board(half, row, col, row + half - 1, col + half - 1)  # Recur for the top-left quadrant

        # Check if the missing tile is in the top-right quadrant
        if missing_row < row + half and missing_col >= col + half:
            self.fill_board(half, row, col + half, missing_row, missing_col)  # Recur for the top-right quadrant
        else:
            # Place a tile in the center of the top-right quadrant
            self.board[row + half - 1][col + half] = t
            self.fill_board(half, row, col + half, row + half - 1, col + half)  # Recur for the top-right quadrant

        # Check if the missing tile is in the bottom-left quadrant
        if missing_row >= row + half and missing_col < col + half:
            self.fill_board(half, row + half, col, missing_row, missing_col)  # Recur for the bottom-left quadrant
        else:
            # Place a tile in the center of the bottom-left quadrant
            self.board[row + half][col + half - 1] = t
            self.fill_board(half, row + half, col, row + half, col + half - 1)  # Recur for the bottom-left quadrant

        # Check if the missing tile is in the bottom-right quadrant
        if missing_row >= row + half and missing_col >= col + half:
            self.fill_board(half, row + half, col + half, missing_row, missing_col)  # Recur for the bottom-right quadrant
        else:
            # Place a tile in the center of the bottom-right quadrant
            self.board[row + half][col + half] = t
            self.fill_board(half, row + half, col + half, row + half, col + half)  # Recur for the bottom-right quadrant

if __name__ == "__main__":
    size = int(input("Enter the size of the board: "))  # Read the size of the board
    missing_row = int(input("Enter the missing row: "))  # Read the position of the missing tile
    missing_col = int(input("Enter the missing column: "))  # Read the position of the missing tile

    solver = TilingSolver()  # Create an instance of the TilingSolver
    result = solver.solve_tiling(size, missing_row, missing_col)  # Solve the tiling problem

    # Print the tiled board
    print("Tiled Board:")
    for row in result:
        print(" ".join(map(str, row)))  # Print each tile number

# <END-OF-CODE>
