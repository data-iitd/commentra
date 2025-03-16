# Read two integers n and m from input, representing the number of rows and columns
n, m = map(int, input().split())

# Initialize an empty list to store the resulting grid
l = []

# Iterate over each row index i from 0 to n-1
for i in range(n):
    # Read a string input for the current row
    s = input()
    # Convert the string into a list of characters for mutability
    s = list(s)
    
    # Iterate over each column index j from 0 to m-1
    for j in range(m):
        # Check if the current cell is empty (represented by '.')
        if s[j] == '.':
            # Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
            if (i + j) & 1:
                s[j] = 'W'  # Assign 'W' for odd sums
            else:
                s[j] = 'B'  # Assign 'B' for even sums
    
    # Append the modified row (as a list) to the grid
    l.append(s)

# Print each row of the grid as a string
for c in l:
    print("".join(c))
