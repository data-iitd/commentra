import sys

# Function to check if it's safe to place a number in the given cell
def isSafe(board, row, col, num):
    # Check if the number is already present in the current row
    for d in range(len(board)):
        if board[row][d] == num:
            return False # Number found in the row
    # Check if the number is already present in the current column
    for r in range(len(board)):
        if board[r][col] == num:
            return False # Number found in the column
    # Determine the size of the sub-grid
    sqrt = int(len(board) ** 0.5)
    # Calculate the starting row and column indices of the sub-grid
    boxRowStart = row - row % sqrt
    boxColStart = col - col % sqrt
    # Check if the number is present in the current sub-grid
    for r in range(boxRowStart, boxRowStart + sqrt):
        for d in range(boxColStart, boxColStart + sqrt):
            if board[r][d] == num:
                return False # Number found in the sub-grid
    return True # Number can be placed safely

# Function to solve the Main puzzle using backtracking
def solveMain(board, n):
    row = -1 # Variables to store the row and column of an empty cell
    col = -1
    isEmpty = True # Flag to check if an empty cell is found

    # Find an empty cell in the board
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 0: # Check for an empty cell
                row = i
                col = j
                isEmpty = False # Mark that an empty cell is found
                break
        if not isEmpty:
            break # Exit if an empty cell is found
    # If no empty cell is found, the puzzle is solved
    if isEmpty:
        return True

    # Try placing numbers from 1 to n in the empty cell
    for num in range(1, n + 1):
        # Check if it's safe to place the number
        if isSafe(board, row, col, num):
            board[row][col] = num # Place the number
            # Recursively attempt to solve the rest of the board
            if solveMain(board, n):
                return True # Puzzle solved
            else:
                board[row][col] = 0 # Backtrack if placing the number didn't lead to a solution
        return False # No solution found

# Function to print the Main board
def print(board, n):
    for r in range(len(board)):
        for d in range(len(board)):
            print(board[r][d], end=" ") # Print each number in the row
        print() # Move to the next line after each row

# Main function to execute the program
def main():
    n = int(input()) # Read the size of the board
    board = [] # Initialize the board

    # Read the board configuration from input
    for i in range(n):
        board.append(list(map(int, input().split())))

    # Attempt to solve the Main puzzle
    if solveMain(board, n):
        print(board, n) # Print the solved board
    else:
        print("No solution") # Inform the user if no solution exists

if __name__ == "__main__":
    main()

