class TilingSolver:
    def __init__(self):
        self.tile = 1
        self.board = []

    def solve_tiling(self, size, missing_row, missing_col):
        self.board = [[0] * size for _ in range(size)]
        self.fill_board(size, 0, 0, missing_row, missing_col)
        return self.board

    def fill_board(self, size, row, col, missing_row, missing_col):
        if size == 1:
            return
        half = size // 2
        t = self.tile
        self.tile += 1

        if missing_row < row + half and missing_col < col + half:
            self.fill_board(half, row, col, missing_row, missing_col)
        else:
            self.board[row + half - 1][col + half - 1] = t
            self.fill_board(half, row, col, row + half - 1, col + half - 1)

        if missing_row < row + half and missing_col >= col + half:
            self.fill_board(half, row, col + half, missing_row, missing_col)
        else:
            self.board[row + half - 1][col + half] = t
            self.fill_board(half, row, col + half, row + half - 1, col + half)

        if missing_row >= row + half and missing_col < col + half:
            self.fill_board(half, row + half, col, missing_row, missing_col)
        else:
            self.board[row + half][col + half - 1] = t
            self.fill_board(half, row + half, col, row + half, col + half - 1)

        if missing_row >= row + half and missing_col >= col + half:
            self.fill_board(half, row + half, col + half, missing_row, missing_col)
        else:
            self.board[row + half][col + half] = t
            self.fill_board(half, row + half, col + half, row + half, col + half)

if __name__ == "__main__":
    size = int(input("Enter the size of the board: "))
    missing_row = int(input("Enter the missing row: "))
    missing_col = int(input("Enter the missing column: "))
    
    solver = TilingSolver()
    result = solver.solve_tiling(size, missing_row, missing_col)
    
    print("Tiled Board:")
    for row in result:
        print(" ".join(map(str, row)))

# <END-OF-CODE>
