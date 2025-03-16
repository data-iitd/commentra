
# Initialize a list 'c' to store input matrix elements
c = []

# Initialize two lists 'a' and 'b' to store differences between corresponding elements of rows and columns
a = []
b = []

# Read input matrix elements from stdin and store them in 'c' list
for i in range(3):
    for j in range(3):
        # Read each element from stdin and convert it to integer using int()
        c.append(int(input()))

        # Add a comment explaining the current loop iteration
        # This comment will be helpful for understanding the code flow
        print("Reading element %d,%d from input matrix" % (i, j))

# Calculate differences between corresponding elements of rows and columns and store them in 'a' and 'b' lists
b.append(c[0][0] - a[0])
b.append(c[0][1] - a[0])
b.append(c[0][2] - a[0])
a.append(c[1][0] - c[0][0])
a.append(c[2][0] - c[0][0])

# Check if 'a' and 'b' lists are equal to the differences between corresponding elements of the first row and the first column of the matrix
if a[1] == c[1][1]-c[0][1] and a[1] == c[1][2]-c[0][2] and a[2] == c[2][1]-c[0][1] and a[2] == c[2][2]-c[0][2]:
    # Print "Yes" if the condition is true, indicating that the matrix is a diagonal matrix
    print("Yes")
else:
    # Print "No" if the condition is false, indicating that the matrix is not a diagonal matrix
    print("No")

