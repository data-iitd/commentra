
# Import the necessary libraries
import sys

# Create a list to store the input values
c = []

# Read 3x3 integers from input and populate the list 'c'
for i in range(3):
    for j in range(3):
        c.append(int(sys.stdin.readline().strip()))

# Initialize arrays to hold differences for calculations
a = [0, 0, 0]
b = [0, 0, 0]

# Calculate the first differences based on the first row of 'c'
b[0] = c[0] - a[0]
b[1] = c[1] - a[0]
b[2] = c[2] - a[0]

# Calculate the differences for the second and third rows based on the first row
a[1] = c[3] - c[0]
a[2] = c[6] - c[0]

# Check if the calculated differences are consistent across the matrix
if a[1] == c[4]-c[3] and a[1] == c[5]-c[3] and a[2] == c[7]-c[3] and a[2] == c[8]-c[3]:
    # If the conditions are met, print "Yes"
    print("Yes")
else:
    # If the conditions are not met, print "No"
    print("No")

