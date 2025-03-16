
import math


def is_safe(board, row, col, num):
    for d in range(len(board)):
        if board[row][d] == num:
            return False

    for r in range(len(board)):
        if board[r][col] == num:
            return False

    sqrt = int(math.sqrt(len(board)))
    box_row_start = row - row % sqrt
    box_col_start = col - col % sqrt

    for r in range(box_row_start, box_row_start + sqrt):
        for d in range(box_col_start, box_col_start + sqrt):
            if board[r][d] == num:
                return False

    return True


def solve_main(board, n):
    row = -1
    col = -1
    is_empty = True

    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:
                row = i
                col = j
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


def print_board(board, n):
    # Print the board in a nxn grid format
    # if n=9, print the board in a 9x9 grid format
    # if n=16, print the board in a 16x16 grid format
    for r in range(n):
        for d in range(n):
            print(board[r][d], end=" ")
        print()


def main():
    n = int(input())
    board = [[0] * n for _ in range(n)]

    # Input the Main board
    for i in range(n):
        for j in range(n):
            board[i][j] = int(input())

    if solve_main(board, n):
        print_board(board, n)
    else:
        print("No solution")


if __name__ == "__main__":
    main()

