
import sys

class Main:
    def __init__(self):
        pass

    @staticmethod
    def get_main_arrangements(queens):
        arrangements = []
        Main.get_solution(queens, arrangements, [0] * queens, 0)
        return arrangements

    @staticmethod
    def get_solution(board_size, solutions, columns, column_index):
        if column_index == board_size:
            # All queens are placed
            solution = []
            for i in range(board_size):
                row = ""
                for j in range(board_size):
                    row += "Q" if j == columns[i] else "."
                solution.append(row)
            solutions.append(solution)
            return

        # Try placing queen in each row of the current column
        for row_index in range(board_size):
            columns[column_index] = row_index
            if Main.is_placed_correctly(columns, row_index, column_index):
                Main.get_solution(board_size, solutions, columns, column_index + 1)

    @staticmethod
    def is_placed_correctly(columns, row_index, column_index):
        for i in range(column_index):
            diff = abs(columns[i] - row_index)
            if diff == 0 or column_index - i == diff:
                return False
        return True

if __name__ == "__main__":
    queens = int(sys.stdin.readline().strip())
    arrangements = Main.get_main_arrangements(queens)
    if len(arrangements) == 0:
        print("There is no way to place " + str(queens) + " queens on a board of size " + str(queens) + "x" + str(queens))
    else:
        print("Arrangements for placing " + str(queens) + " queens:")
        for arrangement in arrangements:
            for row in arrangement:
                print(row)
            print()

