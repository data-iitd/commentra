import math

def is_safe(board, row, col, num, n):
    for d in range(n):
        if board[row][d] == num:
            return False

    for r in range(n):
        if board[r][col] == num:
            return False

    sqrt_n = int(math.sqrt(n))
    box_row_start = row - row % sqrt_n
    box_col_start = col - col % sqrt_n

    for r in range(box_row_start, box_row_start + sqrt_n):
        for d in range(box_col_start, box_col_start + sqrt_n):
            if board[r][d] == num:
                return False

    return True

def solve_main(board, n):
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

    for num in range(1, n + 1):
        if is_safe(board, row, col, num, n):
            board[row][col] = num
            if solve_main(board, n):
                return True
            else:
                board[row][col] = 0

    return False

def print_board(board, n):
    for r in range(n):
        for d in range(n):
            print(board[r][d], end=" ")
        print()

def main():
    n = int(input())
    board = []

    for i in range(n):
        row = list(map(int, input().split()))
        board.append(row)

    if solve_main(board, n):
        print_board(board, n)
    else:
        print("No solution")

if __name__ == "__main__":
    main()
