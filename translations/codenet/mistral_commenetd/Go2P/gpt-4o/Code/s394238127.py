# Import necessary modules
import sys

def main():
    # Initialize a 3x3 matrix 'c' to store input matrix elements
    c = [[0] * 3 for _ in range(3)]

    # Initialize two 1D lists 'a' and 'b' to store differences between corresponding elements of rows and columns
    a = [0] * 3
    b = [0] * 3

    # Read input matrix elements from stdin and store them in 'c' array
    for i in range(3):
        for j in range(3):
            # Read each element from stdin and convert it to integer
            c[i][j] = int(sys.stdin.readline().strip())
            # Print the current loop iteration for debugging
            print(f"Reading element {i},{j} from input matrix")

    # Calculate differences between corresponding elements of rows and columns and store them in 'a' and 'b' lists
    b[0] = c[0][0] - a[0]
    b[1] = c[0][1] - a[0]
    b[2] = c[0][2] - a[0]
    a[1] = c[1][0] - c[0][0]
    a[2] = c[2][0] - c[0][0]

    # Check if 'a' and 'b' lists are equal to the differences between corresponding elements of the first row and the first column of the matrix
    if (a[1] == c[1][1] - c[0][1] and a[1] == c[1][2] - c[0][2] and
        a[2] == c[2][1] - c[0][1] and a[2] == c[2][2] - c[0][2]):
        # Print "Yes" if the condition is true, indicating that the matrix is a diagonal matrix
        print("Yes")
    else:
        # Print "No" if the condition is false, indicating that the matrix is not a diagonal matrix
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
