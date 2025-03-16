import sys

def get_main_arrangements(queens):
    arrangements = []
    get_solution(queens, arrangements, [0] * queens, 0)
    return arrangements

def get_solution(board_size, solutions, columns, column_index):
    if column_index == board_size:
        solution = []
        for i in range(board_size):
            row = ""
            for j in range(board_size):
                row += "Q" if j == columns[i] else "."
            solution.append(row)
        solutions.append(solution)
        return

    for row_index in range(board_size):
        columns[column_index] = row_index
        if is_placed_correctly(columns, row_index, column_index):
            get_solution(board_size, solutions, columns, column_index + 1)

def is_placed_correctly(columns, row_index, column_index):
    for i in range(column_index):
        diff = abs(columns[i] - row_index)
        if diff == 0 or column_index - i == diff:
            return False
    return True

if __name__ == "__main__":
    queens = int(sys.stdin.readline().strip())
    arrangements = get_main_arrangements(queens)
    if not arrangements:
        print(f"There is no way to place {queens} queens on a board of size {queens}x{queens}")
    else:
        print("Arrangements for placing", queens, "queens:")
        for arrangement in arrangements:
            for row in arrangement:
                print(row)
            print()

