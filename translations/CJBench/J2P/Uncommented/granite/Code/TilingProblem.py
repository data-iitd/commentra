

import sys

def solve_tiling(size, missing_row, missing_col):
    board = [[0 for _ in range(size)] for _ in range(size)]
    fill_board(board, size, 0, 0, missing_row, missing_col)
    return board

def fill_board(board, size, row, col, missing_row, missing_col):
    if size == 1:
        return
    half = size // 2
    t = tile
    if missing_row < row + half and missing_col < col + half:
        fill_board(board, half, row, col, missing_row, missing_col)
    else:
        board[row + half - 1][col + half - 1] = t
        fill_board(board, half, row, col, row + half - 1, col + half - 1)
    if missing_row < row + half and missing_col >= col + half:
        fill_board(board, half, row, col + half, missing_row, missing_col)
    else:
        board[row + half - 1][col + half] = t
        fill_board(board, half, row, col + half, row + half - 1, col + half)
    if missing_row >= row + half and missing_col < col + half:
        fill_board(board, half, row + half, col, missing_row, missing_col)
    else:
        board[row + half][col + half - 1] = t
        fill_board(board, half, row + half, col, row + half, col + half - 1)
    if missing_row >= row + half and missing_col >= col + half:
        fill_board(board, half, row + half, col + half, missing_row, missing_col)
    else:
        board[row + half][col + half] = t
        fill_board(board, half, row + half, col + half, row + half, col + half)

def main():
    size, missing_row, missing_col = map(int, sys.stdin.readline().split())
    result = solve_tiling(size, missing_row, missing_col)
    print("Tiled Board:")
    for row in result:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    main()

