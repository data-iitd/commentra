
# Python code to generate a magic square

def generate_magic_square(n):
    # Initialize a 16x16 array to store the magic square, filled with zeros
    arr = [[0 for _ in range(n)] for _ in range(n)]

    # Initialize flag and starting position for the first number
    flag = True
    r = (n + 1) // 2
    c = (n + 1) // 2
    arr[r][c] = cnt = 1

    # Loop to fill the magic square until all numbers are placed
    while cnt!= n*n + 1:
        cnt += 1  # Increment the counter for the next number

        # If flag is set, move diagonally up-right
        if flag:
            r += 1  # Move down one row
            c += 1  # Move right one column

            # Wrap around if going out of bounds
            if c >= n:
                c = 0  # Wrap to the first column

            if r >= n:
                r = 0  # Wrap to the first row

            # Check if the current position is already filled
            if arr[r][c]:
                flag = False  # Change direction if the position is occupied
                cnt -= 1  # Decrement the counter to retry placing the number
            else:
                arr[r][c] = cnt  # Place the number in the array
        else:  # If flag is not set, move down-left
            r += 1  # Move down one row
            c -= 1  # Move left one column

            # Wrap around if going out of bounds
            if c < 0:
                c = n - 1  # Wrap to the last column

            if r >= n:
                r = 0  # Wrap to the first row

            # Check if the current position is already filled
            if arr[r][c]:
                flag = False  # Change direction if the position is occupied
            else:
                arr[r][c] = cnt  # Place the number in the array
                flag = True  # Reset flag to move diagonally up-right next

    return arr

# Test the function with a 4x4 magic square
print(generate_magic_square(4))

# End of code