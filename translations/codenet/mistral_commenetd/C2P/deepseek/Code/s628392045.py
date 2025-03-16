# Include necessary header files
import sys

# Declare and initialize variables
n = int(input().strip())
h = list(map(int, sys.stdin.readline().strip().split()))
max_height = -1
flag = 0

# Read and process input
for i in range(n):
    # Update the maximum height if the current height is greater
    if max_height < h[i]:
        max_height = h[i]

    # Check if the difference between the current height and maximum height is greater than or equal to 2
    if max_height - h[i] >= 2:
        flag = 1
        break

# Check the value of the flag and print the appropriate message to the standard output
if flag == 1:
    print("No")
else:
    print("Yes")

# Return 0 to indicate successful execution
