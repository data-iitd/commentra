def rotate(matrix, r):
    # Initialize the starting indices for the current layer
    left = 0
    up = 0
    # Get the number of rows and columns in the matrix
    m = len(matrix)
    n = len(matrix[0])
    # Continue rotating layers until the matrix is fully rotated
    while m >= 1 and n >= 1:
        # Calculate the number of elements in the current layer
        count = 2 * (m + n) - 4
        # Create a temporary array to store the elements of the current layer
        tmp = [0] * count
        # Initialize the current index in the temporary array
        curr = 0
        # Store the elements of the top row in the temporary array
        for i in range(n):
            tmp[curr] = matrix[up][left + i]
            curr += 1
        # Store the elements of the right column in the temporary array
        for i in range(1, m - 1):
            tmp[curr] = matrix[up + i][left + n - 1]
            curr += 1
        # Store the elements of the bottom row in the temporary array
        for i in range(n - 1, -1, -1):
            tmp[curr] = matrix[up + m - 1][left + i]
            curr += 1
        # Store the elements of the left column in the temporary array
        for i in range(m - 2, 0, -1):
            tmp[curr] = matrix[up + i][left]
            curr += 1
        # Calculate the effective number of rotations for the current layer
        curr = r % count
        if curr < 0:
            curr += count
        # Rotate the elements in the current layer by shifting them to the right
        for i in range(n):
            matrix[up][left + i] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        for i in range(1, m - 1):
            matrix[up + i][left + n - 1] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        for i in range(n - 1, -1, -1):
            matrix[up + m - 1][left + i] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        for i in range(m - 2, 0, -1):
            matrix[up + i][left] = tmp[curr]
            curr += 1
            if curr >= count:
                curr -= count
        # Update the indices to move to the next inner layer
        m -= 2
        n -= 2
        left += 1
        up += 1


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    # Read the number of rows and columns in the matrix
    rows = int(data[0])
    cols = int(data[1])
    # Create the matrix and read its elements
    matrix = []
    index = 2
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(int(data[index]))
            index += 1
        matrix.append(row)
    # Read the number of rotations
    rotations = int(data[index])
    # Rotate the matrix and print the result
    rotate(matrix, rotations)
    for i in range(rows):
        for j in range(cols):
            print(matrix[i][j], end=' ')
        print()


main()
