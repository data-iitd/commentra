

import sys

def solve_tiling(size, missing_row, missing_col):
    board = [[0 for _ in range(size)] for _ in range(size)]
    fill_board(board, 0, 0, size, missing_row, missing_col)
    return board

def fill_board(board, row, col, size, missing_row, missing_col):
    if size == 1:
        return

    half = size // 2
    t = tile
    tile += 1

    # Top-left quadrant
    if missing_row < row + half and missing_col < col + half:
        fill_board(board, row, col, half, missing_row, missing_col)
    else:
        board[row + half - 1][col + half - 1] = t
        fill_board(board, row, col, half, row + half - 1, col + half - 1)

    # Top-right quadrant
    if missing_row < row + half and missing_col >= col + half:
        fill_board(board, row, col + half, half, missing_row, missing_col)
    else:
        board[row + half - 1][col + half] = t
        fill_board(board, row, col + half, half, row + half - 1, col + half)

    # Bottom-left quadrant
    if missing_row >= row + half and missing_col < col + half:
        fill_board(board, row + half, col, half, missing_row, missing_col)
    else:
        board[row + half][col + half - 1] = t
        fill_board(board, row + half, col, half, row + half, col + half - 1)

    # Bottom-right quadrant
    if missing_row >= row + half and missing_col >= col + half:
        fill_board(board, row + half, col + half, half, missing_row, missing_col)
    else:
        board[row + half][col + half] = t
        fill_board(board, row + half, col + half, half, row + half, col + half)

if __name__ == "__main__":
    size, missing_row, missing_col = map(int, sys.stdin.readline().split())

    result = solve_tiling(size, missing_row, missing_col)

    print("Tiled Board:")
    for row in result:
        print(" ".join(map(str, row)))

