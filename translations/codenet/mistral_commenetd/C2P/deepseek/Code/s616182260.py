# Declare the required arrays and their sizes
a = [0] * 3
b = [0] * 3
c = [[0] * 3 for _ in range(3)]

# Initialize the matrix 'c' with user input
for i in range(3):
    print(f"Enter the elements of row {i+1}: ", end="")
    c[i] = list(map(int, input().split()))

# Initialize array 'a' with the first row of matrix 'c'
a = [c[0][i] for i in range(3)]

# Initialize array 'b' with the elements of the first row of matrix 'c'
b = c[0]

# Initialize array 'a' with the difference between the corresponding elements of matrix 'c' and array 'b'
for i in range(1, 3):
    a[i] = c[i][0] - b[0]

# Compare each element of matrix 'c' with the corresponding elements of array 'a' and 'b'
for i in range(3):
    for j in range(3):
        if c[i][j] != a[i] + b[j]:
            print("No")
            exit()

# If all the elements in matrix 'c' match the condition, print "Yes"
print("Yes")
