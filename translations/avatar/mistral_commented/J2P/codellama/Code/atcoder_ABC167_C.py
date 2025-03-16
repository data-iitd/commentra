
import sys

# Initialize scanner to read input from the console
sc = sys.stdin

# Read the number of rows and columns from the input
n, m = map(int, sc.readline().split())

# Read the 2D array 'a' from the input
a = []
for i in range(n):
    a.append(list(map(int, sc.readline().split())))

# Initialize variables for binary search tree traversal
min = sys.maxsize
x = int(sc.readline())

# Perform binary tree traversal
for i in range(2 ** n):
    status = [0] * n

    # Set the status of each node based on the current binary tree node
    for j in range(n):
        if (1 & i >> j) == 1:
            status[j] = 1

    # Initialize result array for the current binary tree node
    res = [0] * (m + 1)

    # Calculate the sum of elements in the current row for each column
    for j in range(n):
        if status[j] == 1:
            for k in range(m + 1):
                res[k] += a[j][k]

    # Check if the sum of elements in the current row for each column is greater than or equal to 'x'
    flag = True
    for j in range(1, m + 1):
        if res[j] < x:
            flag = False
            break

    # If the sum of elements in all columns for the current binary tree node is greater than or equal to 'x', update the minimum value
    if flag:
        min = min(min, res[0])

# Print the minimum value if it exists, otherwise print '-1'
if min == sys.maxsize:
    print(-1)
else:
    print(min)

# END-OF-CODE
