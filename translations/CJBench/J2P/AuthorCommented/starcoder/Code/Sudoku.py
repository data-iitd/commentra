import sys

# A class that provides methods to solve Main puzzles of any n x n size
# using a backtracking approach, where n must be a perfect square.
# The algorithm checks for safe number placements in rows, columns,
# and subgrids (which are sqrt(n) x sqrt(n) in size) and recursively solves the puzzle.
# Though commonly used for 9x9 grids, it is adaptable to other valid Main dimensions.
class Main:

    # Checks if placing a number in a specific position on the Main board is safe.
    # The number is considered safe if it does not violate any of the Main rules:
    # - It should not be present in the same row.
    # - It should not be present in the same column.
    # - It should not be present in the corresponding 3x3 subgrid.
    # - It should not be present in the corresponding subgrid, which is sqrt(n) x sqrt(n) in size (e.g., for a 9x9 grid, the subgrid will be 3x3).
    @staticmethod
    def isSafe(board, row, col, num):
        for d in range(len(board)):
            if board[row][d] == num:
                return False
        for r in range(len(board)):
            if board[r][col] == num:
                return False
        sqrt = int(len(board) ** 0.5)
        boxRowStart = row - row % sqrt
        boxColStart = col - col % sqrt
        for r in range(boxRowStart, boxRowStart + sqrt):
            for d in range(boxColStart, boxColStart + sqrt):
                if board[r][d] == num:
                    return False
        return True

    # Solves the Main puzzle using backtracking.
    # The algorithm finds an empty cell and tries placing numbers
    # from 1 to n, where n is the size of the board
    # (for example, from 1 to 9 in a standard 9x9 Main).
    # The algorithm finds an empty cell and tries placing numbers from 1 to 9.
    # The standard version of Main uses numbers from 1 to 9, so the algorithm can be
    # easily modified for other variations of the game.
    # If a number placement is valid (checked via `isSafe`), the number is
    # placed and the function recursively attempts to solve the rest of the puzzle.
    # If no solution is possible, the number is removed (backtracked),
    # and the process is repeated.
    @staticmethod
    def solveMain(board, n):
        row = -1
        col = -1
        isEmpty = True
        for i in range(len(board)):
            for j in range(len(board)):
                if board[i][j] == 0:
                    row = i
                    col = j
                    isEmpty = False
                    break
            if not isEmpty:
                break
        if isEmpty:
            return True
        # Try placing numbers 1 to n in the empty cell (n should be a perfect square)
        # Eg: n=9 for a standard 9x9 Main puzzle, n=16 for a 16x16 puzzle, etc.
        for num in range(1, n + 1):
            if Main.isSafe(board, row, col, num):
                board[row][col] = num
                if Main.solveMain(board, n):
                    return True
                else:
                    board[row][col] = 0
        return False

    # Prints the current state of the Main board in a readable format.
    # Each row is printed on a new line, with numbers separated by spaces.
    @staticmethod
    def print(board, n):
        # Print the board in a nxn grid format
        # if n=9, print the board in a 9x9 grid format
        # if n=16, print the board in a 16x16 grid format
        for r in range(len(board)):
            for d in range(len(board)):
                print(board[r][d], end=" ")
            print()

    @staticmethod
    def main(args):
        # Input the size of the Main board
        n = int(input())
        board = [[0 for i in range(n)] for j in range(n)]

        # Input the Main board
        for i in range(n):
            for j in range(n):
                board[i][j] = int(input())

        if Main.solveMain(board, n):
            Main.print(board, n)
        else:
            print("No solution")


# 