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
    row = -1
    col = -1
    isEmpty = True
    for i in range(len(board)):
        for j in range(len(board)):
            if board[i][j] == 0:
                row = i
                col = j
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

def printBoard(board, n):
    for r in range(n):
        for d in range(n):
            print(board[r][d], end=" ")
        print()

def main():
    n = int(input())
    board = []
    for i in range(n):
        board.append(list(map(int, input().split())))
    if solveMain(board, n):
        printBoard(board, n)
    else:
        print("No solution")

if __name__ == "__main__":
    main()

