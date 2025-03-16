
import numpy as np

def main():
    n = int(input("Enter the size of the matrix: "))
    matrix = np.zeros((n, n))
    for i in range(n):
        row = list(map(float, input("Enter the elements of row {}: ".format(i + 1)).split()))
        matrix[i] = row
    inverse = np.linalg.inv(matrix)
    print("The inverse of the matrix is:")
    for row in inverse:
        print(" ".join("{:.6f}".format(x) for x in row))

if __name__ == "__main__":
    main()

