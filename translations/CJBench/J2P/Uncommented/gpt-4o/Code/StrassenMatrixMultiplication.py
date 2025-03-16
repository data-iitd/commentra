class Strassen:
    def multiply(self, a, b):
        n = len(a)
        mat = [[0] * n for _ in range(n)]
        if n == 1:
            mat[0][0] = a[0][0] * b[0][0]
        else:
            a11, a12, a21, a22 = self.split(a)
            b11, b12, b21, b22 = self.split(b)

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

            self.join(c11, mat, 0, 0)
            self.join(c12, mat, 0, n // 2)
            self.join(c21, mat, n // 2, 0)
            self.join(c22, mat, n // 2, n // 2)

        return mat

    def sub(self, a, b):
        n = len(a)
        c = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] - b[i][j]
        return c

    def add(self, a, b):
        n = len(a)
        c = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] + b[i][j]
        return c

    def split(self, p):
        n = len(p)
        mid = n // 2
        a11 = [row[:mid] for row in p[:mid]]
        a12 = [row[mid:] for row in p[:mid]]
        a21 = [row[:mid] for row in p[mid:]]
        a22 = [row[mid:] for row in p[mid:]]
        return a11, a12, a21, a22

    def join(self, c, p, iB, jB):
        for i1 in range(len(c)):
            for j1 in range(len(c)):
                p[iB + i1][jB + j1] = c[i1][j1]

if __name__ == "__main__":
    n = int(input("Enter the size of the matrices: "))
    a = [list(map(int, input().split())) for _ in range(n)]
    b = [list(map(int, input().split())) for _ in range(n)]
    
    strassen = Strassen()
    result = strassen.multiply(a, b)
    
    print("Resultant Matrix:")
    for row in result:
        print(" ".join(map(str, row)))

# <END-OF-CODE>
