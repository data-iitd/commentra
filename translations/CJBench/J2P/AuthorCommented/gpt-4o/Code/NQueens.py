class NQueens:
    def __init__(self, queens):
        self.queens = queens
        self.arrangements = []

    def get_main_arrangements(self):
        self.get_solution([0] * self.queens, 0)
        return self.arrangements

    def get_solution(self, columns, column_index):
        if column_index == self.queens:
            # All queens are placed
            solution = []
            for i in range(self.queens):
                row = ''.join('Q' if j == columns[i] else '.' for j in range(self.queens))
                solution.append(row)
            self.arrangements.append(solution)
            return

        # Try placing queen in each row of the current column
        for row_index in range(self.queens):
            columns[column_index] = row_index
            if self.is_placed_correctly(columns, row_index, column_index):
                self.get_solution(columns, column_index + 1)

    def is_placed_correctly(self, columns, row_index, column_index):
        for i in range(column_index):
            diff = abs(columns[i] - row_index)
            if diff == 0 or column_index - i == diff:
                return False
        return True


if __name__ == "__main__":
    queens = int(input("Enter the number of queens: "))
    n_queens = NQueens(queens)
    arrangements = n_queens.get_main_arrangements()

    if not arrangements:
        print(f"There is no way to place {queens} queens on a board of size {queens}x{queens}")
    else:
        print(f"Arrangements for placing {queens} queens:")
        for arrangement in arrangements:
            for row in arrangement:
                print(row)
            print()

# <END-OF-CODE>
