# Read the number of elements
N = int(input())

# Initialize two lists to store the input values
X = []
Y = []

# Read input values into list X and copy them to list Y
for _ in range(N):
    value = int(input())
    X.append(value)
    Y.append(value)

# Sort list Y to find the median
Y.sort()

# Find the median value (middle element for odd N, or lower middle for even N)
y = Y[N // 2]

# Output the appropriate median value for each element in X
for i in range(N):
    # If the current element in X is less than the median
    if X[i] < Y[N // 2]:
        print(Y[N // 2])  # Output the upper median
    else:
        print(Y[N // 2 - 1])  # Output the lower median

# End of the program
# <END-OF-CODE>
