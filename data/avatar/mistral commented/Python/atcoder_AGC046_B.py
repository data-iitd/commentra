#######
# Code
#######

# Define input variables A, B, C, D as integers
# obtained from user input, separated by spaces
A, B, C, D = map(int, input().split())

# Initialize a 2D array 'd' with dimensions (C+1) x (D+1)
# filled with zeros
d = [[0] * (D + 1) for _ in range(C + 1)]

# Set the value of d[A][B] to 1
d[A][B] = 1

# Matrix multiplication using dynamic programming approach
# Iterate through the rows from A to C
for i in range(A, C + 1):
    # Iterate through the columns from B to D
    for j in range(B, D + 1):
        # Calculate the value of d[i][j] using the previous values
        d[i][j] += (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m

# Print the final value of d[C][D]
print(d[C][D])
