
# Method to rotate the matrix in layers
def rotate(matrix, r):
    # Initialize boundaries for the current layer
    left = 0
    up = 0
    m = len(matrix) # Number of rows
    n = len(matrix[0]) # Number of columns

    # Continue processing while there are layers left to rotate
    while m >= 1 and n >= 1:
        # Calculate the number of elements in the current layer
        count = 2 * (m + n) - 4
        tmp = [0] * count # Temporary array to hold the layer elements
        curr = 0

        # Extract the top row of the current layer
        for i in range(n):
            tmp[curr] = matrix[up][left + i]
            curr += 1
        # Extract the right column of the current layer
        for i in range(1, m - 1):
            tmp[curr] = matrix[up + i][left + n - 1]
            curr += 1
        # Extract the bottom row of the current layer
        for i in range(n - 1, -1, -1):
            tmp[curr] = matrix[up + m - 1][left + i]
            curr += 1
        # Extract the left column of the current layer
        for i in range(m - 2, 0, -1):
            tmp[curr] = matrix[up + i][left]
            curr += 1

        # Calculate the effective number of rotations needed
        curr = r % count
        if curr < 0:
            curr += count # Adjust for negative rotations

        # Place the rotated elements back into the top row
        for i in range(n):
            matrix[up][left + i] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count # Wrap around if needed
        # Place the rotated elements back into the right column
        for i in range(1, m - 1):
            matrix[up + i][left + n - 1] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count # Wrap around if needed
        # Place the rotated elements back into the bottom row
        for i in range(n - 1, -1, -1):
            matrix[up + m - 1][left + i] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count # Wrap around if needed
        # Place the rotated elements back into the left column
        for i in range(m - 2, 0, -1):
            matrix[up + i][left] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count # Wrap around if needed

        # Move to the next inner layer
        m -= 2 # Decrease the number of rows for the next layer
        n -= 2 # Decrease the number of columns for the next layer
        left += 1 # Move the left boundary inward
        up += 1 # Move the upper boundary inward

# Read the dimensions of the matrix
rows = int(input())
cols = int(input())
matrix = []

# Read the matrix elements from input
for i in range(rows):
    matrix.append([int(x) for x in input().split()])

# Read the number of rotations to perform
rotations = int(input())

# Call the rotate method to perform the rotations
rotate(matrix, rotations)

# Print the rotated matrix
for i in range(rows):
    for j in range(cols):
        print(matrix[i][j], end=" ")
    print() # New line after each row

# END-OF-CODE
