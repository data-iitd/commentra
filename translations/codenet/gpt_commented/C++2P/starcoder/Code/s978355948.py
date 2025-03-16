# Declare variables for the number of elements (N) and the threshold value (X)
N, X = map(int, input().split())

# Initialize a vector L of size N to store the elements
L = [0] * N

# Read N elements into the vector L
for i in range(N):
    L[i] = int(input())

# Initialize index variable and a variable to accumulate the sum
i = 0
d = 0

# Iterate through the elements of the vector L
for i in range(N):
    # Accumulate the sum of elements
    d = d + L[i]

    # Check if the accumulated sum exceeds the threshold X
    if d > X:
        break # Exit the loop if the sum exceeds X

# Output the number of elements processed before exceeding X
print(i + 1) # i + 1 because we want to count the number of elements

