# Read the number of rows (n) from user input
n = int(input())

# Read n rows of integers into a 2D list (matrix) m
m = [[int(x) for x in input().split()] for i in range(n)]

# Sort the matrix m in descending order based on the first element of each row
m.sort(reverse=True)

# Initialize a variable a with the first row of the sorted matrix
a = m[0]

# Iterate through the remaining rows of the sorted matrix
for i in m[1:]:
    # Check if the second element of the current row is greater than the second element of the previous row
    if i[1] > a[1]:
        # If true, print 'Happy Alex' and exit the loop
        print('Happy Alex')
        break
    # Update a to the current row for the next iteration
    a = i
else:
    # If the loop completes without finding a greater second element, print 'Poor Alex'
    print('Poor Alex')
