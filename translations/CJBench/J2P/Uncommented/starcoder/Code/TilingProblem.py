
import sys

def solveTiling(size, missingRow, missingCol):
    board = [[0 for i in range(size)] for j in range(size)]
    fillBoard(size, 0, 0, missingRow, missingCol)
    return board

def fillBoard(size, row, col, missingRow, missingCol):
    if size == 1:
        return
    half = size / 2
    t = tile
    if missingRow < row + half and missingCol < col + half:
        fillBoard(half, row, col, missingRow, missingCol)
    else:
        board[row + half - 1][col + half - 1] = t
        fillBoard(half, row, col, row + half - 1, col + half - 1)
    if missingRow < row + half and missingCol >= col + half:
        fillBoard(half, row, col + half, missingRow, missingCol)
    else:
        board[row + half - 1][col + half] = t
        fillBoard(half, row, col + half, row + half - 1, col + half)
    if missingRow >= row + half and missingCol < col + half:
        fillBoard(half, row + half, col, missingRow, missingCol)
    else:
        board[row + half][col + half - 1] = t
        fillBoard(half, row + half, col, row + half, col + half - 1)
    if missingRow >= row + half and missingCol >= col + half:
        fillBoard(half, row + half, col + half, missingRow, missingCol)
    else:
        board[row + half][col + half] = t
        fillBoard(half, row + half, col + half, row + half, col + half)

if __name__ == "__main__":
    size = int(sys.stdin.readline())
    missingRow = int(sys.stdin.readline())
    missingCol = int(sys.stdin.readline())
    result = solveTiling(size, missingRow, missingCol)
    print "Tiled Board:"
    for i in range(size):
        for j in range(size):
            print result[i][j],
        print

