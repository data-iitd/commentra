

def rotate(matrix, r):
    m = len(matrix) # Number of rows in the matrix
    n = len(matrix[0]) # Number of columns in the matrix
    left = 0 # Initialize left index
    up = 0 # Initialize top index

    # Rotate the matrix as long as both dimensions are greater than zero
    while m >= 1 and n >= 1:
        count = 2 * (m + n) - 4 # Calculate the total number of elements to be shifted
        tmp = [0] * count # Create a temporary array to store the elements
        curr = 0 # Initialize index to store the temporary array

        # Copy the first row to the temporary array
        for i in range(n):
            tmp[curr] = matrix[up][left + i]
            curr += 1

        # Copy the last column to the temporary array
        for i in range(1, m - 1):
            tmp[curr] = matrix[up + i][left + n - 1]
            curr += 1

        # Copy the last row to the temporary array, except the last element
        for i in range(n - 1, -1, -1):
            tmp[curr] = matrix[up + m - 1][left + i]
            curr += 1

        # Copy the first column to the temporary array, except the first element
        for i in range(m - 2, 1, -1):
            tmp[curr] = matrix[up + i][left]
            curr += 1

        # Update the matrix using the temporary array
        curr = r % count # Calculate the index to start updating the matrix
        if curr < 0:
            curr += count # Handle negative index
        for i in range(n):
            matrix[up][left + i] = tmp[curr] # Update the first row
            curr += 1
            if curr >= count:
                curr -= count # Handle index out of bounds
        for i in range(1, m - 1):
            matrix[up + i][left + n - 1] = tmp[curr] # Update the last column
            curr += 1
            if curr >= count:
                curr -= count # Handle index out of bounds
        for i in range(n - 1, -1, -1):
            matrix[up + m - 1][left + i] = tmp[curr] # Update the last row
            curr += 1
            if curr >= count:
                curr -= count # Handle index out of bounds
        for i in range(m - 2, 1, -1):
            matrix[up + i][left] = tmp[curr] # Update the first column
            curr += 1
            if curr >= count:
                curr -= count # Handle index out of bounds

        # Decrease the size of the matrix and move to the next position
        m -= 2
        n -= 2
        left += 1
        up += 1

# Main method to read input and call the rotate method
if __name__ == "__main__":
    rows = int(input()) # Read the number of rows
    cols = int(input()) # Read the number of columns
    matrix = [] # Create a 2D list to store the matrix elements

    # Read the matrix elements
    for i in range(rows):
        row = list(map(int, input().split())) # Read the row elements
        matrix.append(row)

    rotations = int(input()) # Read the number of rotations
    rotate(matrix, rotations) # Call the rotate method to rotate the matrix

    # Print the rotated matrix
    for row in matrix:
        print(*row) # Print the row elements with a space between them

