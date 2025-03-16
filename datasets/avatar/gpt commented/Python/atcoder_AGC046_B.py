# Read input values A, B, C, D and convert them to integers
A, B, C, D = map(int, input().split())

# Define a large prime number for modulo operations
m = 998244353

# Initialize a 2D list (matrix) d with dimensions (C+1) x (D+1) filled with zeros
d = [[0] * (D + 1) for _ in range(C + 1)]

# Set the starting point in the matrix d at position (A, B) to 1
d[A][B] = 1

# Iterate over the range from A to C (inclusive) for the first dimension
for i in range(A, C + 1):
    # Iterate over the range from B to D (inclusive) for the second dimension
    for j in range(B, D + 1):
        # Update the current cell d[i][j] using the values from the previous cells
        d[i][j] += (d[i][j - 1] * i + d[i - 1][j] * j - d[i - 1][j - 1] * (i - 1) * (j - 1)) % m

# Output the final result from the bottom-right corner of the matrix d
print(d[C][D])
