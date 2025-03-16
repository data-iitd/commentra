# Declare the required arrays and their sizes
def main():
    a = [0] * 3  # Initialize array 'a' with size 3
    b = [0] * 3  # Initialize array 'b' with size 3
    c = [[0] * 3 for _ in range(3)]  # Initialize a 3x3 matrix 'c'

    # Initialize the matrix 'c' with user input
    for i in range(3):
        c[i] = list(map(int, input(f"Enter the elements of row {i + 1}: ").split()))
        # Scan the three elements of each row and store them in the matrix 'c'

    # Store the elements of the first row of matrix 'c' in array 'b'
    for i in range(3):
        b[i] = c[0][i]

    # Initialize array 'a' with the difference between the corresponding elements of matrix 'c' and array 'b'
    for i in range(1, 3):
        a[i] = c[i][0] - b[0]  # Subtract the first element of each row of matrix 'c' from the corresponding element of array 'b'

    # Compare each element of matrix 'c' with the corresponding elements of array 'a' and 'b'
    for i in range(3):
        for j in range(3):
            if c[i][j] != a[i] + b[j]:  # Check if the element at position (i,j) in matrix 'c' is equal to the sum of the elements at position i in array 'a' and j in array 'b'
                print("No")  # If not, print "No" and exit the program
                return

    # If all the elements in matrix 'c' match the condition, print "Yes"
    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
