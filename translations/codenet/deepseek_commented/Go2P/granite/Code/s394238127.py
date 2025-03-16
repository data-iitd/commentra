
import sys

# Read input from standard input
input = sys.stdin.read()

# Split the input into lines
lines = input.split('\n')

# Initialize a 3x3 integer array and a 3-element integer array
c = [[0 for _ in range(3)] for _ in range(3)]
a = [0 for _ in range(3)]
b = [0 for _ in range(3)]

# Read values into the 3x3 array `c`
for i in range(3):
    for j in range(3):
        c[i][j] = int(lines[i].split()[j])

# Calculate the values of `b` based on the initial assumption that `a[0]` is zero
b[0] = c[0][0] - a[0]
b[1] = c[0][1] - a[0]
b[2] = c[0][2] - a[0]

# Calculate the values of `a` based on the values in `c`
a[1] = c[1][0] - c[0][0]
a[2] = c[2][0] - c[0][0]

# Check if the calculated values of `a` and `c` are consistent with the given relationships
if a[1] == c[1][1] - c[0][1] and a[1] == c[1][2] - c[0][2] and \
   a[2] == c[2][1] - c[0][1] and a[2] == c[2][2] - c[0][2]:
    print("Yes")
else:
    print("No")
