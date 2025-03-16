
# <START-OF-CODE>

# Create a Scanner object to read input from the user
s = Scanner(sys.stdin)

# Read the number of elements in the array
n = s.nextInt()

# Initialize an array of size n to hold the integers
a = [0] * n

# Populate the array with user input
for i in range(n):
    a[i] = s.nextInt()

# Create a list to store the result pairs
r = []

# Variable to track the index of the element with the maximum absolute value
m = 0

# Find the index of the element with the maximum absolute value
for i in range(1, n):
    if abs(a[m]) < abs(a[i]):
        m = i

# Generate pairs of indices based on the sign of the maximum absolute value element
for i in range(n):
    if a[m] >= 0 ^ a[i] >= 0:
        r.append(str(m + 1) + " " + str(i + 1))

# If the maximum absolute value element is non-negative
if a[m] >= 0:
    # Add pairs of consecutive indices in ascending order
    for i in range(1, n):
        r.append(str(i) + " " + str(i + 1))
else:
    # If the maximum absolute value element is negative, add pairs in descending order
    for i in range(n, 1, -1):
        r.append(str(i) + " " + str(i - 1))

# Print the size of the result list
print(len(r))

# Print each pair in the result list
for i in r:
    print(i)

# 