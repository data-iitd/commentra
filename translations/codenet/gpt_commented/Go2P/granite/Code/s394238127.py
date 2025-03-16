
import sys

# Read input from standard input (stdin)
input = sys.stdin.read()

# Split the input into a list of integers
c = list(map(int, input.split()))

# Reshape the list into a 3x3 matrix
c = [c[i:i+3] for i in range(0, 9, 3)]

# Calculate the first differences based on the first row of 'c'
b = [c[0][0] - 0, c[0][1] - 0, c[0][2] - 0]

# Calculate the differences for the second and third rows based on the first row
a = [c[1][0] - c[0][0], c[2][0] - c[0][0]]

# Check if the calculated differences are consistent across the matrix
if a[0] == c[1][1] - c[0][1] and a[0] == c[1][2] - c[0][2] and a[1] == c[2][1] - c[0][1] and a[1] == c[2][2] - c[0][2]:
    # If the conditions are met, print "Yes"
    print("Yes")
else:
    # If the conditions are not met, print "No"
    print("No")

