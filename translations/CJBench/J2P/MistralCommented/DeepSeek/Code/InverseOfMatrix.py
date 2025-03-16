import numpy as np

def invert(a):
    n = len(a)
    x = np.zeros((n, n))
    b = np.identity(n)
    index = list(range(n))

    def gaussian(a, index):
        c = np.zeros(n)
        for i in range(n):
            c[i] = max(abs(a[i][j]) for j in range(n))
        for j in range(n):
            pi1 = 0
            k = j
            for i in range(j, n):
                pi0 = abs(a[index[i]][j]) / c[index[i]]
                if pi0 > pi1:
                    pi1 = pi0
                    k = i
            index[j], index[k] = index[k], index[j]
            for i in range(j + 1, n):
                pj = a[index[i]][j] / a[index[j]][j]
                a[index[i]][j] = pj
                for l in range(j + 1, n):
                    a[index[i]][l] -= pj * a[index[j]][l]
        return a, index

    a, index = gaussian(a, index)

    for i in range(n):
        x[n - 1][i] = b[index[n - 1]][i] / a[index[n - 1]][n - 1]
        for j in range(n - 2, -1, -1):
            x[j][i] = b[index[j]][i]
            for k in range(j + 1, n):
                x[j][i] -= a[index[j]][k] * x[k][i]
            x[j][i] /= a[index[j]][j]

    return x

def main():
    n = int(input())
    matrix = [list(map(float, input().split())) for _ in range(n)]
    inverse = invert(matrix)
    for row in inverse:
        print(" ".join(f"{x:.6f}" for x in row))

main()
