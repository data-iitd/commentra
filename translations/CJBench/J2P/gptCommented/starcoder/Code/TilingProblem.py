# <START-OF-CODE>

# Private constructor to prevent instantiation of the class
class Main:
    # Static variable to keep track of the tile number
    tile = 1
    # 2D array to represent the board
    board = None

    # Method to solve the tiling problem
    def solveTiling(self, size, missingRow, missingCol):
        # Initialize the board with the given size
        self.board = [[0 for i in range(size)] for j in range(size)]
        # Start filling the board recursively
        self.fillBoard(size, 0, 0, missingRow, missingCol)
        return self.board # Return the completed board

    # Recursive method to fill the board with tiles
    def fillBoard(self, size, row, col, missingRow, missingCol):
        # Base case: if the size of the board is 1, return
        if size == 1:
            return

        # Calculate half the size of the current board
        half = size // 2
        # Get the current tile number and increment it for the next tile
        t = self.tile
        self.tile += 1

        # Check if the missing tile is in the top-left quadrant
        if missingRow < row + half and missingCol < col + half:
            self.fillBoard(half, row, col, missingRow, missingCol) # Recur for the top-left quadrant
        else:
            # Place a tile in the center of the top-left quadrant
            self.board[row + half - 1][col + half - 1] = t
            self.fillBoard(half, row, col, row + half - 1, col + half - 1) # Recur for the top-left quadrant

        # Check if the missing tile is in the top-right quadrant
        if missingRow < row + half and missingCol >= col + half:
            self.fillBoard(half, row, col + half, missingRow, missingCol) # Recur for the top-right quadrant
        else:
            # Place a tile in the center of the top-right quadrant
            self.board[row + half - 1][col + half] = t
            self.fillBoard(half, row, col + half, row + half - 1, col + half) # Recur for the top-right quadrant

        # Check if the missing tile is in the bottom-left quadrant
        if missingRow >= row + half and missingCol < col + half:
            self.fillBoard(half, row + half, col, missingRow, missingCol) # Recur for the bottom-left quadrant
        else:
            # Place a tile in the center of the bottom-left quadrant
            self.board[row + half][col + half - 1] = t
            self.fillBoard(half, row + half, col, row + half, col + half - 1) # Recur for the bottom-left quadrant

        # Check if the missing tile is in the bottom-right quadrant
        if missingRow >= row + half and missingCol >= col + half:
            self.fillBoard(half, row + half, col + half, missingRow, missingCol) # Recur for the bottom-right quadrant
        else:
            # Place a tile in the center of the bottom-right quadrant
            self.board[row + half][col + half] = t
            self.fillBoard(half, row + half, col + half, row + half, col + half) # Recur for the bottom-right quadrant

    # Main method to execute the program
    def main(self):
        # Create a scanner to read input
        scanner = Scanner(System.in)
        # Read the size of the board and the position of the missing tile
        size = scanner.nextInt()
        missingRow = scanner.nextInt()
        missingCol = scanner.nextInt()
        # Solve the tiling problem and get the result
        result = self.solveTiling(size, missingRow, missingCol)
        # Print the tiled board
        print("Tiled Board:")
        for i in range(size):
            for j in range(size):
                print(result[i][j], end=" ") # Print each tile number
            print() # Move to the next line after each row
        scanner.close() # Close the scanner

# 