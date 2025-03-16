
# Declare the required arrays and their sizes
a = [0,0,0]
b = [0,0,0]
c = [[0,0,0],[0,0,0],[0,0,0]]

# Initialize the matrix 'c' with user input
for i in range(3):
    print("Enter the elements of row %d: " % (i+1))
    c[i][0], c[i][1], c[i][2] = map(int, input().split())

# Initialize array 'a' with the first row of matrix 'c'
a[0] = 0
for i in range(3):
    b[i] = c[0][i]

# Initialize array 'a' with the difference between the corresponding elements of matrix 'c' and array 'b'
for i in range(1,3):
    a[i] = c[i][0] - b[0]

# Compare each element of matrix 'c' with the corresponding elements of array 'a' and 'b'
for i in range(3):
    for j in range(3):
        if c[i][j]!= a[i] + b[j]:
            print("No")
            exit(0)

# If all the elements in matrix 'c' match the condition, print "Yes"
print("Yes")

