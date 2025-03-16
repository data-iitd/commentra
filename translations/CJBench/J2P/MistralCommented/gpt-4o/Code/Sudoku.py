import math

# Check if a number can be placed at given position in the board
def is_safe(board, row, col, num):
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
    box_row_start = row - row % sqrt
    box_col_start = col - col % sqrt
    for r in range(box_row_start, box_row_start + sqrt):
        for d in range(box_col_start, box_col_start + sqrt):
            if board[r][d] == num:
                # Number already exists in the box, return false
                return False

    # Number is safe to place, return true
    return True

# Solve the puzzle recursively
def solve_main(board, n):
    row, col = -1, -1
    is_empty = True

    # Find empty cell
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:
                row, col = i, j
                is_empty = False
                break
        if not is_empty:
            break

    # If no empty cells are found, the puzzle is solved
    if is_empty:
        return True

    # Try placing numbers from 1 to n in the empty cell
    for num in range(1, n + 1):
        if is_safe(board, row, col, num):
            board[row][col] = num
            # Recursively solve the puzzle
            if solve_main(board, n):
                return True
            else:
                # Backtrack if the recursive call fails
                board[row][col] = 0

    # If no number can be placed in the empty cell, return false
    return False

# Print the solved puzzle
def print_board(board, n):
    for r in range(n):
        for d in range(n):
            print(board[r][d], end=" ")
        print()

# Main function to read input and call the solver
def main():
    n = int(input("Enter the size of the puzzle: "))

    # Initialize the board with input
    board = []
    for i in range(n):
        row = list(map(int, input().split()))
        board.append(row)

    # Solve the puzzle and print the result
    if solve_main(board, n):
        print_board(board, n)
    else:
        print("No solution")

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
