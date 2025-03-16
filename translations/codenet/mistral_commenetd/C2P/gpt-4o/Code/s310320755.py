# Declare variables
r, c, n, flag, cnt = 0, 0, 0, 0, 0
arr = [[0] * 17 for _ in range(17)]  # Create a 17x17 matrix initialized to 0

while True:
    n = int(input("Enter the size of the square matrix: "))

    # Break the loop if user inputs 0
    if n == 0:
        break

    flag = 1  # Initialize flag to 1
    r = (n + 1) // 2 + 1  # Calculate row index
    c = (n + 1) // 2      # Calculate column index

    # Set the first element of the matrix
    arr[r][c] = cnt = 1

    # Fill the rest of the matrix
    while cnt != n * n:
        cnt += 1

        # If flag is 1, move to the next cell in the right direction
        if flag:
            r += 1
            c += 1

            # If we reach the end of the row, move to the first cell of the next row
            if c > n:
                c = 1

            # If we reach the end of the matrix, move to the first cell of the first row
            if r > n:
                r = 1

            # If the cell is already filled, move to the opposite cell
            if arr[r][c]:
                flag = 0
                cnt -= 1
            # Otherwise, fill the cell with the current number
            else:
                arr[r][c] = cnt
        # If flag is 0, move to the previous cell in the left direction
        else:
            r += 1
            c -= 1

            # If we reach the beginning of the row, move to the last cell of the previous row
            if c < 1:
                c = n

            # If we reach the beginning of the matrix, move to the last cell of the last row
            if r > n:
                r = 1

            # If the cell is already filled, move to the opposite cell
            if arr[r][c]:
                flag = 0
            # Otherwise, fill the cell with the current number and set flag to 1
            else:
                arr[r][c] = cnt
                flag = 1

    # Print the filled matrix
    for r in range(1, n + 1):
        for c in range(1, n + 1):
            print(f"{arr[r][c]:4d}", end="")
            arr[r][c] = 0  # Reset the matrix for the next input
            if c == n:
                print()

# End of the program
# <END-OF-CODE>
