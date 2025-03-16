import sys  # Importing sys for efficient output writing

def main():
    input = sys.stdin.read  # Reading all input at once
    data = input().split()  # Splitting the input into a list of strings

    H = int(data[0])  # Reading the height of the matrix
    W = int(data[1])  # Reading the width of the matrix
    A = int(data[2])  # Reading the value of A
    B = int(data[3])  # Reading the value of B

    # Checking if the matrix dimensions are suitable for the given values of A and B
    if W < 2 * A or H < 2 * B:
        print(-1)  # Printing -1 if the matrix dimensions are not suitable
        return  # Exiting the program

    # Nested loops to generate the matrix
    for i in range(H):
        for j in range(W):
            # Assigning 0 or 1 based on the conditions specified
            if (i < B and j < A) or (i >= B and j >= A):
                sys.stdout.write("0")  # Writing 0 to the output
            else:
                sys.stdout.write("1")  # Writing 1 to the output
        sys.stdout.write("\n")  # Moving to the next line after each row is written

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
