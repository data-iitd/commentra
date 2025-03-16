
import sys

class Main:
    def __init__(self):
        self.n = 0
        self.a = []
        self.b = []
        self.mat = []

    def split(self, p, c, iB, jB):
        for i1 in range(0, c.length):
            for j1 in range(0, c.length):
                c[i1][j1] = p[i2][j2]

    def join(self, c, p, iB, jB):
        for i1 in range(0, c.length):
            for j1 in range(0, c.length):
                p[i2][j2] = c[i1][j1]

    def multiply(self, a, b):
        self.n = a.length
        self.mat = [[0 for x in range(self.n)] for y in range(self.n)]
        if self.n == 1:
            self.mat[0][0] = a[0][0] * b[0][0]
        else:
            a11 = [[0 for x in range(self.n / 2)] for y in range(self.n / 2)]
            a12 = [[0 for x in range(self.n / 2)] for y in range(self.n / 2)]
            a21 = [[0 for x in range(self.n / 2)] for y in range(self.n / 2)]
            a22 = [[0 for x in range(self.n / 2)] for y in range(self.n / 2)]
            b11 = [[0 for x in range(self.n / 2)] for y in range(self.n / 2)]
            b12 = [[0 for x in range(self.n / 2)] for y in range(self.n / 2)]
            b21 = [[0 for x in range(self.n / 2)] for y in range(self.n / 2)]
            b22 = [[0 for x in range(self.n / 2)] for y in range(self.n / 2)]
            self.split(a, a11, 0, 0)
            self.split(a, a12, 0, self.n / 2)
            self.split(a, a21, self.n / 2, 0)
            self.split(a, a22, self.n / 2, self.n / 2)
            self.split(b, b11, 0, 0)
            self.split(b, b12, 0, self.n / 2)
            self.split(b, b21, self.n / 2, 0)
            self.split(b, b22, self.n / 2, self.n / 2)
            m1 = self.multiply(self.add(a11, a22), self.add(b11, b22))
            m2 = self.multiply(self.add(a21, a22), b11)
            m3 = self.multiply(a11, self.sub(b12, b22))
            m4 = self.multiply(a22, self.sub(b21, b11))
            m5 = self.multiply(self.add(a11, a12), b22)
            m6 = self.multiply(self.sub(a21, a11), self.add(b11, b12))
            m7 = self.multiply(self.sub(a12, a22), self.add(b21, b22))
            c11 = self.add(self.sub(self.add(m1, m4), m5), m7)
            c12 = self.add(m3, m5)
            c21 = self.add(m2, m4)
            c22 = self.add(self.sub(self.add(m1, m3), m2), m6)
            self.join(c11, self.mat, 0, 0)
            self.join(c12, self.mat, 0, self.n / 2)
            self.join(c21, self.mat, self.n / 2, 0)
            self.join(c22, self.mat, self.n / 2, self.n / 2)
        return self.mat

    def sub(self, a, b):
        c = [[0 for x in range(self.n)] for y in range(self.n)]
        for i in range(0, self.n):
            for j in range(0, self.n):
                c[i][j] = a[i][j] - b[i][j]
        return c

    def add(self, a, b):
        c = [[0 for x in range(self.n)] for y in range(self.n)]
        for i in range(0, self.n):
            for j in range(0, self.n):
                c[i][j] = a[i][j] + b[i][j]
        return c

if __name__ == "__main__":
    main = Main()
    n = int(sys.stdin.readline())
    a = [[0 for x in range(n)] for y in range(n)]
    b = [[0 for x in range(n)] for y in range(n)]
    for i in range(0, n):
        for j in range(0, n):
            a[i][j] = int(sys.stdin.readline())
    for i in range(0, n):
        for j in range(0, n):
            b[i][j] = int(sys.stdin.readline())
    result = main.multiply(a, b)
    print("Resultant Matrix:")
    for i in range(0, n):
        for j in range(0, n):
            print(result[i][j], end=" ")
        print()

