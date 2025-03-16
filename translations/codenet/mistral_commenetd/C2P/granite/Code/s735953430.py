
import sys

# Read input values X and N from the user
X, N = map(int, input().split())

# Check if N is zero, if yes, print X and exit the program
if N == 0:
    print(X)
    sys.exit(0)

# Initialize two arrays plus and minus of size 256
plus = [i for i in range(256)]
minus = [-1*i for i in range(256)]

# Subtract the given numbers from the plus array
for i in range(N):
    j = int(input())
    plus[j] = 0

# Initialize variables i_min and min with initial values
i_min = 0
min = 1000

# Find the minimum number in the plus array that is not zero and can form the difference X
for i in range(255, -1, -1):
    # Skip the iteration if the current number in the plus array is zero and it is not the first element
    if plus[i] == 0 and i > 0:
        continue
    # Calculate the difference between X and the current number in the plus array
    k = X - plus[i]
    # If the difference is negative, make it positive
    if k < 0:
        k *= -1
    # Update min and i_min if the current difference is smaller than the previous minimum
    if k <= min:
        min = k
        i_min = i

# Print the index of the minimum number
print(i_min)

