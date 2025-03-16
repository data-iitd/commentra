class Main:
    tile = 1
    board = []

    @staticmethod
    def solve_tiling(size, missing_row, missing_col):
        Main.board = [[0] * size for _ in range(size)]
        Main.fill_board(size, 0, 0, missing_row, missing_col)
        return Main.board

    @staticmethod
    def fill_board(size, row, col, missing_row, missing_col):
        if size == 1:
            return

        half = size // 2
        t = Main.tile
        Main.tile += 1

        if missing_row < row + half and missing_col < col + half:
            Main.fill_board(half, row, col, missing_row, missing_col)
        else:
            Main.board[row + half - 1][col + half - 1] = t
            Main.fill_board(half, row, col, row + half - 1, col + half - 1)

        if missing_row < row + half and missing_col >= col + half:
            Main.fill_board(half, row, col + half, missing_row, missing_col)
        else:
            Main.board[row + half - 1][col + half] = t
            Main.fill_board(half, row, col + half, row + half - 1, col + half)

        if missing_row >= row + half and missing_col < col + half:
            Main.fill_board(half, row + half, col, missing_row, missing_col)
        else:
            Main.board[row + half][col + half - 1] = t
            Main.fill_board(half, row + half, col, row + half, col + half - 1)

        if missing_row >= row + half and missing_col >= col + half:
            Main.fill_board(half, row + half, col + half, missing_row, missing_col)
        else:
            Main.board[row + half][col + half] = t
            Main.fill_board(half, row + half, col + half, row + half, col + half)

    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()

        size = int(data[0])
        missing_row = int(data[1])
        missing_col = int(data[2])

        result = Main.solve_tiling(size, missing_row, missing_col)
        print("Tiled Board:")
        for row in result:
            print(" ".join(map(str, row)))


Main.main()
