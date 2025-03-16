import sys

def main():
    # Reading input from stdin
    H, W, A, B = map(int, sys.stdin.readline().split())

    # Checking if the matrix dimensions are suitable for the given values of A and B
    if W < 2 * A or H < 2 * B:
        print(-1)  # Printing -1 if the matrix dimensions are not suitable
        return

    # Nested loops to generate the matrix
    for i in range(H):
        for j in range(W):
            # Assigning 0 or 1 based on the conditions specified
            if (i < B and j < A) or (i >= B and j >= A):
                sys.stdout.write("0")  # Writing 0 to stdout
            else:
                sys.stdout.write("1")  # Writing 1 to stdout
        print()  # Moving to the next line after each row is written

if __name__ == "__main__":
    main()
