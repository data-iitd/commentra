# Read the number of elements
N = int(raw_input())

# Initialize two vectors to store the input values
X = []
Y = []

# Read input values into vector X and copy them to vector Y
for i in range(N):
    X.append(int(raw_input()))
    Y.append(X[i])

# Sort vector Y to find the median
Y.sort()

# Find the median value (middle element for odd N, or lower middle for even N)
y = Y[N/2]

# Output the appropriate median value for each element in X
for i in range(N):
    # If the current element in X is less than the median
    if X[i] < Y[N/2]:
        print Y[N/2] # Output the upper median
    else:
        print Y[N/2 - 1] # Output the lower median
    print "" # Print a newline after each output

# 