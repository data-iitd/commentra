def multiply(a, b):
    n = len(a)
    mat = [[0] * n for _ in range(n)]
    if n == 1:
        mat[0][0] = a[0][0] * b[0][0]
    else:
        a11 = [[0] * (n // 2) for _ in range(n // 2)]
        a12 = [[0] * (n // 2) for _ in range(n // 2)]
        a21 = [[0] * (n // 2) for _ in range(n // 2)]
        a22 = [[0] * (n // 2) for _ in range(n // 2)]
        b11 = [[0] * (n // 2) for _ in range(n // 2)]
        b12 = [[0] * (n // 2) for _ in range(n // 2)]
        b21 = [[0] * (n // 2) for _ in range(n // 2)]
        b22 = [[0] * (n // 2) for _ in range(n // 2)]
        split(a, a11, 0, 0)
        split(a, a12, 0, n // 2)
        split(a, a21, n // 2, 0)
        split(a, a22, n // 2, n // 2)
        split(b, b11, 0, 0)
        split(b, b12, 0, n // 2)
        split(b, b21, n // 2, 0)
        split(b, b22, n // 2, n // 2)
        m1 = add(add(a11, a22), b11, b22)
        m2 = add(add(a21, a22), b11)
        m3 = add(a11, b12, b22)
        m4 = add(a22, b21, b11)
        m5 = add(add(a11, a12), b22)
        m6 = add(sub(a21, a11), add(b11, b12))
        m7 = add(sub(a12, a22), add(b21, b22))
        c11 = add(sub(add(m1, m4), m5), m7)
        c12 = add(m3, m5)
        c21 = add(m2, m4)
        c22 = add(sub(add(m1, m3), m2), m6)
        join(c11, mat, 0, 0)
        join(c12, mat, 0, n // 2)
        join(c21, mat, n // 2, 0)
        join(c22, mat, n // 2, n // 2)
    return mat

def sub(a, b):
    n = len(a)
    c = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] - b[i][j]
    return c

def add(a, b):
    n = len(a)
    c = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] + b[i][j]
    return c

def split(p, c, iB, jB):
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            c[i1][j1] = p[iB + i1][jB + j1]

def join(c, p, iB, jB):
    for i1 in range(len(c)):
        for j1 in range(len(c)):
            p[iB + i1][jB + j1] = c[i1][j1]

def main():
    n = int(input())
    a = [list(map(int, input().split())) for _ in range(n)]
    b = [list(map(int, input().split())) for _ in range(n)]
    result = multiply(a, b)
    print("Resultant Matrix:")
    for row in result:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    main()
