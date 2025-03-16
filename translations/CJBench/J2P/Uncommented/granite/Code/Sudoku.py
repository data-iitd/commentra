
import sys
def isSafe(board, row, col, num):
    for d in range(len(board)):
        if board[row][d] == num:
            return False
    for r in range(len(board)):
        if board[r][col] == num:
            return False
    sqrt = int(len(board) ** 0.5)
    boxRowStart = row - row % sqrt
    boxColStart = col - col % sqrt
    for r in range(boxRowStart, boxRowStart + sqrt):
        for d in range(boxColStart, boxColStart + sqrt):
            if board[r][d] == num:
                return False
    return True
def solveMain(board, n):
    row, col = -1, -1
    isEmpty = True
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:
                row, col = i, j
                isEmpty = False
                break
        if not isEmpty:
            break
    if isEmpty:
        return True
    for num in range(1, n + 1):
        if isSafe(board, row, col, num):
            board[row][col] = num
            if solveMain(board, n):
                return True
            else:
                board[row][col] = 0
    return False
def print(board, n):
    for r in range(n):
        for d in range(n):
            sys.stdout.write(str(board[r][d]) + " ")
        sys.stdout.write("\n")
def main():
    n = int(input())
    board = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            board[i][j] = int(input())
    if solveMain(board, n):
        print(board, n)
    else:
        print("No solution")
if __name__ == "__main__":
    main()
