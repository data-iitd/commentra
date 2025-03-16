
# Initialize a scanner to read input from standard input
scanner = input().split()

# Read the number of elements in the array from the input
N = int(scanner[0])

# Allocate memory for two arrays X and Y of size N
X = [0] * N
Y = [0] * N

# Read N integers from the input and store them in X and Y arrays
for i in range(N):
    X[i] = int(scanner[i + 1])
    Y[i] = X[i]

# Sort the Y array in ascending order
Y.sort()

# Find the median of Y array
m1 = Y[N//2 - 1]
m2 = Y[N//2]

# Iterate through each element of X array and print the corresponding median value
for i in range(N):
    if X[i] <= m1:
        # If X[i] is smaller than m1, print m2 as the answer
        print(m2)
    else:
        # If X[i] is greater than m1, print m1 as the answer
        print(m1)

# END-OF-CODE
