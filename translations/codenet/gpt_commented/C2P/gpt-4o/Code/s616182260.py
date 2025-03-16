# Declare arrays to hold input values and intermediate calculations
a = [0] * 3
b = [0] * 3
c = [[0] * 3 for _ in range(3)]  # 2D list to store the input matrix

# Read a 3x3 matrix from user input
for i in range(3):
    c[i] = list(map(int, input().split()))

# Initialize the first element of array 'a' to 0
a[0] = 0

# Copy the first row of the matrix 'c' into array 'b'
for i in range(3):
    b[i] = c[0][i]

# Calculate the remaining elements of array 'a' based on the first column of matrix 'c'
for i in range(1, 3):
    a[i] = c[i][0] - b[0]

# Verify if the matrix 'c' can be represented as the sum of arrays 'a' and 'b'
for i in range(3):
    for j in range(3):
        # Check if the current element of 'c' equals the sum of corresponding elements from 'a' and 'b'
        if c[i][j] != a[i] + b[j]:
            print("No")  # Output "No" if the condition fails
            exit(0)      # Exit the program

# If all checks pass, output "Yes"
print("Yes")
# Exit the program successfully
# <END-OF-CODE>
