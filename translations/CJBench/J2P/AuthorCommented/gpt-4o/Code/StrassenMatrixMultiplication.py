import numpy as np

# Python Program to Implement Strassen Algorithm for Matrix Multiplication

class Strassen:
    # Function to multiply matrices
    def multiply(self, a, b):
        n = len(a)
        mat = np.zeros((n, n), dtype=int)

        if n == 1:
            mat[0][0] = a[0][0] * b[0][0]
        else:
            # Dividing Matrix into parts
            a11 = np.zeros((n // 2, n // 2), dtype=int)
            a12 = np.zeros((n // 2, n // 2), dtype=int)
            a21 = np.zeros((n // 2, n // 2), dtype=int)
            a22 = np.zeros((n // 2, n // 2), dtype=int)
            b11 = np.zeros((n // 2, n // 2), dtype=int)
            b12 = np.zeros((n // 2, n // 2), dtype=int)
            b21 = np.zeros((n // 2, n // 2), dtype=int)
            b22 = np.zeros((n // 2, n // 2), dtype=int)

            # Dividing matrix A into 4 parts
            self.split(a, a11, 0, 0)
            self.split(a, a12, 0, n // 2)
            self.split(a, a21, n // 2, 0)
            self.split(a, a22, n // 2, n // 2)

            # Dividing matrix B into 4 parts
            self.split(b, b11, 0, 0)
            self.split(b, b12, 0, n // 2)
            self.split(b, b21, n // 2, 0)
            self.split(b, b22, n // 2, n // 2)

            # Using Formulas as described in algorithm
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

    # Function to subtract two matrices
    def sub(self, a, b):
        n = len(a)
        c = np.zeros((n, n), dtype=int)

        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] - b[i][j]

        return c

    # Function to add two matrices
    def add(self, a, b):
        n = len(a)
        c = np.zeros((n, n), dtype=int)

        for i in range(n):
            for j in range(n):
                c[i][j] = a[i][j] + b[i][j]

        return c

    # Function to split parent matrix into child matrices
    def split(self, p, c, iB, jB):
        for i1 in range(c.shape[0]):
            for j1 in range(c.shape[1]):
                c[i1][j1] = p[iB + i1][jB + j1]

    # Function to join child matrices into (to) parent matrix
    def join(self, c, p, iB, jB):
        for i1 in range(c.shape[0]):
            for j1 in range(c.shape[1]):
                p[iB + i1][jB + j1] = c[i1][j1]

if __name__ == "__main__":
    n = int(input("Enter the size of the matrices (must be a power of 2): "))

    a = np.zeros((n, n), dtype=int)
    b = np.zeros((n, n), dtype=int)

    print("Enter matrix A:")
    for i in range(n):
        a[i] = list(map(int, input().split()))

    print("Enter matrix B:")
    for i in range(n):
        b[i] = list(map(int, input().split()))

    strassen = Strassen()
    result = strassen.multiply(a, b)

    print("Resultant Matrix:")
    for row in result:
        print(" ".join(map(str, row)))

# <END-OF-CODE>
