
import math

# Check if a number can be placed at given position in the board
def isSafe(board, row, col, num):
    # Check row
    for d in range(len(board)):
        if board[row][d] == num:
            # Number already exists in the row, return false
            return False

    # Check column
    for r in range(len(board)):
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
def solveMain(board, n):
    row = -1
    col = -1
    isEmpty = True

    # Find empty cell
    for i in range(n):
        for j in range(n):
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
        if isSafe(board, row, col, num):
            board[row][col] = num
            # Recursively solve the puzzle
            if solveMain(board, n):
                return True
            else:
                # Backtrack if the recursive call fails
                board[row][col] = 0

    # If no number can be placed in the empty cell, return false
    return False

# Print the solved Main puzzle
def print(board, n):
    for r in range(n):
        for d in range(n):
            print(board[r][d], end=" ")
        print()

# Main method to read input and call the solver
def main():
    # Read the size of the Main puzzle
    n = int(input())

    # Initialize the board with input
    board = []
    for i in range(n):
        board.append([int(x) for x in input().split()])

    # Solve the puzzle and print the result
    if solveMain(board, n):
        print(board, n)
    else:
        print("No solution")

# Close the scanner
# scanner.close()

# END-OF-CODE
