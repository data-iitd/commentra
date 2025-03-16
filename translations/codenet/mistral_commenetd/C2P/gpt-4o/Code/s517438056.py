import math

# Declare variables
N = 0
D = 0
k = 0

# Read the number of rows and columns from the user
N, D = map(int, input("Enter the number of rows and columns: ").split())

# Allocate memory for the 2D matrix
matrix = []

# Read the elements of the matrix from the user
print("Enter the elements of the matrix:")
for i in range(N):
    row = list(map(int, input(f"Row {i + 1}: ").split()))
    matrix.append(row)

# Calculate the number of identical rows
k = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        m = 0  # Initialize the variable m to 0
        for n in range(D):
            # Calculate the difference between the corresponding elements of two rows and square it
            m += (matrix[i][n] - matrix[j][n]) ** 2
        # Calculate the square root of the sum of squared differences
        l = math.sqrt(m)
        # If the square root is an integer, increment the counter k
        if l.is_integer():
            k += 1

# Print the result
print(k)

# No need to free memory in Python as it is handled by the garbage collector
# <END-OF-CODE>
