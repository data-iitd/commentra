
# Read the 3x3 matrix from the input
c = [[0 for _ in range(3)] for _ in range(3)]
for i in range(3):
    c[i] = list(map(int, input().split()))

# Initialize the first element of array a to 0
a = [0] * 3

# Assign the first row of the matrix to array b
b = [c[0][i] for i in range(3)]

# Calculate the remaining elements of array a
for i in range(1, 3):
    a[i] = c[i][0] - b[0]

# Check if each element of the matrix is equal to the sum of the corresponding elements of a and b
for i in range(3):
    for j in range(3):
        if c[i][j]!= a[i] + b[j]:
            print("No")
            exit()

# If all elements match, print "Yes"
print("Yes")

