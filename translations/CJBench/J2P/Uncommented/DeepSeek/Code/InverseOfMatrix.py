import numpy as np

def invert(a):
    n = len(a)
    x = np.zeros((n, n))
    b = np.eye(n)
    index = [0] * n
    
    for i in range(n):
        index[i] = i
    
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
    c = [0] * n
    
    for i in range(n):
        index[i] = i
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
        temp = index[j]
        index[j] = index[k]
        index[k] = temp
        
        for i in range(j + 1, n):
            pj = a[index[i]][j] / a[index[j]][j]
            a[index[i]][j] = pj
            for l in range(j + 1, n):
                a[index[i]][l] -= pj * a[index[j]][l]

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    matrix = []
    idx = 1
    for i in range(n):
        row = []
        for j in range(n):
            row.append(float(data[idx]))
            idx += 1
        matrix.append(row)
    
    inverse = invert(matrix)
    for i in range(n):
        for j in range(n):
            print("{:.6f}".format(inverse[i][j]), end=' ')
        print()
