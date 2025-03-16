
import sys
import math

def multiply(a, b):
    n = len(a)
    mat = [[0 for i in range(n)] for j in range(n)]
    if n == 1:
        mat[0][0] = a[0][0] * b[0][0]
    else:
        a11 = [[0 for i in range(n/2)] for j in range(n/2)]
        a12 = [[0 for i in range(n/2)] for j in range(n/2)]
        a21 = [[0 for i in range(n/2)] for j in range(n/2)]
        a22 = [[0 for i in range(n/2)] for j in range(n/2)]
        b11 = [[0 for i in range(n/2)] for j in range(n/2)]
        b12 = [[0 for i in range(n/2)] for j in range(n/2)]
        b21 = [[0 for i in range(n/2)] for j in range(n/2)]
        b22 = [[0 for i in range(n/2)] for j in range(n/2)]
        split(a, a11, 0, 0)
        split(a, a12, 0, n/2)
        split(a, a21, n/2, 0)
        split(a, a22, n/2, n/2)
        split(b, b11, 0, 0)
        split(b, b12, 0, n/2)
        split(b, b21, n/2, 0)
        split(b, b22, n/2, n/2)
        m1 = multiply(add(a11, a22), add(b11, b22))
        m2 = multiply(add(a21, a22), b11)
        m3 = multiply(a11, sub(b12, b22))
        m4 = multiply(a22, sub(b21, b11))
        m5 = multiply(add(a11, a12), b22)
        m6 = multiply(sub(a21, a11), add(b11, b12))
        m7 = multiply(sub(a12, a22), add(b21, b22))
        c11 = add(sub(add(m1, m4), m5), m7)
        c12 = add(m3, m5)
        c21 = add(m2, m4)
        c22 = add(sub(add(m1, m3), m2), m6)
        join(c11, mat, 0, 0)
        join(c12, mat, 0, n/2)
        join(c21, mat, n/2, 0)
        join(c22, mat, n/2, n/2)
    return mat

def add(a, b):
    n = len(a)
    c = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] + b[i][j]
    return c

def sub(a, b):
    n = len(a)
    c = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] - b[i][j]
    return c

def split(p, c, iB, jB):
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            c[i1][j1] = p[i1+iB][j1+jB]

def join(c, p, iB, jB):
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            p[i1+iB][j1+jB] = c[i1][j1]

def main():
    n = int(sys.stdin.readline())
    a = [[0 for i in range(n)] for j in range(n)]
    b = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            a[i][j] = int(sys.stdin.readline())
    for i in range(n):
        for j in range(n):
            b[i][j] = int(sys.stdin.readline())
    strassen = Main()
    result = strassen.multiply(a, b)
    print("Resultant Matrix:")
    for i in range(n):
        for j in range(n):
            print(result[i][j], end=" ")
        print()

if __name__ == "__main__":
    main()

