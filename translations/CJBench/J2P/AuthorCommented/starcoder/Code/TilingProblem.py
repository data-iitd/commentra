
import sys

# A counter used to label the L-shaped tiles placed on the board.
tile = 1
# A 2D array representing the board to be tiled.
board = None


def solve_tiling(size, missing_row, missing_col):
    """
    Solves the tiling problem for a 2^n x 2^n board with one missing square.

    :param size: The size of the board (must be a power of 2).
    :param missing_row: The row index of the missing square.
    :param missing_col: The column index of the missing square.
    :return: A 2D array representing the tiled board with L-shaped tiles.
    """
    global tile
    global board
    board = [[0 for _ in range(size)] for _ in range(size)]
    fill_board(size, 0, 0, missing_row, missing_col)
    return board


def fill_board(size, row, col, missing_row, missing_col):
    """
    Recursively fills the board with L-shaped tiles.

    The board is divided into four quadrants. Depending on the location of
    the missing square, an L-shaped tile is placed at the center of the board
    to cover three of the four quadrants. The process is then repeated for
    each quadrant until the entire board is filled.

    :param size: The current size of the sub-board.
    :param row: The starting row index of the current sub-board.
    :param col: The starting column index of the current sub-board.
    :param missing_row: The row index of the missing square within the board.
    :param missing_col: The column index of the missing square within the board.
    """
    if size == 1:
        return

    half = size // 2
    t = tile
    tile += 1

    # Top-left quadrant
    if missing_row < row + half and missing_col < col + half:
        fill_board(half, row, col, missing_row, missing_col)
    else:
        board[row + half - 1][col + half - 1] = t
        fill_board(half, row, col, row + half - 1, col + half - 1)

    # Top-right quadrant
    if missing_row < row + half and missing_col >= col + half:
        fill_board(half, row, col + half, missing_row, missing_col)
    else:
        board[row + half - 1][col + half] = t
        fill_board(half, row, col + half, row + half - 1, col + half)

    # Bottom-left quadrant
    if missing_row >= row + half and missing_col < col + half:
        fill_board(half, row + half, col, missing_row, missing_col)
    else:
        board[row + half][col + half - 1] = t
        fill_board(half, row + half, col, row + half, col + half - 1)

    # Bottom-right quadrant
    if missing_row >= row + half and missing_col >= col + half:
        fill_board(half, row + half, col + half, missing_row, missing_col)
    else:
        board[row + half][col + half] = t
        fill_board(half, row + half, col + half, row + half, col + half)


def main():
    size = int(sys.stdin.readline().strip())

    missing_row = int(sys.stdin.readline().strip())

    missing_col = int(sys.stdin.readline().strip())

    result = solve_tiling(size, missing_row, missing_col)

    print("Tiled Board:")
    for i in range(size):
        for j in range(size):
            print(result[i][j], end=" ")
        print()


if __name__ == "__main__":
    main()

