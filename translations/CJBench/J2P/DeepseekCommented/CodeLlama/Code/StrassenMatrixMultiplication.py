
import math
import sys

# Method to multiply two matrices using Strassen's algorithm
def multiply(a, b):
    n = len(a) // 2
    mat = [[0] * n for _ in range(n)]
    if n == 1:
        mat[0][0] = a[0][0] * b[0][0]
    else:
        a11 = [[0] * n for _ in range(n)]
        a12 = [[0] * n for _ in range(n)]
        a21 = [[0] * n for _ in range(n)]
        a22 = [[0] * n for _ in range(n)]
        b11 = [[0] * n for _ in range(n)]
        b12 = [[0] * n for _ in range(n)]
        b21 = [[0] * n for _ in range(n)]
        b22 = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                a11[i][j] = a[i][j]
                a12[i][j] = a[i][j + n // 2]
                a21[i][j] = a[i + n // 2][j]
                a22[i][j] = a[i + n // 2][j + n // 2]
                b11[i][j] = b[i][j]
                b12[i][j] = b[i][j + n // 2]
                b21[i][j] = b[i + n // 2][j]
                b22[i][j] = b[i + n // 2][j + n // 2]
        m1 = add(add(multiply(add(a11, a22), add(b11, b22)),
                     multiply(add(a21, a22), b11)),
                  subtract(multiply(add(a11, a12), b22),
                            multiply(add(a21, a22), b12)))
        m2 = add(multiply(add(a11, a12), b22),
                 subtract(multiply(add(a12, a22), b11),
                           multiply(add(a21, a22), b12)))
        m3 = subtract(multiply(add(a11, a12), b22),
                      multiply(add(a21, a22), b12))
        m4 = subtract(multiply(add(a11, a12), b22),
                      multiply(add(a21, a22), b12))
        m5 = add(multiply(add(a11, a12), b22),
                 subtract(multiply(add(a11, a22), b11),
                           multiply(add(a12, a22), b12)))
        m6 = subtract(multiply(add(a11, a12), b22),
                      multiply(add(a21, a22), b12))
        m7 = subtract(multiply(add(a11, a12), b22),
                      multiply(add(a21, a22), b12))
        c11 = add(subtract(add(m1, m4), m5), m7)
        c12 = add(m3, m5)
        c21 = add(m2, m4)
        c22 = add(subtract(add(m1, m3), m2), m6)
        for i in range(n):
            for j in range(n):
                mat[i][j] = c11[i][j]
                mat[i][j + n // 2] = c12[i][j]
                mat[i + n // 2][j] = c21[i][j]
                mat[i + n // 2][j + n // 2] = c22[i][j]
    return mat

# Method to perform element-wise subtraction of two matrices
def subtract(a, b):
    n = len(a)
    c = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] - b[i][j]
    return c

# Method to perform element-wise addition of two matrices
def add(a, b):
    n = len(a)
    c = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] + b[i][j]
    return c

# Main method to read input, call the multiply method, and print the result
def main():
    n = int(sys.stdin.readline())
    a = [[0] * n for _ in range(n)]
    b = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            a[i][j] = int(sys.stdin.readline())
    for i in range(n):
        for j in range(n):
            b[i][j] = int(sys.stdin.readline())
    result = multiply(a, b)
    print("Resultant Matrix:")
    for i in range(n):
        for j in range(n):
            print(result[i][j], end=" ")
        print()

if __name__ == "__main__":
    main()

