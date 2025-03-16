# Import the necessary module
import sys

def main():
    # Declare variables to store the dimensions of matrix A and vector B
    m, n = map(int, sys.stdin.readline().split())
    
    # Declare a 2D list to store matrix A
    A = []
    
    # Read the elements of matrix A row by row
    for i in range(m):
        row = list(map(int, sys.stdin.readline().split()))
        A.append(row)

    # Declare a list to store vector B
    B = list(map(int, sys.stdin.readline().split()))

    # Declare a list to store the result of matrix multiplication
    S = [0] * m

    # Perform matrix multiplication of A and B and store the result in list S
    for i in range(m):
        for j in range(n):
            S[i] += A[i][j] * B[j]

    # Print the elements of list S
    for i in range(m):
        print(S[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
