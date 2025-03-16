def print_island(n, count):
    a = (n + 1) // 2  # Calculating the number of 'L' characters in the first diagonal
    b = n // 2        # Calculating the number of 'L' characters in the second diagonal
    max_count = a * a + b * b  # Calculating the maximum possible number of 'L' characters

    # Checking if the requested count exceeds the maximum possible 'L' characters
    if count > max_count:
        print("NO")  # Printing "NO" if count is too high
        return  # Returning from the function as further execution is unnecessary

    print("YES")  # Printing "YES" as the count is within the allowed range

    # Building the island grid
    for i in range(n):
        row = []  # Creating a list to build the row
        for j in range(n):
            if (i + j) % 2 == 0 and count > 0:  # Checking if the position should be 'L'
                row.append('L')  # Appending 'L' to the row
                count -= 1  # Decrementing the count of 'L' characters
            else:
                row.append('S')  # Appending 'S' to the row
        print(''.join(row))  # Printing the constructed row

# Main function to read input and call the print_island function
if __name__ == "__main__":
    n = int(input())  # Reading the first integer input (size of the grid)
    count = int(input())  # Reading the second integer input (number of 'L' characters)
    print_island(n, count)  # Calling the print_island function with the inputs

# <END-OF-CODE>
