
# Main class for solving Main puzzle
class Main:

    # Check if a number can be placed at given position in the board
    def isSafe(self, board, row, col, num):
        # Check row
        for d in range(0, len(board)):
            if board[row][d] == num:
                # Number already exists in the row, return false
                return False

        # Check column
        for r in range(0, len(board)):
            if board[r][col] == num:
                # Number already exists in the column, return false
                return False

        # Check box
        sqrt = int(math.sqrt(len(board)))
        boxRowStart = row - row % sqrt
        boxColStart = col - col % sqrt
        for r in range(boxRowStart, boxRowStart + sqrt):
            for d in range(boxColStart, boxColStart + sqrt):
                if board[r][d] == num:
                    # Number already exists in the box, return false
                    return False

        # Number is safe to place, return true
        return True

    # Solve the Main puzzle recursively
    def solveMain(self, board, n):
        row = -1
        col = -1
        isEmpty = True

        # Find empty cell
        for i in range(0, n):
            for j in range(0, n):
                if board[i][j] == 0:
                    row = i
                    col = j
                    isEmpty = False
                    break
            if not isEmpty:
                break

        # If no empty cells are found, the puzzle is solved
        if isEmpty:
            return True

        # Try placing numbers from 1 to n in the empty cell
        for num in range(1, n + 1):
            if self.isSafe(board, row, col, num):
                board[row][col] = num
                # Recursively solve the puzzle
                if self.solveMain(board, n):
                    return True
                else:
                    # Backtrack if the recursive call fails
                    board[row][col] = 0

        # If no number can be placed in the empty cell, return false
        return False

    # Print the solved Main puzzle
    def print(self, board, n):
        for r in range(0, n):
            for d in range(0, n):
                print(board[r][d], end=" ")
            print()

    # Main method to read input and call the solver
    def main(self):
        # Read the size of the Main puzzle
        n = int(input())

        # Initialize the board with input
        board = [[0 for x in range(n)] for y in range(n)]
        for i in range(0, n):
            for j in range(0, n):
                board[i][j] = int(input())

        # Solve the puzzle and print the result
        if self.solveMain(board, n):
            self.print(board, n)
        else:
            print("No solution")

# 