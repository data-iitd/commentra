# Include necessary libraries
import sys

# Declare and initialize variables
n = 0
h = []
max_height = -1
flag = 0

# Read the number of test cases
n = int(input())

# Read and process input
for i in range(n):
    # Read the next integer from standard input and store it in the list h
    height = int(input())
    h.append(height)

    # Update the maximum height if the current height is greater
    if max_height < height:
        max_height = height

    # Check if the difference between the current height and maximum height is greater than or equal to 2
    if max_height - height >= 2:
        flag = 1

# Check the value of the flag and print the appropriate message to the standard output
if flag == 1:
    print("No")
else:
    print("Yes")

# <END-OF-CODE>
