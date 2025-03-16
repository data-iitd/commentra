import numpy as np

class MatrixRankCalculator:
    EPSILON = 1e-10

    @staticmethod
    def compute_rank(matrix):
        MatrixRankCalculator.validate_input_matrix(matrix)

        num_rows, num_columns = matrix.shape
        rank = 0
        row_marked = np.zeros(num_rows, dtype=bool)

        matrix_copy = matrix.copy()

        for col_index in range(num_columns):
            pivot_row = MatrixRankCalculator.find_pivot_row(matrix_copy, row_marked, col_index)
            if pivot_row != num_rows:
                rank += 1
                row_marked[pivot_row] = True
                MatrixRankCalculator.normalize_pivot_row(matrix_copy, pivot_row, col_index)
                MatrixRankCalculator.eliminate_rows(matrix_copy, pivot_row, col_index)

        return rank

    @staticmethod
    def is_zero(value):
        return abs(value) < MatrixRankCalculator.EPSILON

    @staticmethod
    def validate_input_matrix(matrix):
        if matrix is None or matrix.size == 0:
            raise ValueError("The input matrix cannot be null or empty")
        if not MatrixRankCalculator.has_valid_rows(matrix):
            raise ValueError("The input matrix cannot have null or empty rows")

    @staticmethod
    def has_valid_rows(matrix):
        return all(row.size > 0 for row in matrix)

    @staticmethod
    def find_pivot_row(matrix, row_marked, col_index):
        num_rows = matrix.shape[0]
        for pivot_row in range(num_rows):
            if not row_marked[pivot_row] and not MatrixRankCalculator.is_zero(matrix[pivot_row, col_index]):
                return pivot_row
        return num_rows

    @staticmethod
    def normalize_pivot_row(matrix, pivot_row, col_index):
        num_columns = matrix.shape[1]
        for next_col in range(col_index + 1, num_columns):
            matrix[pivot_row, next_col] /= matrix[pivot_row, col_index]

    @staticmethod
    def eliminate_rows(matrix, pivot_row, col_index):
        num_rows = matrix.shape[0]
        num_columns = matrix.shape[1]
        for other_row in range(num_rows):
            if other_row != pivot_row and not MatrixRankCalculator.is_zero(matrix[other_row, col_index]):
                for col2 in range(col_index + 1, num_columns):
                    matrix[other_row, col2] -= matrix[pivot_row, col2] * matrix[other_row, col_index]

if __name__ == "__main__":
    rows, cols = map(int, input().split())
    matrix = np.array([list(map(float, input().split())) for _ in range(rows)])

    rank = MatrixRankCalculator.compute_rank(matrix)
    print("The rank of the matrix is:", rank)

# <END-OF-CODE>
