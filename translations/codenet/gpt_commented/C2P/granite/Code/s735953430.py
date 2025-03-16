
import sys

# Read the values of X and N from user input
X, N = map(int, input().split())

# If N is 0, print X and exit the program
if N == 0:
    print(X)
    sys.exit(0)

# Initialize arrays to hold positive and negative values
plus = [i for i in range(256)]
minus = [-1 * i for i in range(256)]

# Read N values and set corresponding indices in the plus array to 0
for i in range(N):
    j = int(input())
    plus[j] = 0 # Mark the value as unavailable

# Initialize minimum index and minimum difference
i_min = 0
min = 1000

# Iterate through the plus array in reverse order to find the closest value to X
for i in range(255, -1, -1):
    # Skip indices that are marked as unavailable (0) and are greater than 0
    if plus[i] == 0 and i > 0:
        continue

    # Calculate the difference between X and the current value in the plus array
    k = abs(X - plus[i])

    # Update minimum difference and index if a closer value is found
    if k <= min:
        min = k
        i_min = i # Store the index of the closest value

# Print the index of the closest value found
print(i_min)

