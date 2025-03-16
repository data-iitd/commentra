def is_placed_correctly(columns, row_index, column_index):
    for i in range(column_index):
        diff = abs(columns[i] - row_index)
        if diff == 0 or column_index - i == diff:
            return False
    return True


def get_solution(board_size, solutions, columns, column_index):
    if column_index == board_size:
        # All queens are placed
        solution = []
        for i in range(board_size):
            row = ['.' if j != columns[i] else 'Q' for j in range(board_size)]
            solution.append(''.join(row))
        solutions.append(solution)
        return

    # Try placing queen in each row of the current column
    for row_index in range(board_size):
        columns[column_index] = row_index
        if is_placed_correctly(columns, row_index, column_index):
            get_solution(board_size, solutions, columns, column_index + 1)


def get_main_arrangements(queens):
    solutions = []
    get_solution(queens, solutions, [0] * queens, 0)
    return solutions


def main():
    queens = int(input())
    arrangements = get_main_arrangements(queens)
    if not arrangements:
        print(f"There is no way to place {queens} queens on a board of size {queens}x{queens}")
    else:
        print(f"Arrangements for placing {queens} queens:")
        for arrangement in arrangements:
            for row in arrangement:
                print(row)
            print()


if __name__ == "__main__":
    main()
