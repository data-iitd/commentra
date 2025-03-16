def print_island(n, count):
    a = (n + 1) // 2  # Calculate the side length 'a' of the square grid of size 'n x n'
    b = n // 2        # Calculate the square of the side length 'b' of the grid
    max_count = a * a + b * b  # Calculate the maximum number of 'L' islands that can be placed in the grid

    # Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
    if count > max_count:
        print("NO")  # If yes, print "NO" and return from the method
        return

    print("YES")  # If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

    # Initialize a list to store the rows of the grid
    for i in range(n):
        row = []
        for j in range(n):
            # If the cell is in the position where an 'L' island can be placed, append an 'L' character to the row and decrement the count
            if (i + j) % 2 == 0 and count > 0:
                row.append('L')
                count -= 1
            else:
                # Otherwise, append an 'S' character to the row
                row.append('S')
        # Print the contents of the row to represent a row of the grid
        print(''.join(row))

# Entry point of the program
if __name__ == "__main__":
    n = int(input())  # Read the first integer 'n' from the input
    count = int(input())  # Read the second integer 'count' from the input
    print_island(n, count)  # Call the print_island function with the arguments 'n' and 'count'

# <END-OF-CODE>
