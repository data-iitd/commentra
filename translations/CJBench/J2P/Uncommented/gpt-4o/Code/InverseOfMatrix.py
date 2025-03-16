import numpy as np

def main():
    n = int(input())
    matrix = np.zeros((n, n))
    for i in range(n):
        matrix[i] = list(map(float, input().split()))
    
    inverse = invert(matrix)
    for row in inverse:
        print(" ".join(f"{value:.6f}" for value in row))

def invert(a):
    n = a.shape[0]
    x = np.zeros((n, n))
    b = np.eye(n)
    index = list(range(n))
    
    gaussian(a, index)
    
    for i in range(n - 1):
        for j in range(i + 1, n):
            for k in range(n):
                b[index[j]][k] -= a[index[j]][i] * b[index[i]][k]
    
    for i in range(n):
        x[n - 1][i] = b[index[n - 1]][i] / a[index[n - 1]][n - 1]
        for j in range(n - 2, -1, -1):
            x[j][i] = b[index[j]][i]
            for k in range(j + 1, n):
                x[j][i] -= a[index[j]][k] * x[k][i]
            x[j][i] /= a[index[j]][j]
    
    return x

def gaussian(a, index):
    n = len(index)
    c = np.zeros(n)
    
    for i in range(n):
        index[i] = i
    
    for i in range(n):
        c1 = 0
        for j in range(n):
            c0 = abs(a[i][j])
            if c0 > c1:
                c1 = c0
        c[i] = c1
    
    for j in range(n - 1):
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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
