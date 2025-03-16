def solve_tiling(size, missing_row, missing_col):
    board = [[0] * size for _ in range(size)]
    fill_board(size, 0, 0, missing_row, missing_col, board)
    return board

def fill_board(size, row, col, missing_row, missing_col, board):
    if size == 1:
        return
    half = size // 2
    tile = 1
    t = tile
    if missing_row < row + half and missing_col < col + half:
        fill_board(half, row, col, missing_row, missing_col, board)
    else:
        board[row + half - 1][col + half - 1] = t
        fill_board(half, row, col, row + half - 1, col + half - 1, board)
    if missing_row < row + half and missing_col >= col + half:
        fill_board(half, row, col + half, missing_row, missing_col, board)
    else:
        board[row + half - 1][col + half] = t
        fill_board(half, row, col + half, row + half - 1, col + half, board)
    if missing_row >= row + half and missing_col < col + half:
        fill_board(half, row + half, col, missing_row, missing_col, board)
    else:
        board[row + half][col + half - 1] = t
        fill_board(half, row + half, col, row + half, col + half - 1, board)
    if missing_row >= row + half and missing_col >= col + half:
        fill_board(half, row + half, col + half, missing_row, missing_col, board)
    else:
        board[row + half][col + half] = t
        fill_board(half, row + half, col + half, row + half, col + half, board)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    size = int(data[0])
    missing_row = int(data[1])
    missing_col = int(data[2])
    result = solve_tiling(size, missing_row, missing_col)
    print("Tiled Board:")
    for row in result:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    main()
