def compute_rank(matrix):
    validate_input_matrix(matrix)

    num_rows = len(matrix)
    num_columns = len(matrix[0])
    rank = 0

    row_marked = [False] * num_rows

    matrix_copy = deep_copy(matrix)

    for col_index in range(num_columns):
        pivot_row = find_pivot_row(matrix_copy, row_marked, col_index)
        if pivot_row != num_rows:
            rank += 1
            row_marked[pivot_row] = True
            normalize_pivot_row(matrix_copy, pivot_row, col_index)
            eliminate_rows(matrix_copy, pivot_row, col_index)

    return rank


def is_zero(value):
    return abs(value) < EPSILON


def deep_copy(matrix):
    return [row[:] for row in matrix]


def validate_input_matrix(matrix):
    if matrix is None or len(matrix) == 0:
        raise ValueError("The input matrix cannot be None or empty")
    if not has_valid_rows(matrix):
        raise ValueError("The input matrix cannot have None or empty rows")


def has_valid_rows(matrix):
    return all(row is not None and len(row) > 0 for row in matrix)


def find_pivot_row(matrix, row_marked, col_index):
    num_rows = len(matrix)
    for pivot_row in range(num_rows):
        if not row_marked[pivot_row] and not is_zero(matrix[pivot_row][col_index]):
            return pivot_row
    return num_rows


def normalize_pivot_row(matrix, pivot_row, col_index):
    num_columns = len(matrix[0])
    for next_col in range(col_index + 1, num_columns):
        matrix[pivot_row][next_col] /= matrix[pivot_row][col_index]


def eliminate_rows(matrix, pivot_row, col_index):
    num_rows = len(matrix)
    num_columns = len(matrix[0])
    for other_row in range(num_rows):
        if other_row != pivot_row and not is_zero(matrix[other_row][col_index]):
            for col2 in range(col_index + 1, num_columns):
                matrix[other_row][col2] -= matrix[pivot_row][col2] * matrix[other_row][col_index]


EPSILON = 1e-10


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    rows = int(data[index])
    cols = int(data[index + 1])
    index += 2

    matrix = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(float(data[index]))
            index += 1
        matrix.append(row)

    rank = compute_rank(matrix)
    print("The rank of the matrix is:", rank)


if __name__ == "__main__":
    main()
