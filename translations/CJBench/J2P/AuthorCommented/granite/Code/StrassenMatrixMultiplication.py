

import numpy as np

# Python Program to Implement Strassen Algorithm for Matrix Multiplication

# This Matrix multiplication can be performed only on square matrices
# where n is a power of 2. Order of both of the matrices are n × n.

# Reference:
# https://www.tutorialspoint.com/design_and_analysis_of_algorithms/design_and_analysis_of_algorithms_strassens_matrix_multiplication.htm#:~:text=Strassen's%20Matrix%20multiplication%20can%20be,matrices%20are%20n%20%C3%97%20n.
# https://www.geeksforgeeks.org/strassens-matrix-multiplication/

def multiply(a, b):
    n = a.shape[0]

    if n == 1:
        return np.array([[a[0][0] * b[0][0]]])
    else:
        # Dividing Matrix into parts
        # by storing sub-parts to variables
        a11 = a[:n//2, :n//2]
        a12 = a[:n//2, n//2:]
        a21 = a[n//2:, :n//2]
        a22 = a[n//2:, n//2:]

        b11 = b[:n//2, :n//2]
        b12 = b[:n//2, n//2:]
        b21 = b[n//2:, :n//2]
        b22 = b[n//2:, n//2:]

        # Using Formulas as described in algorithm
        # m1:=(A1+A3)×(B1+B2)
        m1 = multiply(a11 + a22, b11 + b22)
        # m2:=(A2+A4)×(B3+B4)
        m2 = multiply(a21 + a22, b11 + b22)
        # m3:=(A1−A4)×(B1+A4)
        m3 = multiply(a11 + a12, b22 - b12)
        # m4:=A1×(B2−B4)
        m4 = multiply(a22 - a12, b11 + b12)
        # m5:=(A3+A4)×(B1)
        m5 = multiply(a11 + a12, b11 + b21)
        # m6:=(A1+A2)×(B4)
        m6 = multiply(a11 - a21, b11 + b22)
        # m7:=A4×(B3−B1)
        m7 = multiply(a12 - a22, b21 + b22)

        # P:=m2+m3−m6−m7
        c11 = m2 + m3 - m6 - m7
        # Q:=m4+m6
        c12 = m4 + m6
        # mat:=m5+m7
        c21 = m5 + m7
        # S:=m1−m3−m4−m5
        c22 = m1 - m3 - m4 - m5

        return np.vstack((np.hstack((c11, c12)), np.hstack((c21, c22))))

def main():
    n = int(input("Enter the size of the matrices (must be a power of 2): "))

    a = np.array([[int(x) for x in input("Enter matrix A: ").split()] for _ in range(n)])
    b = np.array([[int(x) for x in input("Enter matrix B: ").split()] for _ in range(n)])

    result = multiply(a, b)

    print("Resultant Matrix:")
    for row in result:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    main()

