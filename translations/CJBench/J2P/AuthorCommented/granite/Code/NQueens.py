

def get_main_arrangements(queens):
    arrangements = []
    get_solution(queens, arrangements, [0] * queens, 0)
    return arrangements

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
        if is_placed_correctly(columns, row_index, column_index):
            get_solution(board_size, solutions, columns, column_index + 1)

def is_placed_correctly(columns, row_index, column_index):
    for i in range(column_index):
        diff = abs(columns[i] - row_index)
        if diff == 0 or column_index - i == diff:
            return False
    return True

# 