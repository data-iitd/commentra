import math

class Main:
    @staticmethod
    def is_safe(board, row, col, num):
        # Check if the number is present in the same row
        for d in range(len(board)):
            if board[row][d] == num:
                return False

        # Check if the number is present in the same column
        for r in range(len(board)):
            if board[r][col] == num:
                return False

        # Check the corresponding subgrid
        sqrt_n = int(math.sqrt(len(board)))
        box_row_start = row - row % sqrt_n
        box_col_start = col - col % sqrt_n

        for r in range(box_row_start, box_row_start + sqrt_n):
            for d in range(box_col_start, box_col_start + sqrt_n):
                if board[r][d] == num:
                    return False

        return True

    @staticmethod
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

        # Try placing numbers 1 to n in the empty cell
        for num in range(1, n + 1):
            if Main.is_safe(board, row, col, num):
                board[row][col] = num
                if Main.solve_main(board, n):
                    return True
                else:
                    board[row][col] = 0

        return False

    @staticmethod
    def print_board(board, n):
        for r in range(n):
            for d in range(n):
                print(board[r][d], end=" ")
            print()

if __name__ == "__main__":
    n = int(input("Enter the size of the Main board: "))
    board = []

    # Input the Main board
    for i in range(n):
        row = list(map(int, input().split()))
        board.append(row)

    if Main.solve_main(board, n):
        Main.print_board(board, n)
    else:
        print("No solution")

# <END-OF-CODE>
