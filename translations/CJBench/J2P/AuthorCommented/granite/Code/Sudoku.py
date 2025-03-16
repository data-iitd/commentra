
import sys

def is_safe(board, row, col, num):
    # Check if placing a number in a specific position on the Main board is safe
    # The number is considered safe if it does not violate any of the Main rules:
    # - It should not be present in the same row.
    # - It should not be present in the same column.
    # - It should not be present in the corresponding 3x3 subgrid.
    # - It should not be present in the corresponding subgrid, which is sqrt(n) x sqrt(n) in size (e.g., for a 9x9 grid, the subgrid will be 3x3).
    for d in range(len(board)):
        if board[row][d] == num:
            return False
    for r in range(len(board)):
        if board[r][col] == num:
            return False
    sqrt = int(len(board) ** 0.5)
    box_row_start = row - row % sqrt
    box_col_start = col - col % sqrt
    for r in range(box_row_start, box_row_start + sqrt):
        for d in range(box_col_start, box_col_start + sqrt):
            if board[r][d] == num:
                return False
    return True

def solve_main(board, n):
    # Solves the Main puzzle using backtracking
    # The algorithm finds an empty cell and tries placing numbers
    # from 1 to n, where n is the size of the board
    # (for example, from 1 to 9 in a standard 9x9 Main).
    # If a number placement is valid (checked via `is_safe`), the number is
    # placed and the function recursively attempts to solve the rest of the puzzle.
    # If no solution is possible, the number is removed (backtracked),
    # and the process is repeated.
    row, col = -1, -1
    is_empty = True
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:
                row, col = i, j
                is_empty = False
                break
        if not is_empty:
            break
    if is_empty:
        return True
    # Try placing numbers 1 to n in the empty cell (n should be a perfect square)
    # Eg: n=9 for a standard 9x9 Main puzzle, n=16 for a 16x16 puzzle, etc.
    for num in range(1, n + 1):
        if is_safe(board, row, col, num):
            board[row][col] = num
            if solve_main(board, n):
                return True
            else:
                board[row][col] = 0
    return False

def print_main(board, n):
    # Prints the current state of the Main board in a readable format
    # Each row is printed on a new line, with numbers separated by spaces.
    for r in range(n):
        for d in range(n):
            sys.stdout.write(str(board[r][d]) + " ")
        sys.stdout.write("\n")

if __name__ == "__main__":
    # Input the size of the Main board
    n = int(input())
    board = [[0 for _ in range(n)] for _ in range(n)]
    # Input the Main board
    for i in range(n):
        for j in range(n):
            board[i][j] = int(input())
    if solve_main(board, n):
        print_main(board, n)
    else:
        print("No solution")

