
# Final class to prevent instantiation from outside
class Main:
    # Private static variable to keep track of the next tile number
    tile = 1

    # Two dimensional array to store the tiled board
    board = []

    # Method to solve the tiling problem and return the tiled board
    def solveTiling(size, missingRow, missingCol):
        # Initialize the board with given size
        board = [[0 for i in range(size)] for j in range(size)]

        # Recursive method to fill the board with tiles
        fillBoard(size, 0, 0, missingRow, missingCol)

        # Return the filled board
        return board

    # Recursive method to fill the board with tiles
    def fillBoard(size, row, col, missingRow, missingCol):
        # Base case: if size is 1, return
        if size == 1:
            return

        # Half the size of the board
        half = size // 2

        # Tile number to be placed
        t = tile
        tile += 1

        # Check the position of missing tile and fill accordingly
        if missingRow < row + half and missingCol < col + half:
            fillBoard(half, row, col, missingRow, missingCol)  # Top left quadrant
        else:
            # Place the tile at the current position
            board[row + half - 1][col + half - 1] = t

            # Recursively fill the remaining quadrant
            fillBoard(half, row, col, row + half - 1, col + half - 1)  # Top right quadrant

        if missingRow < row + half and missingCol >= col + half:
            fillBoard(half, row, col + half, missingRow, missingCol)  # Bottom left quadrant
        else:
            # Place the tile at the current position
            board[row + half - 1][col + half] = t

            # Recursively fill the remaining quadrant
            fillBoard(half, row, col + half, row + half - 1, col + half)  # Bottom right quadrant

        if missingRow >= row + half and missingCol < col + half:
            fillBoard(half, row + half, col, missingRow, missingCol)  # Left half
        else:
            # Place the tile at the current position
            board[row + half][col + half - 1] = t

            # Recursively fill the remaining half
            fillBoard(half, row + half, col, row + half, col + half - 1)  # Right half

        if missingRow >= row + half and missingCol >= col + half:
            fillBoard(half, row + half, col + half, missingRow, missingCol)  # Top right quadrant
        else:
            # Place the tile at the current position
            board[row + half][col + half] = t

            # Recursively fill the remaining quadrant
            fillBoard(half, row + half, col + half, row + half, col + half)  # Bottom right quadrant

    # Main method to read input and print the tiled board
    def main():
        # Read input size, missing row, and missing column
        size = int(input())
        missingRow = int(input())
        missingCol = int(input())

        # Call the solveTiling method and print the tiled board
        result = solveTiling(size, missingRow, missingCol)
        print("Tiled Board:")
        for i in range(size):
            for j in range(size):
                print(result[i][j], end=" ")
            print()

    # Main method to read input and print the tiled board
    if __name__ == "__main__":
        main()

