# Importing the sys and stdin modules for reading input from the standard input
import sys

# Assigning the function readline to the variable input for reading lines from standard input
input = sys.stdin.readline

# Initializing the arrays m and f with zeros for all indices up to N
N = 368
m = [0] * N
f = [0] * N

# Reading the number of operations from the standard input and processing each operation
for i in range(int(input())):
    # Reading an operation line and splitting it into components
    x, a, b = input().split()[:-1]
    # Converting the components a and b to integers
    a = int(a)
    b = int(b) + 1
    # If the operation is 'M', updating the m array accordingly
    if x == 'M':
        m[a] += 2
        m[b] -= 2
    # If the operation is 'F', updating the f array accordingly
    else:
        f[a] += 2
        f[b] -= 2

# Initializing three variables a, b, and c with zeros
a, b, c = 0, 0, 0

# Calculating the prefix sums of m and f arrays
for i in range(N):
    # Updating the variables a and b with the sum of m and f arrays respectively
    a += m[i]
    b += f[i]
    # Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
    if min(a, b) > c:
        c = min(a, b)

# Printing the result, which is the minimum of the prefix sums of m and f arrays
print(c)
