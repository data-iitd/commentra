

import math


def solve_tiling(size, missing_row, missing_col):
    board = [[0 for _ in range(size)] for _ in range(size)]
    fill_board(size, 0, 0, missing_row, missing_col, board)
    return board


def fill_board(size, row, col, missing_row, missing_col, board):
    if size == 1:
        return

    half = size // 2
    t = tile
    tile += 1

    # Top-left quadrant
    if missing_row < row + half and missing_col < col + half:
        fill_board(half, row, col, missing_row, missing_col, board)
    else:
        board[row + half - 1][col + half - 1] = t
        fill_board(half, row, col, row + half - 1, col + half - 1, board)

    # Top-right quadrant
    if missing_row < row + half and missing_col >= col + half:
        fill_board(half, row, col + half, missing_row, missing_col, board)
    else:
        board[row + half - 1][col + half] = t
        fill_board(half, row, col + half, row + half - 1, col + half, board)

    # Bottom-left quadrant
    if missing_row >= row + half and missing_col < col + half:
        fill_board(half, row + half, col, missing_row, missing_col, board)
    else:
        board[row + half][col + half - 1] = t
        fill_board(half, row + half, col, row + half, col + half - 1, board)

    # Bottom-right quadrant
    if missing_row >= row + half and missing_col >= col + half:
        fill_board(half, row + half, col + half, missing_row, missing_col, board)
    else:
        board[row + half][col + half] = t
        fill_board(half, row + half, col + half, row + half, col + half, board)


tile = 1

size = int(input())

missing_row = int(input())

missing_col = int(input())

result = solve_tiling(size, missing_row, missing_col)

print("Tiled Board:")
for i in range(size):
    for j in range(size):
        print(result[i][j], end=" ")
    print()

# 