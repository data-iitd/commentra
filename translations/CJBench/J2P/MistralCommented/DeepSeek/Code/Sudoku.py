def is_safe(board, row, col, num, n):
    # Check row
    for d in range(n):
        if board[row][d] == num:
            return False

    # Check column
    for r in range(n):
        if board[r][col] == num:
            return False

    # Check box
    sqrt = int(n**0.5)
    box_row_start = row - row % sqrt
    box_col_start = col - col % sqrt
    for r in range(box_row_start, box_row_start + sqrt):
        for d in range(box_col_start, box_col_start + sqrt):
            if board[r][d] == num:
                return False

    return True

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
        if is_safe(board, row, col, num, n):
            board[row][col] = num
            # Recursively solve the puzzle
            if solve_main(board, n):
                return True
            else:
                # Backtrack if the recursive call fails
                board[row][col] = 0

    return False

def print_board(board, n):
    for r in range(n):
        for d in range(n):
            print(board[r][d], end=" ")
        print()

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    index = 1
    board = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            board[i][j] = int(data[index])
            index += 1

    if solve_main(board, n):
        print_board(board, n)
    else:
        print("No solution")

if __name__ == "__main__":
    main()
