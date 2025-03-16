import math

# Function to check if it's safe to place a number in the given cell
def is_safe(board, row, col, num):
    # Check if the number is already present in the current row
    for d in range(len(board)):
        if board[row][d] == num:
            return False  # Number found in the row
    # Check if the number is already present in the current column
    for r in range(len(board)):
        if board[r][col] == num:
            return False  # Number found in the column
    # Determine the size of the sub-grid
    sqrt = int(math.sqrt(len(board)))
    # Calculate the starting row and column indices of the sub-grid
    box_row_start = row - row % sqrt
    box_col_start = col - col % sqrt
    # Check if the number is present in the current sub-grid
    for r in range(box_row_start, box_row_start + sqrt):
        for d in range(box_col_start, box_col_start + sqrt):
            if board[r][d] == num:
                return False  # Number found in the sub-grid
    return True  # Number can be placed safely

# Function to solve the puzzle using backtracking
def solve_main(board, n):
    row, col = -1, -1  # Variables to store the row and column of an empty cell
    is_empty = True  # Flag to check if an empty cell is found

    # Find an empty cell in the board
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:  # Check for an empty cell
                row, col = i, j
                is_empty = False  # Mark that an empty cell is found
                break
        if not is_empty:
            break  # Exit if an empty cell is found
    # If no empty cell is found, the puzzle is solved
    if is_empty:
        return True

    # Try placing numbers from 1 to n in the empty cell
    for num in range(1, n + 1):
        # Check if it's safe to place the number
        if is_safe(board, row, col, num):
            board[row][col] = num  # Place the number
            # Recursively attempt to solve the rest of the board
            if solve_main(board, n):
                return True  # Puzzle solved
            else:
                board[row][col] = 0  # Backtrack if placing the number didn't lead to a solution
    return False  # No solution found

# Function to print the board
def print_board(board, n):
    for r in range(n):
        for d in range(n):
            print(board[r][d], end=" ")  # Print each number in the row
        print()  # Move to the next line after each row

# Main function to execute the program
if __name__ == "__main__":
    n = int(input())  # Read the size of the board
    board = [[0] * n for _ in range(n)]  # Initialize the board

    # Read the board configuration from input
    for i in range(n):
        board[i] = list(map(int, input().split()))  # Fill the board with user input

    # Attempt to solve the puzzle
    if solve_main(board, n):
        print_board(board, n)  # Print the solved board
    else:
        print("No solution")  # Inform the user if no solution exists
