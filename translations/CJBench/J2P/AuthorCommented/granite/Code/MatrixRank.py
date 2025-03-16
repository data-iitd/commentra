
import numpy as np

def compute_rank(matrix):
    matrix = np.array(matrix)
    rank = np.linalg.matrix_rank(matrix)
    return rank

if __name__ == "__main__":
    rows = int(input("Enter the number of rows: "))
    cols = int(input("Enter the number of columns: "))

    matrix = []
    for _ in range(rows):
        row = list(map(float, input("Enter the elements of the row (separated by spaces): ").split()))
        matrix.append(row)

    rank = compute_rank(matrix)
    print(f"The rank of the matrix is: {rank}")

