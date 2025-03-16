def multiply(a, b):
    n = len(a)
    mat = [[0 for _ in range(n)] for _ in range(n)]

    if n == 1:
        mat[0][0] = a[0][0] * b[0][0]
    else:
        # Dividing Matrix into parts
        # by storing sub-parts to variables
        a11 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
        a12 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
        a21 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
        a22 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
        b11 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
        b12 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
        b21 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]
        b22 = [[0 for _ in range(n // 2)] for _ in range(n // 2)]

        # Dividing matrix A into 4 parts
        split(a, a11, 0, 0)
        split(a, a12, 0, n // 2)
        split(a, a21, n // 2, 0)
        split(a, a22, n // 2, n // 2)

        # Dividing matrix B into 4 parts
        split(b, b11, 0, 0)
        split(b, b12, 0, n // 2)
        split(b, b21, n // 2, 0)
        split(b, b22, n // 2, n // 2)

        # Using Formulas as described in algorithm
        # m1:=(A1+A3)×(B1+B2)
        m1 = multiply(add(a11, a22), add(b11, b22))
        # m2:=(A2+A4)×(B3+B4)
        m2 = multiply(add(a21, a22), b11)
        # m3:=(A1−A4)×(B1+A4)
        m3 = multiply(sub(a11, a22), add(b12, b22))
        # m4:=A1×(B2−B4)
        m4 = multiply(a22, sub(b21, b11))
        # m5:=(A3+A4)×(B1)
        m5 = multiply(add(a11, a12), b22)
        # m6:=(A1+A2)×(B4)
        m6 = multiply(sub(a21, a11), add(b11, b12))
        # m7:=A4×(B3−B1)
        m7 = multiply(sub(a12, a22), add(b21, b22))

        # P:=m2+m3−m6−m7
        c11 = add(sub(add(m1, m4), m5), m7)
        # Q:=m4+m6
        c12 = add(m3, m5)
        # mat:=m5+m7
        c21 = add(m2, m4)
        # S:=m1−m3−m4−m5
        c22 = add(sub(add(m1, m3), m2), m6)

        join(c11, mat, 0, 0)
        join(c12, mat, 0, n // 2)
        join(c21, mat, n // 2, 0)
        join(c22, mat, n // 2, n // 2)

    return mat


def sub(a, b):
    n = len(a)
    c = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            c[i][j] = a[i][j] - b[i][j]

    return c


def add(a, b):
    n = len(a)
    c = [[0 for _ in range(n)] for _ in range(n)]

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


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    index = 1
    a = [[0 for _ in range(n)] for _ in range(n)]
    b = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            a[i][j] = int(data[index])
            index += 1

    for i in range(n):
        for j in range(n):
            b[i][j] = int(data[index])
            index += 1

    result = multiply(a, b)

    for i in range(n):
        for j in range(n):
            print(result[i][j], end=" ")
        print()
