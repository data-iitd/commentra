import numpy as np

class MatrixInverter:
    @staticmethod
    def invert(matrix):
        n = len(matrix)
        x = np.zeros((n, n))
        b = np.eye(n)
        index = list(range(n))

        MatrixInverter.gaussian(matrix, index)

        for i in range(n - 1):
            for j in range(i + 1, n):
                for k in range(n):
                    b[index[j]][k] -= matrix[index[j]][i] * b[index[i]][k]

        for i in range(n):
            x[n - 1][i] = b[index[n - 1]][i] / matrix[index[n - 1]][n - 1]
            for j in range(n - 2, -1, -1):
                x[j][i] = b[index[j]][i]
                for k in range(j + 1, n):
                    x[j][i] -= matrix[index[j]][k] * x[k][i]
                x[j][i] /= matrix[index[j]][j]

        return x

    @staticmethod
    def gaussian(matrix, index):
        n = len(index)
        c = np.zeros(n)

        for i in range(n):
            index[i] = i

        for i in range(n):
            c1 = 0
            for j in range(n):
                c0 = abs(matrix[i][j])
                if c0 > c1:
                    c1 = c0
            c[i] = c1

        for j in range(n - 1):
            pi1 = 0
            k = j
            for i in range(j, n):
                pi0 = abs(matrix[index[i]][j]) / c[index[i]]
                if pi0 > pi1:
                    pi1 = pi0
                    k = i
            index[j], index[k] = index[k], index[j]

            for i in range(j + 1, n):
                pj = matrix[index[i]][j] / matrix[index[j]][j]
                matrix[index[i]][j] = pj
                for l in range(j + 1, n):
                    matrix[index[i]][l] -= pj * matrix[index[j]][l]

def main():
    n = int(input())
    matrix = []
    for _ in range(n):
        row = list(map(float, input().split()))
        matrix.append(row)

    matrix = np.array(matrix)
    inverse = MatrixInverter.invert(matrix)

    for row in inverse:
        print(" ".join(f"{value:.6f}" for value in row))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
